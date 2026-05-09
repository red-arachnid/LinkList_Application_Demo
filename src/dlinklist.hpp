#include<stdexcept>
#include "node.hpp"

template <typename T>
class DLinkList {
    DNode<T>* start;
    DNode<T>* end;
    size_t nodeCount;

public:
    DLinkList() : start(nullptr), end(nullptr), nodeCount(0) {}

    ~DLinkList() {
        while (start != nullptr) {
            removeFront();
        }
    }

    // DISABLE COPYING
    DLinkList(const DLinkList&) = delete;
    DLinkList& operator = (const DLinkList&) = delete;

    void insertFront(T data) {
        DNode<T>* temp = new DNode<T>(data);

        if (start == nullptr) {
            end = start = temp;
        }
        else {
            temp->next = start;
            start->prev = temp;
            start = temp;
        }
        nodeCount++;
    }

    void insertBack(T data) {
        DNode<T>* temp = new DNode<T>(data);

        if (start == nullptr) {
            end = start = temp;
        }
        else {
            end-> next = temp;
            temp->prev = end;
            end = temp;
        }
        nodeCount++;
    }

    void insertAtIndex(T data, size_t index) {
        if (index <= 0) {
            insertFront(data);
            return;
        }

        if (index >= nodeCount) {
            insertBack(data);
            return;
        }
        
        DNode<T>* ptr;
        DNode<T>* temp = new DNode<T>(data);

        if (index < nodeCount / 2) {
            ptr = start;
            for (size_t i = 0; i < index-1; i++) {
                ptr = ptr->next;
            }

            temp->next = ptr->next;
            temp->prev = ptr;
            ptr->next->prev = temp;
            ptr->next = temp;
        }
        else {
            ptr = end;
            for (size_t i = nodeCount; i > index+1; i--) {
                ptr = ptr->prev;
            }

            temp->next = ptr;
            temp->prev = ptr->prev;
            ptr->prev->next = temp;
            ptr->prev = temp;
        }
        nodeCount++;
    }

    void removeFront() {
        if (start == nullptr) {
            throw std::runtime_error("Link List is empty");
        }

        DNode<T>* temp = start;

        start = start->next;
        if (start != nullptr) {
            start->prev = nullptr;
        }
        else {
            end = nullptr;
        }
        delete temp;
        nodeCount--;
    }

    void removeBack() {
        if (start == nullptr) {
            throw std::runtime_error("Link List is empty");
        }

        DNode<T>* temp = end;

        end = end->prev;
        if (end != nullptr) {
            end->next = nullptr;
        }
        else {
            start = nullptr;
        }
        delete temp;
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

        DNode<T>* ptr;
        if (index < nodeCount / 2) {
            ptr = start;
            for (size_t i = 0; i < index; i++) {
                ptr = ptr->next;
            }
        }
        else {
            ptr = end;
            for (size_t i = nodeCount - 1; i > index; i--) {
                ptr = ptr->prev;
            }
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        nodeCount--;
    }

    size_t size() const {
        return nodeCount;
    }

    T get(size_t index) const {
        if (index >= nodeCount)
            throw std::out_of_range("Index out of range");
        
        DNode<T>* ptr;

        if (index < nodeCount / 2){
            ptr = start;
            for (size_t i = 0; i < index; i++) {
                ptr = ptr->next;
            }
        }
        else {
            ptr = end;
            for (size_t i = nodeCount - 1; i > index; i--) {
                ptr = ptr->prev;
            }
        }

        return ptr->data;
    }
};
