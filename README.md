# Linked List Manager (C++ With UI)

A modern, visual demonstration of the Linked List data structure. This project combines low-level C++ memory management with a reactive GUI built using the [Slint](https://slint.dev/) UI framework.

![UI Preview](preview/Preview.png)

## 🚀 Features
- **Dual Data Structures**: Support for both Singly and Doubly Linked Lists.
- **Visual List Representation**: Real-time rendering of nodes and pointers.
- **Dynamic Operations**:
  - Insert at Beginning, End, or Specific Position.
  - Remove from Beginning, End, or Specific Position.
  - Interactive "X" button on each node for direct deletion.
- **Optimized Traversal**: Doubly Linked List implementation uses bidirectional traversal to optimize operations near the end of the list.
- **Modern C++ Core**: Uses an abstract base class for polymorphism and RAII for memory safety.
- **Cross-Platform**: Built with CMake, supporting Windows, macOS, and Linux.

## 🛠️ Supported Structures

### 1. Singly Linked List (`SLinkList<T>`)
- Each node points to the next node.
- Efficient memory usage (one pointer per node).
- Best for forward-only traversal and stacks.

### 2. Doubly Linked List (`DLinkList<T>`)
- Each node points to both the next and previous nodes.
- **Optimized Indexing**: Search/Insert/Remove operations start from the nearest end (Head or Tail), reducing traversal time by up to 50% ($O(n/2)$ average).
- Supports bidirectional traversal.

## 🛠️ Tech Stack
- **Language**: C++20
- **UI Framework**: Slint
- **Build System**: CMake 3.28+
- **Architecture**: Polymorphic Design (Interface-based programming).

## 📥 Getting Started

### Prerequisites
1. **C++ Compiler**: GCC, Clang, or MSVC (supporting C++20).
2. **CMake**: Version 3.28 or higher.
3. **Slint Compiler**: Follow the [Slint Installation Guide](https://slint.dev/docs/cpp/getting_started).

### Build & Run
```bash
# 1. Clone the repository
git clone https://github.com/red-arachnid/LinkList_Application_Demo.git
cd LinkList_Application_Demo

# 2. Create build directory
mkdir build && cd build

# 3. Configure and build
cmake ..
cmake --build .

# 4. Run the application
./linklist_project
```

## 🧠 Learning Journey

- **Polymorphism**: Refactored the core logic to use an abstract `LinkList<T>` base class, allowing the UI to interact with different list implementations interchangeably.
- **Bidirectional Logic**: Implementing the Doubly Linked List required careful pointer management to maintain head, tail, and sibling links.
- **Memory Management**: Ensuring zero leaks across both implementations using manual pointer handling within RAII-compliant classes.
- **Bridge Logic**: Connecting a procedural C++ backend to a reactive, declarative UI (Slint).

## 📈 Future Improvements
- [ ] **Iterators**: Add `begin()` and `end()` support to make the list compatible with C++ Standard Library algorithms.
- [ ] **Persistence**: Add the ability to save/load the list data to a JSON or CSV file.
- [ ] **Circular Lists**: Implement Circular Singly and Doubly Linked Lists.

---
*Created as part of a personal exploration into Data Structures and Modern C++ Development.*
