#pragma once
template <typename T>
class LinkList {
public:
    virtual ~LinkList() = default;
    virtual void insertFront(T data) = 0;
    virtual void insertBack(T data) = 0;
    virtual void insertAtIndex(T data, size_t index) = 0;
    virtual void removeFront() = 0;
    virtual void removeBack() = 0;
    virtual void removeFromIndex(size_t index) = 0;
    virtual size_t size() const = 0;
    virtual T get(size_t index) const = 0;
};