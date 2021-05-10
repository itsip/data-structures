#ifndef STACK
#define STACK
#include "LinkedList.hpp"

template <class T>
class Stack {
    private:
        LinkedList<T> _stackList;

    public:
        void push(T value) {
            _stackList.prepend(value);
        }

        void pop() {
            _stackList.remove(0);
        }

        T peek() {
            _stackList.get(0);
        }

        void print() {
            _stackList.print();
        }
};

#endif
