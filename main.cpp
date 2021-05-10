#include <stdio.h>
#include "Array.hpp"
#include "LinkedList.hpp"

int main() {
    Array<int> arr = Array<int>(4);
    arr.set(0, 9);
    arr.set(1, 3);
    int x = arr.get(1);
    printf("%d\n\n", x);

    LinkedList<int> linkedList;
    linkedList.append(3);
    linkedList.append(6);
    linkedList.prepend(7);
    linkedList.insertAfter(5, 1);
    linkedList.print();
}
