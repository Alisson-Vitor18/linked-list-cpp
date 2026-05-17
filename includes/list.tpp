#include <stdexcept>
#include <utility>

template<typename T>
List<T>::Node::Node(const T& value, std::unique_ptr<Node> next, Node* prev) :
    value(value), next(std::move(next)), prev(prev) {}

template<typename T>
void List<T>::insert(const T& value, std::size_t index) {
    if(index > this->size_l) {
        throw std::out_of_range("Não é possível inserir, pois a posição é inválida!");
    }

    if(index == 0) {
        push_front(value);
        return;
    }

    if(index == this->size_l) {
        push_back(value);
        return;
    }

    auto new_node = std::make_unique<Node>(value);
    Node* previous = nullptr;

    if(index <= this->size_l / 2) {
        previous = this->head.get();

        for(std::size_t i = 0; i < index - 1; i++) {
            previous = previous->next.get();
        }
    } else {
        previous = this->tail;
        for(std::size_t i = this->size_l - 1; i > index - 1; i--) {
            previous = previous->prev;
        }
    }

    Node* next_node = previous->next.get();
    new_node->prev = previous;
    new_node->next = std::move(previous->next);

    next_node->prev = new_node.get();
    previous->next = std::move(new_node);

    this->size_l++;
}

template<typename T>
void List<T>::push_back(const T& value) {
    auto new_node = std::make_unique<Node>(value);
    Node* raw_node = new_node.get();

    if(empty()) {
        this->head = std::move(new_node);
        this->tail = raw_node;
    } else {
        new_node->prev = this->tail;
        this->tail->next = std::move(new_node);
        this->tail = raw_node;
    }

    this->size_l++;
}

template<typename T>
void List<T>::push_front(const T& value) {
    auto new_node = std::make_unique<Node>(value);
    Node* raw_node = new_node.get();

    if(empty()) {
        this->head = std::move(new_node);
        this->tail = raw_node;
    } else {
        this->head->prev = raw_node;
        new_node->next = std::move(this->head);
        this->head = std::move(new_node);
    }

    this->size_l++;
}

template<typename T>
void List<T>::remove(std::size_t index) {
    if(index >= this->size_l) {
        throw std::out_of_range("Não é possível remover, pois a posição é inválida!");
    }

    if (index == 0) {
        pop_front();
        return;
    }

    if (index == this->size_l - 1) {
        pop_back();
        return;
    }

    Node* current = nullptr;

    if(index <= this->size_l / 2) {
        current = this->head.get();

        for(std::size_t i = 0; i < index; i++) {
            current = current->next.get();
        }
    } else {
        current = this->tail;

        for(std::size_t i = this->size_l - 1; i > index; i--) {
            current = current->prev;
        }
    }
    Node* previous = current->prev;
    Node* next_node = current->next.get();

    previous->next = std::move(current->next);
    next_node->prev = previous;

    this->size_l--;
}

template<typename T>
void List<T>::pop_back() {
    if(empty()) {
        throw std::runtime_error("Não é possível remover, a lista está vazia!");
    }

    if(this->tail == this->head.get()) {
        this->head.reset();
        this->tail = nullptr;
    } else {
        this->tail = this->tail->prev;
        this->tail->next.reset();
    }

    this->size_l--;
}

template<typename T>
void List<T>::pop_front() {
    if(empty()) {
        throw std::runtime_error("Não é possível remover, a lista está vazia!");
    }

    if(this->head.get() == this->tail) {
        this->head.reset();
        this->tail = nullptr;
    } else {
        this->head = std::move(this->head->next);
        this->head->prev = nullptr;
    }

    this->size_l--;
}

template<typename T>
void List<T>::clear() {
    this->head.reset();
    this->tail = nullptr;
    this->size_l = 0;
}

template<typename T>
bool List<T>::empty() const {
    return this->size_l == 0;
}

template<typename T>
std::size_t List<T>::size() const {
    return this->size_l;
}

template<typename T>
T& List<T>::get_front() {
    if(empty()) {
        throw std::runtime_error("A lista está vazia!");
    }
    return this->head->value;
}

template<typename T>
T& List<T>::get_back() {
    if(empty()) {
        throw std::runtime_error("A lista está vazia!");
    }
    return this->tail->value;
}

template<typename T>
T& List<T>::get(std::size_t index) {
    if(empty()) {
        throw std::out_of_range("A lista está vazia!");
    }

    if(index >= this->size_l) {
        throw std::out_of_range("Índice inválido para busca!");
    }
    
    if(index == 0) {
        return get_front();
    }

    if(index == this->size_l - 1) {
        return get_back();
    }

    Node* current = nullptr;
    if(index <= this->size_l / 2) {
        current = this->head.get();

        for(std::size_t i = 0; i < index; i++) {
            current = current->next.get();
        }
    } else {
        current = this->tail;

        for(std::size_t i = this->size_l - 1; i > index; i--) {
            current = current->prev;
        }
    }

    return current->value;
}

template<typename T>
const T& List<T>::get_front() const {
    if(empty()) {
        throw std::runtime_error("A lista está vazia!");
    }

    return this->head->value;
}

template<typename T>
const T& List<T>::get_back() const {
    if(empty()) {
        throw std::runtime_error("A lista está vazia!");
    }

    return this->tail->value;
}

template<typename T>
const T& List<T>::get(std::size_t index) const {
    if(empty()) {
        throw std::out_of_range("A lista está vazia!");
    }

    if(index >= this->size_l) {
        throw std::out_of_range("Índice inválido para busca!");
    }
    
    if(index == 0) {
        return get_front();
    }

    if(index == this->size_l - 1) {
        return get_back();
    }

    const Node* current = nullptr;
    if(index <= this->size_l / 2) {
        current = this->head.get();

        for(std::size_t i = 0; i < index; i++) {
            current = current->next.get();
        }
    } else {
        current = this->tail;

        for(std::size_t i = this->size_l - 1; i > index; i--) {
            current = current->prev;
        }
    }

    return current->value;
}

template<typename T>
void List<T>::print_list(std::ostream& os) const {
    Node* current = this->head.get();
    bool first = true;

    os << "[";
    for(; current != nullptr; current = current->next.get()) {
        if(!first) os << ", ";
        os << current->value;
        first = false;
    }
    os << "]\n";
}