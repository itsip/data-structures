#ifndef BINARY_TREE
#define BINARY_TREE
#include "BinaryNode.hpp"

template <class S, class T>
class BinarySearchTree {
    private:
        BinaryNode<S,T> *_root;
    public:
        BinarySearchTree() : _root(nullptr) {}

        void insert(S key, T value) {
            BinaryNode<S,T> *curr = _root;

            while (curr) {
                S currKey = curr->getKey();

                if (currKey == key)
                    curr->setData(value);
                else if (currKey > key)
                    curr = curr->getLeft();
                else
                    curr = curr->getRight();
            }

            curr = new BinaryNode<S,T>(key, value);
        }
};

#endif
