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

        T pop() {
            T value = peek();
            _stackList.remove(0);
            return value;
        }

        T peek() {
            return _stackList.get(0);
        }

        void print() {
            _stackList.print();
        }
};

#endif
