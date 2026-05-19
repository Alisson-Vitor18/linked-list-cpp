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

## Estrutura do projeto

```bash
.
├── includes/
│   ├── list.hpp
│   └── list.tpp
├── src/
│   └── main.cpp
├── .gitignore
├── LICENSE
└── README.md
```

---

## Funcionalidades 

- `insert`     (insere um elemento em uma posição da lista)
- `push_back`  (insere um elemento no final da lista)
- `push_front` (insere um elemento no início da lista)
- `remove`     (remove um elemento em uma posição da lista)
- `pop_back`   (remove o elemento no final da lista)
- `pop_front`  (remove o elemento no início da lista)
- `clear`      (remove todos os elementos da lista)
- `empty`      (verifica se a lista está vazia)
- `size`       (retorna o tamanho da lista)
- `get_front`  (retorna o elemento do início da lista)
- `get_back`   (retorna o elemento do final da lista)
- `get`        (retorna o elemento de uma posição da lista)

A estrutura foi implementada com templates, permitindo armazenar diferentes tipos de dados, como `int`, `float`, `std::string` ou tipos definidos pelo usuário.

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

## Gerenciamento de memória

Esta implementação utiliza `std::unique_ptr` para gerenciamento automático de memória, seguindo os princípios de RAII (*Resource Acquisition Is Initialization*).

Por utilizar smart pointers da STL, não é necessário liberar memória manualmente com `delete`, já que a destruição dos nós ocorre automaticamente quando deixam de ser utilizados. Dessa forma, a implementação se torna mais segura e reduz o risco de vazamentos de memória.

---

## Verificação com Valgrind

O projeto também foi testado com o **Valgrind**, uma ferramenta amplamente utilizada em sistemas Linux para detectar problemas relacionados ao gerenciamento de memória em aplicações C e C++.

Com o Valgrind é possível identificar:

- Vazamentos de memória (*memory leaks*)
- Uso de memória não inicializada
- Acessos inválidos à memória
- Problemas relacionados à desalocação de memória

### Compilando e executando com Valgrind

```bash
mkdir -p build
g++ src/main.cpp -Iincludes -g -o build/program
valgrind --leak-check=full ./build/program
```

### Saída esperada

```bash
==1541== Memcheck, a memory error detector
==1541== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==1541== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==1541== Command: ./build/program
==1541== 

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

==1541== 
==1541== HEAP SUMMARY:
==1541==     in use at exit: 0 bytes in 0 blocks
==1541==   total heap usage: 10 allocs, 10 frees, 74,944 bytes allocated
==1541== 
==1541== All heap blocks were freed -- no leaks are possible
==1541== 
==1541== For lists of detected and suppressed errors, rerun with: -s
==1541== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

O resultado acima demonstra que, mesmo após a utilização dos métodos implementados, toda a memória alocada foi liberada corretamente, sem ocorrência de vazamentos de memória.

---

## Sobre a std::list (C++ STL)

A linguagem C++ já fornece uma implementação pronta de lista através da `std::list`, presente na Standard Template Library (STL). Essa estrutura é amplamente utilizada em aplicações reais, oferecendo uma interface simples e eficiente para operações de inserção e remoção, especialmente quando já se possui um iterador para a posição desejada.

No desenvolvimento do dia a dia, o uso de estruturas prontas fornecidas pela linguagem costuma ser a melhor escolha, já que elas são amplamente testadas, otimizadas e facilitam a manutenção do código.

---

### Exemplo de uso com a std::list

```cpp
#include <iostream>
#include <iterator>
#include <cstddef>
#include <list> 

void print_list(const std::list<int>& list);
void insere_posicao(std::list<int>& list, std::size_t p, int valor);

int main()
{
    //Cria uma lista de inteiros
    std::list<int> list;
        
    //Insere elementos na lista
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);
    
    //Inicializa it no começo da lista
    auto it = list.begin();
    
    //Imprime a lista
    print_list(list);
    
    //Exibe o elemento na posição 0
    std::cout << "\nRemovendo elemento: " << *it << std::endl;
    std::cout << std::endl;
    
    //Exclui o elemento no início da lista
    list.pop_front();
    
    //Imprime a lista
    print_list(list);
    
    //Exibe o elemento na última posição
    std::cout << "\nRemovendo elemento: " << list.back() << std::endl;
    std::cout << std::endl;

    //Exclui o elemento no final da lista
    list.pop_back();

    //Imprime a lista
    print_list(list);
    
    //Insere o elemento 5 na posição 0
    insere_posicao(list, 0, 5);
    
    std::cout << "\nInserindo elemento 5...\n" << std::endl;
    
    //Imprime a lista
    print_list(list);
    
    //Insere o elemento 10 na posição 1
    insere_posicao(list, 1, 10);
    
    std::cout << "\nInserindo elemento 10...\n" << std::endl;
    
    //Imprime a lista
    print_list(list);
    
    //Insere o elemento 50 na posição 5
    insere_posicao(list, 5, 50);
    
    std::cout << "\nInserindo elemento 50...\n" << std::endl;
    
    //Imprime a lista
    print_list(list);
    
    //Remove todos os elementos da lista
    list.clear();
    
    std::cout << "\nRemovendo todos os elementos da lista...\n" << std::endl;

    //Imprime a lista
    print_list(list);

    return 0;
}

void print_list(const std::list<int>& list) {
    bool first = true;
    
    std::cout << "lista: [";
    for(auto l : list) {
        if(!first) std::cout << ", ";
        std::cout << l;
        first = false;
    }
    std::cout << "]\n";
    
    std::cout << "Tamanho da lista: " << list.size() << std::endl;
}

void insere_posicao(std::list<int>& list, std::size_t p, int valor) {
    if (p > list.size()) {
        std::cout << "Posição inválida\n";
        return;
    }
    
    std::list<int>::iterator it = list.begin();
    
    std::advance(it, p);
    
    list.insert(it, valor);
}
```

### Saída esperada

```bash
lista: [10, 20, 30, 40, 50]
Tamanho da lista: 5

Removendo elemento: 10

lista: [20, 30, 40, 50]
Tamanho da lista: 4

Removendo elemento: 50

lista: [20, 30, 40]
Tamanho da lista: 3

Inserindo elemento 5...

lista: [5, 20, 30, 40]
Tamanho da lista: 4

Inserindo elemento 10...

lista: [5, 10, 20, 30, 40]
Tamanho da lista: 5

Inserindo elemento 50...

lista: [5, 10, 20, 30, 40, 50]
Tamanho da lista: 6

Removendo todos os elementos da lista...

lista: []
Tamanho da lista: 0
```

---

## Objetivo do projeto
Este projeto foi desenvolvido **exclusivamente para fins de estudo e demonstração**, com o objetivo de entender como estruturas encadeadas podem ser implementadas em C++.

---

## Conclusão

Embora a implementação própria seja importante para fins educacionais, em projetos reais geralmente é recomendado utilizar ferramentas prontas como a `std::list`, que oferecem maior confiabilidade, manutenção simplificada e integração com o ecossistema da linguagem.

---

## Autor

Desenvolvido por **Alisson Vitor Pereira Barbosa**