#ifndef LINKED_LIST
#define LINKED_LIST
#include "Node.hpp"
#include <iostream>

template <class T>
class LinkedList {
    private:
        Node<T> *_head;

    public:
        LinkedList() : _head(nullptr) {}

        ~LinkedList() {
            if (_head) {
                Node<T> *curr = _head;

                while (curr->getNext()) {
                    curr = curr->getNext();
                }

                delete curr;
            }
        }

        T get(int index) {
            Node<T> *curr = _head;

            for (int i = 0; i != index; i++) {
                curr = curr->getNext();
            }

            return curr->getData();
        }

        void prepend(T value) {
            if (!_head) {
                _head = new Node<T>(value);
            } else {
                Node<T> *newNode = new Node<T>(value);
                newNode->setNext(_head);
                _head = newNode;
            }
        }

        void insertAfter(T value, int index) {
            Node<T> *curr = _head;

            for (int i = 0; i != index; i++)
                curr = curr->getNext();

            Node<T> *newNode = new Node<T>(value);

            if (curr->getNext())
                newNode->setNext(curr->getNext());

            curr->setNext(newNode);
        }

        void append(T value) {
            if (!_head) {
                _head = new Node<T>(value);
            } else {
                Node<T> *curr = _head;

                while (curr->getNext()) {
                    curr = curr->getNext();
                }

                Node<T> *newNode = new Node<T>(value);
                curr->setNext(newNode);
            }
        }

        void remove(int index) {
            Node<T> *prev = nullptr;
            Node<T> *curr = _head;
            Node<T> *post = nullptr;

            for (int i = 0; i != index; i++) {
                prev = curr;
                curr = curr->getNext();
                post = curr->getNext();
            }

            if (post) {
                prev->setNext(post);
            } else if (!prev && !post) {
                _head = curr->getNext();
            } else if (prev && !post) {
                prev->setNext(nullptr);
            }

            delete curr;
        }

        void print() {
            Node<T> *curr = _head;

            std::cout << _head->getData() << std::endl;

            while (curr->getNext()) {
                curr = curr->getNext();
                std::cout << curr->getData() << std::endl;
            }
        }
};

#endif
