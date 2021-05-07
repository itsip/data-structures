#include <stdio.h>
#include <iostream>

template <class T>
class Node {
    private:
        T _data;
        Node *_next;
    public:
        Node(T data) : _next(NULL) {
            _data = data;
        }

        void setNext(Node *next) {
            _next = next;
        }

        Node *getNext() {
            return _next;
        }

        T getData() {
            return _data;
        }
};

template <class T>
class LinkedList {
    private:
        Node<T> *_head;

    public:
        LinkedList<T>() : _head(NULL) {}

        ~LinkedList<T>() {
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
            Node<T> *newNode = new Node<T>(value);
            newNode->setNext(_head);
            _head = newNode;
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

        void print() {
            Node<T> *head = _head;

            std::cout << _head->getData() << std::endl;

            while (head->getNext()) {
                head = head->getNext();
                std::cout << head->getData() << std::endl;
            }
        }
};

int main() {
    LinkedList<int> linkedList;
    linkedList.append(3);
    linkedList.append(6);
    linkedList.prepend(7);
    linkedList.insertAfter(5, 1);
    linkedList.print();
}
