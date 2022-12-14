//
//  stack.hpp
//  stack implementation using Linked list
//
//  Created by Jedidiah Uchenna on 05.12.2022.
//

#ifndef STACKLL_HPP
#define STACKLL_HPP

namespace LL
{
    template <typename T>
    struct Node
    {
        T value;
        Node * next;
    };

    template <class T>
    class Stack
    {
    public:
        Stack();
        ~Stack();
        void push(const T& );
        T pop();
        T peek(const int& ) const;
        T& operator[](const int& );
        T sTop();
        int getSize() const;
        bool isFull();
        bool isEmpty();

    private:
        Node<T>* topNode;
    };
}
#endif /* STACKLL_HPP */
