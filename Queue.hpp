#ifndef QUEUE
#define QUEUE
#include "DoublyLinkedList.hpp"

template <class T>
class Queue {
    private:
        DoublyLinkedList<T> _queueList;
    public:
        void enqueue(T value) {
            _queueList.prepend(value);
        }

        T dequeue() {
            T value = _queueList.getLast();
            _queueList.removeLast();

            return value;
        }

        T front() {
            return _queueList.getLast();
        }

        void print() {
            _queueList.print();
        }
};

#endif
