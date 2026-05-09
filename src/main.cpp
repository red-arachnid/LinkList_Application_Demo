#include<slint.h>
#include<stdexcept>
#include"app.h"
#include"linklist.hpp"
#include"slinklist.hpp"
#include"dlinklist.hpp"

class LinkListModel : public slint::Model<Data> {
    LinkList<Data>* modelList;

    public:
    LinkListModel(LinkList<Data>* list) : modelList(list) {}

    void setList(LinkList<Data>* newList) {
        modelList = newList;
        this->notify_reset();
    }

    size_t row_count() const override {
        return modelList->size();
    }

    std::optional<Data> row_data(size_t index) const override {
        if (index >= modelList->size()) return {};
        return modelList->get(index);
    }

    void notify_inserted(size_t index) {
        this->notify_row_added(index, 1);
    }
    void notify_removed(size_t index) {
        this->notify_row_removed(index, 1);
    }
};

int main() {
    SLinkList<Data> sList;
    DLinkList<Data> dList;
    LinkList<Data>* activeList;
    activeList = &sList;

    auto nodes = std::make_shared<LinkListModel>(activeList);
    int idCounter = 0;

    auto app = AppWindow::create();
    app->set_nodes(nodes);

    app->on_list_type_change([&](int type) {
        if (type == 0) {
            activeList = &sList;
            nodes->setList(activeList);
        }
        else if (type == 1) {
            activeList = &dList;
            nodes->setList(activeList);
        }
        else {
            std::runtime_error("The link list type was undefined");
        }
    });

    app->on_insert_front([&](Data data) {
        data.id = ++idCounter;
        activeList->insertFront(data);
        nodes->notify_inserted(0);
    });

    app->on_insert_back([&](Data data) {
        data.id = ++idCounter;
        activeList->insertBack(data);
        nodes->notify_inserted(activeList->size() - 1);
    });

    app->on_insert_at_index([&](Data data, int pos) {
        data.id = ++idCounter;

        size_t actualIndex;
        if (pos <= 0) {
            actualIndex = 0;
        }
        else if (static_cast<size_t>(pos) >= activeList->size()){
            actualIndex = activeList->size();
        }
        else {
            actualIndex = static_cast<size_t>(pos);
        }
        activeList->insertAtIndex(data, actualIndex);
        nodes->notify_inserted(actualIndex);
    });

    app->on_remove_front([&]() {
        if (activeList->size() > 0) {
            activeList->removeFront();
            nodes->notify_removed(0);
        }
    });

    app->on_remove_back([&]() {
        if (activeList->size() > 0) {
            size_t index = activeList->size() - 1;
            activeList->removeBack();
            nodes->notify_removed(index);
        }
    });

    app->on_remove_from_index([&](int pos) {
        activeList->removeFromIndex(pos);

        size_t actualIndex;
        if (pos <= 0) {
            actualIndex = 0;
        }
        else if (static_cast<size_t>(pos) >= activeList->size()){
            actualIndex = activeList->size() - 1;
        }
        else {
            actualIndex = static_cast<size_t>(pos);
        }
        nodes->notify_removed(actualIndex);
    });

    app->run();
    return 0;
}