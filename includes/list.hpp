#pragma once 
#include <memory>
#include <cstddef>

template<typename T>
class List {
    private:
        struct Node {
            T value;
            std::unique_ptr<Node> next;
            Node* prev;

            //Construtor de Node
            Node(const T& value, std::unique_ptr<Node> next = nullptr,
            Node* prev = nullptr);
        };
        std::unique_ptr<Node> head = nullptr;
        Node* tail = nullptr;
        std::size_t size_l = 0;

    public:
        //Construtor da classe List
        List() = default;

        //Insere um valor na lista
        void insert(const T& value, std::size_t index);
        
         //Insere no final da lista
        void push_back(const T& value);

        //Insere no começo da lista
        void push_front(const T& value);

        //Remove um valor da lista
        void remove(std::size_t index);

        //Remove no final da lista
        void pop_back();

        //Remove no começo da lista
        void pop_front();

        //Remove todos os elementos da lista
        void clear();

        //Retorna true se a lista estiver vazia
        bool empty() const;

        //Retorna o tamanho da lista
        std::size_t size() const;

        //Retorna o valor da frente da lista e permite editar o valor
        T& get_front();

        //Retorna o valor de trás da lista e permite editar o valor
        T& get_back();

        //Retorna um valor da lista na posição informada e permite editar o valor
        T& get(std::size_t index);

        //Retorna o valor da frente da lista
        const T& get_front() const;

        //Retorna o valor de trás da lista
        const T& get_back() const;

        //Retorna um valor da lista na posição informada
        const T& get(std::size_t index) const;

        //Imprime os valores na lista
        void print_list(std::ostream& os) const;
};  

#include "list.tpp"