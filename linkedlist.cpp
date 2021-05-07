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
            std::cout << _data << std::endl;
            return _data;
        }
};

template <class T>
class LinkedList {
    private:
        Node<T> *_head;
    public:
        LinkedList<T>() : _head(NULL) {}

        Node<T> get(int index) {
            Node<T> head = _head;
            for (int i = 0; i < index; i++) {
                if (i == index) {
                    return head;
                }

                head = head->getNext();
            }
        }

        void prepend(T value) {
            Node<T> *newNode = Node<T>(value);
            newNode->setNext(_head);
            _head = newNode;
        }

        void insert(T value, int index) {
        }

        void append(T value) {
            if (!_head) {
                Node<T> head = Node<T>(value);
                _head = &head;
                std::cout << _head->getData() << std::endl;
            } else {
                Node<T> *head = _head;

                while (head->getNext()) {
                    head = head->getNext();
                }

                Node<T> newNode = Node<T>(value);
                head->setNext(&newNode);
            }
        }

        void print() {
            //Node<T> *head = _head;

            std::cout << _head->getData() << std::endl;

/*            while (head->getNext()) {*/
                //head = head->getNext();
                //std::cout << head->getData() << std::endl;
            /*}*/
        }
};

int main() {
    LinkedList<int> linkedList;
    linkedList.append(3);
    linkedList.print();
}
