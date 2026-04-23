#include<iostream>
#include"node.h"
using namespace std;

template <typename T>
class LinkList {
    Node<T> *START, *END;

public:
    LinkList() {
        START = nullptr;
        END = nullptr;
    }

    void insertFront(T data) {
        Node<T> *temp = new Node(data);
        if (temp == nullptr){
            cout << "Insufficient Memory\n\n";
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
        Node<T> *temp = new Node(data);
        if (temp == nullptr){
            cout << "Insufficient Memory\n\n";
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
        if (pos == 0){
            insertFront(data);
            return;
        }
        else if (pos < 0) {
            insertBack(data);
            return;
        } 

        Node<T> *temp = new Node(data);
        Node<T> *ptr = START;
        if (temp == nullptr) {
            cout << "Insufficient Memory\n\n";
            return;
        }

        if (ptr == nullptr) {
            END = START = temp;
            return;
        }

        int i = 0;
        while (ptr != nullptr){
            if (i == pos-1){
                temp->next = ptr->next;
                ptr->next = temp;
                return;
            }
            ptr = ptr->next;
            i++;
        }

        END->next = temp;
        END = temp;
    }

    void removeFront() {
        Node<T> *temp = START;

        if (temp == nullptr){
            cout<<"Link List is empty";
            return;
        }

        START = START->next;
        delete(temp);
    }

    void removeBack() {
        Node<T> *ptr = START;
        if (ptr == nullptr) {
            cout<<"Link List is empty";
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
        delete(ptr);
        END->next = nullptr;
    }

    void show() {
        Node<T> *ptr = START;
        if (ptr == nullptr){
            cout<<"List is empty\n\n";
            return;
        }
        else {
            while (ptr != nullptr){
                cout<<ptr->data<<" -> ";
                ptr = ptr->next;
            }
            cout << "Null";
        }
    }
};
