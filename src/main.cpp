#include"linklist.hpp"
#include<iostream>
#include"app.h"

int main() {

    LinkList<Data> list;
    int idCounter = 0;

    auto app = AppWindow::create();

    app->on_insert_front([&](Data data) {
        if (data.name == "" || data.message == ""){
            //! Show a Error Dialog box here somehow
            return;
        }

        data.id = ++idCounter;
        list.insertFront(data);
    });

    app->on_insert_back([&](Data data) {
        if (data.name == "" || data.message == ""){
            //! Show a Error here too
            return;
        }

        data.id == ++idCounter;
        list.insertBack(data);
    });

    app->on_insert_at_pos([&](Data data, int pos) {
        if (data.name == "" || data.message == ""){
            //! Show A Error
            return;
        }

        data.id = ++idCounter;
        list.insertAtPos(data, pos);
    });

    app->run();
    return 0;
}