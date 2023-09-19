#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <iostream>
#include <string>

class DoubleLinkedList {
public:
    DoubleLinkedList();//Конструктор
    ~DoubleLinkedList();//Деструктор

    void insert(int data);//Добавление элемента в "голову"
    void print();//Вывод списка в прямом направлении
    void print(std::string value);//Вывод списка в прямом или в обратном направлении в зависимости от параметра
    void replaceByAverage();//заменяет пару элементов, на средне арифметический элемент

private:
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;//значение элемента
            prev = nullptr;//предыдущий элемент
            next = nullptr;//Следующий элемент
        }
    };
    Node* head;//Голова
    Node* tail;//Хвост

    // Запрещаем копирование и присваивание
    DoubleLinkedList(const DoubleLinkedList&) = delete;
    DoubleLinkedList& operator=(const DoubleLinkedList&) = delete;

    // Запрещаем перемещение
    DoubleLinkedList(DoubleLinkedList&&) = delete;
    DoubleLinkedList& operator=(DoubleLinkedList&&) = delete;
};




    DoubleLinkedList::DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    inline DoubleLinkedList::~DoubleLinkedList()
    {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void DoubleLinkedList::insert(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void DoubleLinkedList::print()
    {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void DoubleLinkedList::print(std::string value) {
        if (value == "backward") {
            Node* current = tail;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->prev;
            }
            std::cout << std::endl;
        }
        if (value == "forward") {
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    void DoubleLinkedList::replaceByAverage() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) { //Проверка, если ли у узла следующий узел
            int avg = (current->data + current->next->data) / 2;
            current->data = avg; //Заменяется на новый узел
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next != nullptr) { //Проверка если ли следующий узел
                current->next->prev = current;
            }
            delete temp;
            if (current->next != nullptr) {
                current = current->next;
            }
        }
        if (current != nullptr && current->next == nullptr) { //Если нечетное ко-во узлов
            Node* temp = current;
            current = current->prev;
            current->next = nullptr;
            delete temp;
        }
   
}
#endif 