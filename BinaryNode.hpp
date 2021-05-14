#ifndef BINARY_NODE
#define BINARY_NODE
#include "DoubleNode.hpp"

template <class T>
class BinaryNode: public DoubleNode<T> {
    public:
        void setLeft(BinaryNode *left) {
            this->_prev = (DoubleNode<T> *)left;
        }

        BinaryNode *getLeft() {
            return (BinaryNode *)this->_prev;
        }

        void setRight(BinaryNode *right) {
            this->_next = (DoubleNode<T> *)right;
        }

        BinaryNode *getRight() {
            return (BinaryNode *)this->_next;
        }
};

#endif
