#include<iostream>
#include"linklist.hpp"
using namespace std;

int main() {
    LinkList<int> numberList;
    numberList.insertFront(10);
    numberList.insertFront(20);
    numberList.insertBack(30);
    numberList.insertBack(40);
    numberList.insertAtPos(50, 2);
    numberList.show();
    cout<<"\n\n";

    numberList.removeBack();
    numberList.removeFront();
    numberList.removeAtPos(4);
    numberList.show();
    cout<<"\n\n";

    return 0;
}