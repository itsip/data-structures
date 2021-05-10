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
            Node<T> *head = _head;

            if (!head->getNext()) {
                delete head;
            } else {
                while (head->getNext()) {
                    Node<T> *last = head;
                    head = head->getNext();
                    delete last;
                }

                delete head;
            }
        }

        T get(int index) {
            Node<T> *head = _head;

            for (int i = 0; i != index; i++) {
                head = head->getNext();
            }

            return head->getData();
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
            Node<T> *head = _head;

            for (int i = 0; i != index; i++) {
                head = head->getNext();
            }

            if (head->getNext()) {
                Node<T> *newNode = new Node<T>(value);
                newNode->setNext(head->getNext());
                head->setNext(newNode);
            } else {
                head->setNext(new Node<T>(value));
            }
        }

        void append(T value) {
            if (!_head) {
                _head = new Node<T>(value);
            } else {
                Node<T> *head = _head;

                while (head->getNext()) {
                    head = head->getNext();
                }

                head->setNext(new Node<T>(value));
            }
        }

        void remove(int index) {
            Node<T> *pre = nullptr;
            Node<T> *head = _head;
            Node<T> *post = nullptr;

            for (int i = 0; i != index; i++) {
                pre = head;
                head = head->getNext();
                post = head->getNext();
            }

            if (post) {
                pre->setNext(post);
            } else if (!pre && !post) {
                _head = head->getNext();
            } else if (pre && !post) {
                pre->setNext(nullptr);
            }

            delete head;
        }

        void print() {
            Node<T> *head = _head;

            std::cout << _head->getData() << std::endl;

            while (head->getNext()) {
                head = head->getNext();
                std::cout << head->getData() << std::endl;
            }
        }
};

#endif
