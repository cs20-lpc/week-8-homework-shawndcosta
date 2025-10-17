#include "LinkedListStack.hpp"
#include <iostream>
#include <vector> 

template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while(top != nullptr){
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        this->length--;
    }
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    clear();

    if (!copyObj.top) {
        top = nullptr;
        this->length = 0;
        return;
    }
    std::vector<T> temp;

    Node<T>* curr = copyObj.top;
    while (curr) {
        temp.push_back(curr->data);
        curr = curr->next;
    }
    for (int i = static_cast<int>(temp.size()) - 1; i >= 0; --i) {
        push(temp[i]);  
    
    }
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    Node<T>* temp = top;  
    top = top->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);  
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (!top || !top->next) return;  

    if (dir == Stack<T>::RIGHT) {
  
        Node<T>* oldTop = top;
        top = top->next;
        oldTop->next = nullptr;

     
        Node<T>* curr = top;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = oldTop;

    } else if (dir == Stack<T>::LEFT) {

        Node<T>* prev = nullptr;
        Node<T>* curr = top;

  
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        curr->next = top;
        top = curr;
    }
}



template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
