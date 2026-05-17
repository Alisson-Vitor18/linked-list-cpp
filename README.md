![C++](https://img.shields.io/badge/C%2B%2B-17-blue)

# Listas Duplamente Encadeadas em C++

Este projeto implementa uma lista duplamente encadeada em C++ utilizando templates, permitindo o armazenamento genérico de dados. O objetivo é estudar estruturas de dados em C++. Também é demonstrado o uso da `std::list` da STL para fins de comparação e demonstração.

---

## O que é uma lista duplamente encadeada

Listas duplamente encadeadas são estruturas de dados que permitem realizar operações no início, no meio e no fim da lista. Diferente de estruturas como pilhas e filas, elas permitem percorrer seus nós em ambas as direções, utilizando os ponteiros `next` e `prev`. Por essa flexibilidade, são amplamente utilizadas na programação em diversas situações do dia a dia, como:

- **Histórico de navegação**: navegadores permitem avançar e voltar entre páginas visitadas, algo parecido com percorrer uma lista para frente e para trás.

- **Players de música**: em uma playlist, é possível ir para a próxima música ou voltar para a anterior.

- **Editores de texto**: operações de desfazer e refazer podem usar uma lógica parecida, permitindo navegar entre estados anteriores e posteriores.

- **Sistemas de arquivos**: algumas estruturas internas podem usar listas para organizar elementos que precisam ser percorridos em mais de uma direção.

- **Gerenciamento de abas ou janelas**: programas podem manter uma sequência de abas abertas, permitindo avançar, voltar, inserir ou remover abas.

- **Jogos**: listas podem ser usadas para controlar objetos ativos em uma fase, como inimigos, projéteis ou itens, permitindo inserir e remover elementos durante a execução.

### Por que usar estruturas encadeadas?

O principal objetivo de utilizar estruturas encadeadas é a flexibilidade de tamanho, já que não é necessário definir previamente um limite fixo de elementos. Dessa forma, a estrutura pode crescer dinamicamente conforme a necessidade da aplicação, desde que haja memória disponível no sistema.

---

## Funcionalidades 

- insert     (insere um elemento em uma posição da lista)
- push_back  (insere um elemento no final da lista)
- push_front (insere um elemento no início da lista)
- remove     (remove um elemento em uma posição da lista)
- pop_back   (remove o elemento no final da lista)
- pop_front  (remove o elemento no início da lista)
- clear      (remove todos os elementos da lista)
- empty      (verifica se a lista está vazia)
- size       (retorna o tamanho da lista)
- get_front  (retorna o elemento do início da lista)
- get_back   (retorna o elemento do final da lista)
- get        (retorna o elemento de uma posição da lista)

---

## Tecnologias utilizadas

- C++
- Templates
- Smart pointers (`std::unique_ptr`)
- Estruturas de dados encadeadas
- STL (`std::list`)
- Valgrind

--- 

## Complexidade dos métodos implementados

| Método       | Complexidade |
|--------------|--------------|
| `insert`     | O(n)         |
| `push_back`  | O(1)         |
| `push_front` | O(1)         |
| `remove`     | O(n)         |
| `pop_back`   | O(1)         |
| `pop_front`  | O(1)         |
| `clear`      | O(n)         |
| `empty`      | O(1)         |
| `size`       | O(1)         |
| `get_front`  | O(1)         |
| `get_back`   | O(1)         |
| `get`        | O(n)         |

> Onde `n` representa a quantidade de elementos presentes na lista.

Em operações que acessam posições intermediárias, a busca pode começar pelo início ou pelo fim da lista, dependendo do índice informado. Mesmo assim, a complexidade assintótica permanece O(n).

---

## Como executar (Terminal - Ubuntu 24.04 LTS)

```bash
mkdir -p build
g++ src/main.cpp -Iincludes -o build/program
./build/program
```

---

## Testes e demonstração da implementação própria

```cpp
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
```

O `assert` é utilizado para verificar se as operações produziram o resultado esperado. Caso alguma condição seja falsa, o programa será interrompido, indicando possível erro na implementação.

### Saída esperada

```bash
Lista: [10, 20, 30, 40, 50]
Tamanho da lista: 5

Removendo elemento 20...

Lista: [10, 30, 40, 50]
Tamanho da lista: 4

Removendo elemento 40...

Lista: [10, 30, 50]
Tamanho da lista: 3

Inserindo elemento na posição 0...

Lista: [5, 10, 30, 50]
Tamanho da lista: 4

Inserindo elemento na posição 2...

Lista: [5, 10, 20, 30, 50]
Tamanho da lista: 5

Inserindo elemento na posição 4...

Lista: [5, 10, 20, 30, 40, 50]
Tamanho da lista: 6

Removendo elemento 5...

Lista: [10, 20, 30, 40, 50]
Tamanho da lista: 5

Removendo elemento 50...

Lista: [10, 20, 30, 40]
Tamanho da lista: 4

Removendo todos os elementos da lista...

Lista: []
Tamanho da lista: 0
```

---