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