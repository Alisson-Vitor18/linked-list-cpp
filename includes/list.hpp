#pragma once 
#include <memory>

template<typename T>
class List {
    private:
        struct Node {
            T value;
            std::unique_ptr<Node> next;
            std::unique_ptr<Node> prev;

            //Construtor de Node
            List(const T& value, std::unique_ptr<Node> next = nullptr,
                std::unique_ptr<Node> prev = nullptr;);
        };
        std::unique_ptr<Node> head;
        std::unique_ptr<Node> tail;
        std::size_t size;

    public:
        //Construtor da classe List
        List() = default;

};  

#include "list.tpp"