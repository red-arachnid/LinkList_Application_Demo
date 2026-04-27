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
        list.show();
    });

    app->run();
    return 0;
}