#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;      
    Node* next;  

    // Constructor
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;  

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void addSorted(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head || value.bid_amount > head->data.bid_amount) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next && current->next->data.bid_amount > value.bid_amount) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << endl;  
            current = current->next;
        }
    }

    Node<T>* getFront() const {
        return head;
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
