#include <stdio.h>
#include <iostream>
#include "Array.hpp"
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

int main() {
    printf("Array: \n");

    Array<int> arr = Array<int>(4);
    arr.set(0, 9);
    arr.set(1, 3);
    int x = arr.get(1);
    printf("%d\n\n", x);

    printf("Linked List: \n");
    LinkedList<int> linkedList;
    linkedList.append(3);
    linkedList.append(6);
    linkedList.prepend(7);
    linkedList.insertAfter(5, 1);
    linkedList.print();
    printf("\n");


    printf("Doubly Linked List: \n");
    DoublyLinkedList<int> doublyLinkedList;
    doublyLinkedList.append(3);
    doublyLinkedList.append(6);
    doublyLinkedList.prepend(7);
    doublyLinkedList.insertAfter(5, 1);
    doublyLinkedList.print();

    printf("\n");
    std::cout << doublyLinkedList.getLast() << std::endl;
    printf("\n");

    doublyLinkedList.removeLast();
    doublyLinkedList.print();

    printf("\n");

    printf("Stack: \n");
    Stack<int> myStack;
    myStack.push(9);
    myStack.push(7);
    myStack.push(5);
    myStack.pop();
    myStack.print();

    printf("\n");

    printf("Queue: \n");
    Queue<int> myQueue;
    myQueue.enqueue(9);
    myQueue.enqueue(7);
    myQueue.enqueue(5);
    myQueue.print();

    printf("\n");
    std::cout << myQueue.front() << std::endl;
    myQueue.dequeue();

    printf("\n");

    myQueue.print();
}
