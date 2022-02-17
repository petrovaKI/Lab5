// Copyright 2021 Petrova Kseniya <ksyushki5@yandex.ru>

#ifndef  INCLUDE_STACK_1_HPP_
#define INCLUDE_STACK_1_HPP_
#pragma once
#include <stdexcept>
#include <iostream>
#include <utility>
//реализация с помощью односвязного списка
//создаём узел
template <typename T>
struct Node
{
  T val; //значение
  Node<T> *prev; //указатель на предыдущий элемент
  // (при добавлении элемента в стек указатель смещается "вниз")
};

template <typename T>
class My_Stack
{
 private:
  Node<T> *peak_elem = nullptr; //указатель на вершину стека
 public:
  void print();
  My_Stack() = default; //конструктор по умолчанию
  My_Stack(const My_Stack& stack) = delete; //запрет неявного копирования
  My_Stack(My_Stack&& stack)  noexcept = default; //конструктор перемещения
  auto operator=(My_Stack& stack) = delete; //запрет копирования
  auto operator=(My_Stack&& stack)  noexcept -> My_Stack& = default;
  void push(T&& val); //помещение элемента в стек (rvalue)
  void push(const T& val); //(lvalue)
  void pop(); //извлечение элемента из стека
  const T& head() const; //возвращает указатель на вершину стека
  ~My_Stack();
};
template<typename T>
void My_Stack<T>::print(){
  if (peak_elem == nullptr)
    std::cout << "Stack is empty!" << std::endl;
  else
  {
    Node<T>* p;
    p = peak_elem;
    while (p != nullptr)
    {
      std::cout << p->val << std::endl;
      p = p->prev;
    }
  }
}

template<typename T>
void My_Stack<T>::push(T &&val)
{
  auto* cur = new Node<T>{std::forward<T>(val), peak_elem};
  peak_elem = cur;
}

template<typename T>
void My_Stack<T>::push(const T &val)//lvalue
{
  auto* cur = new Node<T>{val, peak_elem};
  peak_elem = cur;
}
template<typename T>
void My_Stack<T>::pop()
{
  if (peak_elem) //если есть хотя бы один элемент в стеке
  {
    auto* cur = peak_elem;
    peak_elem = peak_elem->prev;  //перемещаем указатель на прерыдущий элемент
    delete cur;
  }else{
    throw std::runtime_error("Stack is empty! Can not pop any element!");
  }
}
template<typename T>
const T &My_Stack<T>::head() const
{
  return peak_elem->val;
}
template<typename T>
My_Stack<T>::~My_Stack()
{
  Node<T>* p;
  Node<T>* p2;

  p = peak_elem;
  while (p != nullptr)
  {
    p2 = p; // сделать копию из p
    p = p->prev; // перейти на следующий элемент стека
    delete p2; // удалить память, выделенную под предыдущий элемент
  }
  peak_elem = nullptr; // поправить вершину стека
}
#endif //  INCLUDE_STACK_1_HPP_
