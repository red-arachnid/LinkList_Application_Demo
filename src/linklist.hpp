#include<stdexcept>
#include"node.hpp"

template <typename T>
class LinkList {
    Node<T> *START, *END;

public:
    LinkList() {
        START = nullptr;
        END = nullptr;
    }

    void insertFront(T data) {
        Node<T> *temp = new Node<T>(data);
        if (temp == nullptr){
            throw std::runtime_error("Insufficient Memory");
            return;
        }

        if (START == nullptr){
            END = START = temp;
        }
        else {
            temp->next = START;
            START = temp;
        }
    }
    
    void insertBack(T data) {
        Node<T> *temp = new Node<T>(data);
        if (temp == nullptr){
            throw std::runtime_error("Insufficient Memory");
            return;
        }

        if (START == nullptr){
            END = START = temp;
        }
        else {
            END->next = temp;
            END = temp;
        }
    }   

    void insertAtPos(T data, int pos) {
        if (pos <= 0){
            insertFront(data);
            return;
        }

        Node<T> *ptr = START;
        int i = 0;
        while (ptr != nullptr && i < pos-1){
            ptr = ptr->next;
            i++;
        }

        if (ptr == nullptr || ptr == END){
            insertBack(data);
            return;
        }

        Node<T> *temp = new Node<T>(data);
        if (temp == nullptr) {
            throw std::runtime_error("Insufficient Memory");
            return;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }

    void removeFront() {
        Node<T> *temp = START;

        if (temp == nullptr){
            throw std::runtime_error("Link List is empty");
            return;
        }

        START = START->next;
        if (START == nullptr) {
            END = nullptr;
        }
        delete temp;
    }

    void removeBack() {
        Node<T> *ptr = START;
        if (ptr == nullptr) {
            throw std::runtime_error("Link List is empty");
            return;
        }

        if (ptr == END){
            START = END = nullptr;
            delete(ptr);
            return;
        }

        while (ptr->next != END){
            ptr = ptr->next;
        }
        END = ptr;
        ptr = ptr->next;
        END->next = nullptr;
        delete ptr;
    }

    void removeFromPos(int pos) {
        if (pos <= 0) {
            removeFront();
            return;
        }

        Node<T> *ptr = START;
        int i = 0;
        while (ptr != nullptr && i < pos-1){
            ptr = ptr->next;
            i++;
        }

        if (ptr == nullptr || ptr == END || ptr->next == END) {
            removeBack();
            return;
        }

        Node<T> *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
};
