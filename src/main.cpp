#include"linklist.hpp"
#include"app.h"
#include<slint.h>
#include<iostream>

class LinkListModel : public slint::Model<Data> {
    LinkList<Data>& modelList;

    public:
    LinkListModel(LinkList<Data>& list) : modelList(list) {}

    size_t row_count() const override {
        return modelList.size();
    }

    std::optional<Data> row_data(size_t index) const override {
        if (index >= modelList.size()) return {};
        return modelList.get(index);
    }

    void notify_inserted(size_t index) {
        this->notify_row_added(index, 1);
    }
    void notify_removed(size_t index) {
        this->notify_row_removed(index, 1);
    }
    void notify_all_reset() {
        this->notify_reset();
    }
};

//! Make The ID Counter Such That ID = Position of Block
int main() {

    LinkList<Data> list;
    auto nodes = std::make_shared<LinkListModel>(list);
    int idCounter = 0;

    auto app = AppWindow::create();

    app->set_nodes(nodes);

    app->on_insert_front([&](Data data) {
        if (data.name == "" || data.message == ""){
            //! Show a Error Dialog box here somehow
            return;
        }

        data.id = ++idCounter;
        list.insertFront(data);
        nodes->notify_inserted(0);
    });

    app->on_insert_back([&](Data data) {
        if (data.name == "" || data.message == ""){
            //! Show a Error here too
            return;
        }

        data.id == ++idCounter;
        list.insertBack(data);
        nodes->notify_inserted(list.size() - 1);
    });

    app->on_insert_at_pos([&](Data data, int pos) {
        if (data.name == "" || data.message == ""){
            //! Show A Error
            return;
        }

        data.id = ++idCounter;
        list.insertAtIndex(data, pos);

        int actualIndex;
        if (pos <= 0) {
            actualIndex = 0;
        }
        else if (pos >= list.size()){
            actualIndex = list.size() - 1;
        }
        else {
            actualIndex = pos;
        }
        nodes->notify_inserted(actualIndex);
    });

    app->run();
    return 0;
}