#include <iostream>
#include <cassert>
#include "list.hpp"

template<typename T>
void show_list(const List<T>& list) {
    std::cout << "\nLista: ";
    list.print_list(std::cout);
    std::cout << "Tamanho da lista: " << list.size() << "\n\n";
}

int main() {
    List<int> list;

    list.push_front(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    show_list(list);

    assert(list.size() == 5);
    assert(list.get_front() == 10);
    assert(list.get_back() == 50);

    std::cout << "Removendo elemento " << list.get(1) << "...\n";
    list.remove(1);

    show_list(list);

    assert(list.size() == 4);
    assert(list.get(0) == 10);
    assert(list.get(1) == 30);
    assert(list.get(2) == 40);
    assert(list.get(3) == 50);

    std::cout << "Removendo elemento " << list.get(2) << "...\n";
    list.remove(2);

    show_list(list);

    assert(list.size() == 3);
    assert(list.get(0) == 10);
    assert(list.get(1) == 30);
    assert(list.get(2) == 50);

    list.insert(5, 0);
    std::cout << "Inserindo elemento na posição 0...\n";

    show_list(list);

    assert(list.get_front() == 5);
    assert(list.size() == 4);

    list.insert(20, 2);
    std::cout << "Inserindo elemento na posição 2...\n";

    show_list(list);

    assert(list.get(2) == 20);
    assert(list.size() == 5);

    list.insert(40, 4);
    std::cout << "Inserindo elemento na posição 4...\n";

    show_list(list);

    assert(list.get(4) == 40);
    assert(list.size() == 6);

    std::cout << "Removendo elemento " << list.get_front() << "...\n";
    list.pop_front();

    show_list(list);

    assert(list.get_front() == 10);
    assert(list.size() == 5);

    std::cout << "Removendo elemento " << list.get_back() << "...\n";
    list.pop_back();

    show_list(list);

    assert(list.get_back() == 40);
    assert(list.size() == 4);

    std::cout << "Removendo todos os elementos da lista...\n";
    list.clear();

    show_list(list);

    assert(list.empty());
    assert(list.size() == 0);

    return 0;
}