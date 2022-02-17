// Copyright 2021 Petrova Kseniya <ksyushki5@yandex.ru>

#ifndef INCLUDE_STACK_2_HPP_
#define INCLUDE_STACK_2_HPP_
#pragma once
#include <utility>
//некопируемый перемещаемый шаблон класса Stack для
//некопируемых перемещаемых типов

//реализация с помощью односвязного списка

//создаём узел
template <typename T>
struct Node_2
{
  T val; //значение
  Node_2<T> *prev; //указатель на предыдущий элемент
};

template <typename T>
class My_Stack_2
{
 private:
  Node_2<T> *peak_elem = nullptr;
 public:
  My_Stack_2()= default;//конструктор по умолчанию
  My_Stack_2(const My_Stack_2 &stack) = delete; //запрет неявного копирования
  My_Stack_2(My_Stack_2&& stack) noexcept = default; //конструктор перемещения
  auto operator=(My_Stack_2&& stack)  noexcept -> class My_Stack_2& = default;
  auto operator=(My_Stack_2& stack) = delete; //запрет копирования
  template <typename ... Args>
  void push_emplace(Args&& ... value);
  void push(T&& value);
  const T& head() const;
  T pop();
};

template<typename T>
template<typename ...Args>
void My_Stack_2<T>::push_emplace(Args && ... value)
{
  auto* current = peak_elem;
  peak_elem = new Node_2<T>{{std::forward<Args>(value)...}, current};
}

template<typename T>
void My_Stack_2<T>::push(T && val)
{
  auto* cur = peak_elem;
  peak_elem = new Node_2<T>{std::forward<T>(val), cur};
}

template<typename  T>
const T & My_Stack_2<T>::head() const
{
  return peak_elem->val;
}

template<typename T>
T My_Stack_2<T>::pop()
{
  if (peak_elem) {
    auto* cur = peak_elem;
    T val = std::move(peak_elem->val);
    peak_elem = peak_elem->prev;
    delete cur;
    return val;
  }else{
    throw std::runtime_error("Stack is empty! Can not pop any element!");
  }
}

#endif  // INCLUDE_STACK_2_HPP_
