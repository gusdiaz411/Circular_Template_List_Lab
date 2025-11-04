#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include <iostream>

template <typename T> // T is expected to be a pointer type, e.g., Media*
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current; // For circular playNext

public:
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    ~LinkedList() {
        if (!head) return;
        Node<T>* temp = head;
        do {
            Node<T>* nextNode = temp->next;
            delete temp->data; // Delete the Media* object
            delete temp;       // Delete the node
            temp = nextNode;
        } while (temp != head);
        head = tail = current = nullptr;
        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    void insert(T value) { // value is already a pointer
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
            tail->next = head; // circular link
            current = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // circular link
        }
    }

    void displayList() const {
        if (!head) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist ---" << std::endl;
        Node<T>* temp = head;
        int index = 1;
        do {
            std::cout << index++ << ". " << temp->data->toString() << std::endl;
            temp = temp->next;
        } while (temp != head);
        std::cout << "------------------------" << std::endl;
    }

    void playNext() {
        if (!current) {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
            return;
        }
        current->data->play();
        current = current->next; // advance circularly
    }
};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H
