#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <iostream>
#include <string>

class DoubleLinkedList {
public:
    DoubleLinkedList();//�����������
    ~DoubleLinkedList();//����������

    void insert(int data);//���������� �������� � "������"
    void print();//����� ������ � ������ �����������
    void print(std::string value);//����� ������ � ������ ��� � �������� ����������� � ����������� �� ���������
    void replaceByAverage();//�������� ���� ���������, �� ������ �������������� �������

private:
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;//�������� ��������
            prev = nullptr;//���������� �������
            next = nullptr;//��������� �������
        }
    };
    Node* head;//������
    Node* tail;//�����

    // ��������� ����������� � ������������
    DoubleLinkedList(const DoubleLinkedList&) = delete;
    DoubleLinkedList& operator=(const DoubleLinkedList&) = delete;

    // ��������� �����������
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
        while (current != nullptr && current->next != nullptr) { //��������, ���� �� � ���� ��������� ����
            int avg = (current->data + current->next->data) / 2;
            current->data = avg; //���������� �� ����� ����
            Node* temp = current->next;
            current->next = current->next->next;
            if (current->next != nullptr) { //�������� ���� �� ��������� ����
                current->next->prev = current;
            }
            delete temp;
            if (current->next != nullptr) {
                current = current->next;
            }
        }
        if (current != nullptr && current->next == nullptr) { //���� �������� ��-�� �����
            Node* temp = current;
            current = current->prev;
            current->next = nullptr;
            delete temp;
        }
   
}
#endif 