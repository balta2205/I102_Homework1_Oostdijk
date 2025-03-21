#include "Ejercicio_3.h"

using namespace std; 

int main() {
    // Crear lista vacía
    shared_ptr<List> list = make_shared<List>();
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;

    // Crear nodos
    shared_ptr<Node> node1 = create_node(1);
    shared_ptr<Node> node2 = create_node(2);
    shared_ptr<Node> node3 = create_node(3);
    shared_ptr<Node> node4 = create_node(4);
    shared_ptr<Node> node5 = create_node(5);

    // Agregar nodos
    push_front(list, node1);
    push_front(list, node2);
    push_back(list, node3);
    push_back(list, node4);
    insert(list, node5, 2);  // Insertar en posición 2
    erase(list, 2);          // Eliminar en posición 2

    // Imprimir lista
    print_list(list);

    return 0;
}

// Crear un nodo
shared_ptr<Node> create_node(int value) {
    shared_ptr<Node> node = make_shared<Node>();
    node->value = value;
    node->next = nullptr;
    return node;
}

// Insertar al frente
void push_front(shared_ptr<List> list, shared_ptr<Node> node) {
    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

// Insertar al final
void push_back(shared_ptr<List> list, shared_ptr<Node> node) {
    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Insertar en una posición específica
void insert(shared_ptr<List> list, shared_ptr<Node> node, int position) {
    if (position == 0) { push_front(list, node); return; }

    if (position >= list->size || position < 0) {
        push_back(list, node);
        return;
    }

    shared_ptr<Node> current = list->head;
    for (int i = 0; i < position - 1; i++) current = current->next;
    node->next = current->next;
    current->next = node;
    list->size++;
}

// Eliminar nodo en una posición específica
void erase(shared_ptr<List> list, int position) {
    if (!list->head) return;

    if (position >= list->size) position = list->size - 1;

    if (position == 0) {
        list->head = list->head->next;
        if (!list->head) list->tail = nullptr;
        list->size--;
        return;
    }

    shared_ptr<Node> current = list->head;
    for (int i = 0; i < position - 1; i++) current = current->next;

    if (current->next == list->tail) list->tail = current;
    current->next = current->next->next;
    list->size--;
}

// Imprimir la lista
void print_list(shared_ptr<List> list) {
    shared_ptr<Node> current = list->head;
    while (current) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
