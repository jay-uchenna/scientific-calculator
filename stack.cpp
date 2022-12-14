//
//  stack.cpp
//  stack implementation using Linked list
//
//
//  Created by Jedidiah Uchenna on 05.12.2022.
//

#include "stack.hpp"
#include <iostream>

//default constructor: assign NULL to topNode to show the stack is empty
template <class T> LL::Stack<T>::Stack():topNode(NULL){}
template <class T> LL::Stack<T>::~Stack()
{
    Node <T>* tempNode = topNode;
    while(tempNode)
    {
        topNode = topNode->next;
        delete tempNode;
        tempNode = topNode;
    }
}
//add value to stack from top
template <class T> void LL::Stack<T>::push(const T& val)
{
    Node <T>* tempNode = new (std::nothrow) Node<T>;
    if(tempNode)
    {
        tempNode->value = val;
        tempNode->next = NULL;
        if(topNode) tempNode->next = topNode;
        topNode = tempNode;
    }
    else throw std::runtime_error("stack is full\n");
}
//last out: return last value added to stack and remove it from stack
template <class T> T LL::Stack<T>::pop()
{
    if(topNode == NULL) throw std::runtime_error("stack is empty\n");
    T tempValue;
    tempValue = topNode->value;
    Node<T> * tempNode = topNode->next;
    delete topNode;
    topNode = tempNode;
    return tempValue;
}
template <class T> T LL::Stack<T>::peek(const int& pos) const
{
    if(pos < 1) throw std::runtime_error("error: input should be greater than 0\n");
    if(topNode == NULL) throw std::runtime_error("error: stack is empty\n");
    Node <T>* tempNode = topNode;
    for(int i = 1; tempNode != NULL && i < pos; i++) tempNode = tempNode->next;
    if(tempNode == NULL) throw std::runtime_error("error: input exceeds stack size\n");
    return tempNode->value;
}
template <class T> T&  LL::Stack<T>::operator[](const int& pos)
{
    if(topNode == NULL) throw std::runtime_error("stack is empty\n");
    Node <T>* tempNode = topNode;
    for(int i = 1; tempNode != NULL && i < pos; i++) tempNode = tempNode->next;
    if(tempNode == NULL) throw std::runtime_error("input exceeds stack\n");
    return tempNode->value;
}
template <class T> T LL::Stack<T>::sTop()
{
    if(topNode == 0) throw std::runtime_error("stack is empty\n");
    return topNode->value;
}
template <class T> int LL::Stack<T>::getSize() const
{
    int size = 0;
    Node<T> * tempNode = topNode;
    while(tempNode !=NULL)
    {
        size++;
        tempNode = tempNode->next;
    }
    return size;
}

template <class T> bool LL::Stack<T>::isFull()
{
    Node <T>* tempNode = new (std::nothrow) Node<T>;
    if(tempNode)
    {
        delete tempNode;
        return false;
    }
    return true;
}
template <class T> bool LL::Stack<T>::isEmpty()
{
    if(topNode) return false;
    return true;
}
// explicit instantiation for template class
template class LL::Stack<double>;
template class LL::Stack<char>;

