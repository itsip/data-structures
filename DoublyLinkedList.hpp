#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include "DoubleNode.hpp"
#include <iostream>

template <class T>
class DoublyLinkedList {
    private:
        DoubleNode<T> *_head;
        DoubleNode<T> *_last;

    public:
        DoublyLinkedList() : _head(nullptr), _last(nullptr) {}

        ~DoublyLinkedList() {
            if (_head && _last) {
                DoubleNode<T> *curr = _head;

                while (curr->getNext()) {
                    curr = curr->getNext();
                }

                delete curr;
            }
        }

        T get(int index) {
            DoubleNode<T> *curr = _head;

            for (int i = 0; i != index; i++) {
                curr = curr->getNext();
            }

            return curr->getData();
        }

        void prepend(T value) {
            if (!_head) {
                _head = new DoubleNode<T>(value);
                _last = _head;
            } else {
                DoubleNode<T> *newNode = new DoubleNode<T>(value);
                newNode->setNext(_head);
                _head->setPrev(newNode);
                _head = newNode;
            }
        }

        void insertAfter(T value, int index) {
            DoubleNode<T> *curr = _head;

            for (int i = 0; i != index; i++)
                curr = curr->getNext();

            DoubleNode<T> *newNode = new DoubleNode<T>(value);
            newNode->setPrev(curr);

            if (DoubleNode<T>* post = curr->getNext()) {
                newNode->setNext(post);
                post->setPrev(newNode);
            } else {
                _last = newNode;
            }

            curr->setNext(newNode);
        }

        void append(T value) {
            if (!_head) {
                _head = new DoubleNode<T>(value);
                _last = _head;
            } else {
                DoubleNode<T> *curr = _head;

                while (curr->getNext()) {
                    curr = curr->getNext();
                }

                DoubleNode<T> *newNode = new DoubleNode<T>(value);
                newNode->setPrev(curr);
                curr->setNext(newNode);
                _last = newNode;
            }
        }

        void remove(int index) {
            DoubleNode<T> *prev = nullptr;
            DoubleNode<T> *curr = _head;
            DoubleNode<T> *post = nullptr;

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
                _last = prev;
            }

            delete curr;
        }

        T getLast() {
            return _last->getData();
        }

        void removeLast() {
            DoubleNode<T> *prev = _last->getPrev();
            DoubleNode<T> *tempLast = _last;

            prev->setNext(nullptr);
            _last = prev;

            delete tempLast;
        }

        void print() {
            DoubleNode<T> *curr = _head;

            std::cout << curr->getData() << std::endl;

            while (curr->getNext()) {
                curr = curr->getNext();
                std::cout << curr->getData() << std::endl;
            }
        }
};

#endif
