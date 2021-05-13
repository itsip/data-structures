#ifndef DOUBLE_NODE
#define DOUBLE_NODE
#include "Node.hpp"

template <class T>
class DoubleNode: public Node<T> {
    private:
        DoubleNode *_prev;

    public:
        DoubleNode(T data) : _prev(nullptr) {}

        void setPrev(DoubleNode *prev) {
            _prev = prev;
        }

        DoubleNode *getPrev() {
            return _prev;
        }

        T getData() {
            return this->_data;
        }
};

#endif
