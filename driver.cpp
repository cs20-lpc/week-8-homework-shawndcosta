// main.cpp
#include "LinkedListStack.hpp"
#include <iostream>

int main() {
    LinkedListStack<int> stack;
    std::cout << "push:\n";
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print(); 

    std::cout << "peek: " << stack.peek() << "\n"; 
    std::cout << "pop \n";
    stack.pop();
    stack.print();


    std::cout << "rotate right:\n";
    stack.rotate(Stack<int>::RIGHT);
    stack.print(); 

    std::cout << "Rotate left:\n";
    stack.rotate(Stack<int>::LEFT);
    stack.print(); 

    std::cout << "copy :\n";
    LinkedListStack<int> copyStack(stack);
    copyStack.print(); 

    std::cout << "assignment:\n";
    LinkedListStack<int> assignedStack;
    assignedStack.push(100);
    assignedStack.push(200);
    assignedStack = stack;
    assignedStack.print(); 


    std::cout << "clear:\n";
    stack.clear();
    stack.print(); 

    return 0;
}
