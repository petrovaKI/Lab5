// Copyright 2021 Petrova Kseniya <ksyushki5@yandex.ru>

#include "Stack_1.hpp"
#include <iostream>

int main() {
  int x1 = 10;
  int x2 = 5;
  My_Stack<int> stack;

  std::cout << "PUSH ELEMENTS TO STACK:" << std::endl;
  stack.push(x1);
  stack.push(x2);
  stack.push(15);
  stack.print();
  std::cout << std::endl;

  std::cout << "POP ELEMENTS FROM STACK:" << std::endl;
  stack.pop();
  stack.print();
  std::cout << std::endl;

  std::cout << "POP ALL ELEMENTS FROM STACK:" << std::endl;
  stack.pop();
  stack.pop();
  stack.print();
  std::cout << std::endl;

  std::cout << "POP MORE ELEMENTS THEN THERE ARE IN STACK:" << std::endl;
  //st.pop();
  std::cout << std::endl;

  std::cout << "GET TOP OF THE STACK:" << std::endl;
  stack.push(x1); //10
  stack.push(x2); //5
  stack.push(30);
  //стек сейчас: 30 5 15
  std::cout << stack.head() << std::endl;
  std::cout << std::endl;

  std::cout << "GET TOP OF THE STACK AFTER POP:" << std::endl;
  stack.pop();
  //стек сейчас:  5 15
  std::cout << stack.head();
  std::cout << std::endl;
}
