#include<slint.h>
#include"app.h"
#include"linklist.hpp"

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
};

int main() {
    LinkList<Data> list;
    auto nodes = std::make_shared<LinkListModel>(list);
    int idCounter = 0;

    auto app = AppWindow::create();

    app->set_nodes(nodes);

    app->on_insert_front([&](Data data) {
        data.id = ++idCounter;
        list.insertFront(data);
        nodes->notify_inserted(0);
    });

    app->on_insert_back([&](Data data) {
        data.id = ++idCounter;
        list.insertBack(data);
        nodes->notify_inserted(list.size() - 1);
    });

    app->on_insert_at_pos([&](Data data, int pos) {
        data.id = ++idCounter;

        size_t actualIndex;
        if (pos <= 0) {
            actualIndex = 0;
        }
        else if (static_cast<size_t>(pos) >= list.size()){
            actualIndex = list.size();
        }
        else {
            actualIndex = static_cast<size_t>(pos);
        }
        list.insertAtIndex(data, actualIndex);
        nodes->notify_inserted(actualIndex);
    });

    app->on_remove_front([&]() {
        if (list.size() > 0) {
            list.removeFront();
            nodes->notify_removed(0);
        }
    });

    app->on_remove_back([&]() {
        if (list.size() > 0) {
            size_t index = list.size() - 1;
            list.removeBack();
            nodes->notify_removed(index);
        }
    });

    app->on_remove_from_pos([&](int pos) {
        list.removeFromIndex(pos);

        size_t actualIndex;
        if (pos <= 0) {
            actualIndex = 0;
        }
        else if (static_cast<size_t>(pos) >= list.size()){
            actualIndex = list.size() - 1;
        }
        else {
            actualIndex = static_cast<size_t>(pos);
        }
        nodes->notify_removed(actualIndex);
    });

    app->run();
    return 0;
}