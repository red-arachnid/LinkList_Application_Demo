#include<stdexcept>
#include"node.hpp"

template <typename T>
class LinkList {
    Node<T>* start;
    Node<T>* end;
    size_t nodeCount;

public:
    LinkList() : start(nullptr), end(nullptr), nodeCount(0) {}

    ~LinkList() {
        while(start != nullptr) {
            removeFront();
        }
    }

    //DISABLE COPYING
    LinkList(const LinkList&) = delete;
    LinkList& operator = (const LinkList&) = delete;

    void insertFront(T data) {
        Node<T>* temp = new Node<T>(data);

        if (start == nullptr){
            end = start = temp;
        }
        else {
            temp->next = start;
            start = temp;
        }
        nodeCount++;
    }
    
    void insertBack(T data) {
        Node<T>* temp = new Node<T>(data);

        if (start == nullptr){
            end = start = temp;
        }
        else {
            end->next = temp;
            end = temp;
        }
        nodeCount++;
    }   

    void insertAtIndex(T data, size_t index) {
        if (index <= 0){
            insertFront(data);
            return;
        }

        if (index >= nodeCount) {
            insertBack(data);
            return;
        }

        Node<T>* ptr = start;
        for (size_t i = 0; i < index-1; i++) {
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(data);
        temp->next = ptr->next;
        ptr->next = temp;
        nodeCount++;
    }

    void removeFront() {
        if (start == nullptr) {
            throw std::runtime_error("Link List is empty");
        }

        Node<T>* temp = start;

        start = start->next;
        if (start == nullptr) {
            end = nullptr;
        }
        delete temp;
        nodeCount--;
    }

    void removeBack() {
        if (start == nullptr) {
            throw std::runtime_error("Link List is empty");
        }

        if (start == end) {
            delete start;
            start = end = nullptr;
        }
        else {
            Node<T>* ptr = start;

            while (ptr->next != end){
                ptr = ptr->next;
            }
            delete end;
            end = ptr;
            end->next = nullptr;
        }
        nodeCount--;
    }

    void removeFromIndex(size_t index) {
        if (index == 0) {
            removeFront();
            return;
        }

        if (index >= nodeCount - 1) {
            removeBack();
            return;
        }

        Node<T>* ptr = start;
        for (size_t i = 0; i < index - 1; i++) {
            ptr = ptr->next;
        }

        Node<T>* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        nodeCount--;
    }

    size_t size() const {
        return nodeCount;
    }

    T get(size_t index) const {
        if (index >= nodeCount) 
            throw std::out_of_range("Index out of range");

        Node<T>* ptr = start;
        for (size_t i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    }
};
