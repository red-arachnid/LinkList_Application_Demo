#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
struct DNode {
    DNode<T>* prev;
    T data;
    DNode<T>* next;
};