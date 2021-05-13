#ifndef QUEUE
#define QUEUE
#include "LinkedList.hpp"

template <class T>
class Queue {
    private:
        LinkedList<T> _queueList;
    public:
        void enqueue(T value) {
            _queueList.prepend(value);
        }

        T dequeue() {

        }
};

#endif
