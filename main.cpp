#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node *next;

    Node(T val){
        data = val;
        next = nullptr;
    }
};


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


int main() {
    LinkList<int> numberList;
    numberList.insertFront(10);
    numberList.insertFront(20);
    numberList.insertBack(30);
    numberList.insertBack(40);
    numberList.insertAtPos(50, 2);
    numberList.show();
    cout<<"\n\n";
    return 0;
}