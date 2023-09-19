#include "DoubleLinkedList.h"


int main() {
    DoubleLinkedList list;

    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    std::cout << "Original list: ";
    list.print("forward");

    std::cout << "Backward list: ";
    list.print("backward");

    std::cout << "Original list: ";
    list.print("forward");

    list.replaceByAverage();
    std::cout << "List after replaceByAverage: ";
    list.print();

    return 0;
}