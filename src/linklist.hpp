#include<stdexcept>
#include<iostream>
#include"node.hpp"

template <typename T>
class LinkList {
    Node<T> *START, *END;
    size_t nodeCount;

public:
    LinkList() {
        START = nullptr;
        END = nullptr;
        nodeCount = 0;
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
        nodeCount++;
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
        nodeCount++;
    }   

    void insertAtIndex(T data, size_t index) {
        if (index <= 0){
            insertFront(data);
            return;
        }

        Node<T> *ptr = START;
        int i = 0;
        while (ptr != nullptr && i < index-1){
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
        nodeCount++;
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
        nodeCount--;
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
            nodeCount--;
            return;
        }

        while (ptr->next != END){
            ptr = ptr->next;
        }
        END = ptr;
        ptr = ptr->next;
        END->next = nullptr;
        delete ptr;
        nodeCount--;
    }

    void removeFromPos(size_t index) {
        if (index <= 0) {
            removeFront();
            return;
        }

        Node<T> *ptr = START;
        int i = 0;
        while (ptr != nullptr && i < index-1){
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
        nodeCount--;
    }

    size_t size(){
        return nodeCount;
    }

    T get(size_t index) {
        if (index > nodeCount) 
            return END->data;

        if (index <= 0) 
            return START->data;

        Node<T> *ptr = START;
        int i = 0;

        while (ptr != nullptr && i < index) {
            ptr = ptr->next;
            i++;
        }
        return ptr->data;
    }
};
