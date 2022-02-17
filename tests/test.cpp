// Copyright 2021 Petrova Kseniya <ksyushki5@yandex.ru>

#include <stdexcept>
#include "Stack_1.hpp"
#include "Stack_2.hpp"
#include <gtest/gtest.h>
#include <string>
class Key_Val
{
 public:
  int key;
  double val_;
  Key_Val() = default;
  Key_Val(int key1, double val_1)
  { this->key = key1;
    this->val_ = val_1;
  }
  Key_Val(const Key_Val& obj) = delete;
  Key_Val(Key_Val&& obj) noexcept = default;
  auto operator=(const Key_Val& obj) -> Key_Val& = delete;
  auto operator=(Key_Val&& value) noexcept -> Key_Val& = default;
};
TEST(My_Stack_1, PUSH_POP_HEAD)
{
  My_Stack<int> st;
  int a = 10;

  st.push(30);
  st.push(a);
  st.push(90);
  EXPECT_EQ(st.head(), 90);

  st.pop();
  EXPECT_EQ(st.head(), a);

  st.pop();
  st.pop();
  EXPECT_THROW(st.pop(), std::exception);

}
 TEST (My_Stack_1, IS_MOVE_ASSIGN_CONSTR)
{
   //Проверка на то что тип  может быть создан
   //с помощью операции перемещения
   EXPECT_EQ(std::is_move_constructible<My_Stack<int>>::value, true);
   //Перемещаемые при присваивании типы включают ссылочные скалярные
   //типы и типы классов, в которых есть созданные компилятором
   //или определяемые пользователем операторы присваивания.
   EXPECT_EQ(std::is_move_assignable<My_Stack<int>>::value, true);
 }
 TEST (My_Stack_1, IS_NOT_COPY_ASSIGN_CONSTR)
 {
   EXPECT_FALSE(std::is_copy_constructible<My_Stack<int>>::value);
   EXPECT_FALSE(std::is_copy_assignable<My_Stack<int>>::value);
 }

TEST (My_Stack_2, PUSH_POP_HEAD)
 {
  My_Stack_2<Key_Val> st;
  st.push_emplace(1, 654.7);
  st.push_emplace(2, 678.8);
  EXPECT_EQ(st.head().key, 2);
  EXPECT_EQ(st.head().val_, 678.8);

  st.pop();
  EXPECT_EQ(st.head().key, 1);
  EXPECT_EQ(st.head().val_, 654.7);

  st.push_emplace(2, 678.8);
  Key_Val st2(3, 543.98);
  st.push(std::move(st2)); //push принимает rvalue ссылку
  EXPECT_EQ(st.head().key, 3);
  EXPECT_EQ(st.head().val_, 543.98);
}
TEST (My_Stack_2, IS_MOVE_ASSIGN_CONSTR)
{
  EXPECT_EQ(std::is_move_constructible<My_Stack_2<Key_Val>>::value, true);
  EXPECT_EQ(std::is_move_assignable<My_Stack_2<Key_Val>>::value, true);
}
TEST (My_Stack_2, IS_NOT_COPY_ASSIGN_CONSTR)
{
  EXPECT_FALSE(std::is_copy_constructible<My_Stack_2<Key_Val>>::value);
  EXPECT_FALSE(std::is_copy_assignable<My_Stack_2<Key_Val>>::value);
}
