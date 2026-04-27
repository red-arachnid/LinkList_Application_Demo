#include"linklist.hpp"
#include"app.h"

int main() {
    auto app = AppWindow::create();
    int counter = app->get_counter();

    app->on_test([&]() {
        counter++;
        app->set_counter(counter);
    });

    app->run();
    return 0;
}