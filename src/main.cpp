#include<iostream>
// #include"linklist.hpp"
#include"app-window.h"
using namespace std;

int main() {
    auto hello_world = HelloWorld::create();
    hello_world->set_my_label("UNGA BUNGA");
    // Show the window and spin the event loop until the window is closed.
    hello_world->run();
    return 0;   
}