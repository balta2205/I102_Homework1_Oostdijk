#include <iostream>
#include <string>
#include <fstream>
#include <memory>

using namespace std;    



// 3. Implemente una lista enlazada que utilice nodos que simplemente contengan un
// valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes
// funciones para manejar la lista:
// i. create_node(): devuelve un nodo.
// ii. push_front(): inserta un nodo al frente de la lista.
// iii. push_back(): inserta un nodo al final de la lista.
// iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa
// una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de
// agregar el nodo al final de la lista.
// v. erase(): borra un nodo en la posición que se le pase a la función. Similar a la
// función insert(), si la posición es mayor que el largo de la lista, se debe de borrar
// el último nodo.
// vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”.
// Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y,
// muy importante para el ejercicio, sólo utilizar smart pointers. 


struct Node {
    int value;
    shared_ptr<Node> next;
}typedef Node;

struct List {
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size;
}typedef List;

shared_ptr<Node> create_node(int value) {
    shared_ptr<Node> node = make_shared<Node>();
    node->value = value;
    node->next = nullptr;
    return node;
}

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

void insert(shared_ptr<List> list, shared_ptr<Node> node, int position) {

    if (position == 0) {push_front(list, node); return;}

    if (position >= list->size || position < 0) {
        cout << "La posición es invalida" << endl;
        push_back(list, node);
        return;
    }

    shared_ptr<Node> current = list->head;
    for (int i = 0; i < position - 1; i++) current = current->next;
    node->next = current->next;
    current->next = node;
    list->size++;
}

void erase(shared_ptr<List> list, int position) {
    if (!list->head) cout << "La lista está vacía, no se puede eliminar un nodo." << endl; return;
    
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

void print_list(shared_ptr<List> list) {
    shared_ptr<Node> current = list->head;
    while (current) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    shared_ptr<List> list = make_shared<List>();
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;

    shared_ptr<Node> node1 = create_node(1);
    shared_ptr<Node> node2 = create_node(2);
    shared_ptr<Node> node3 = create_node(3);
    shared_ptr<Node> node4 = create_node(4);
    shared_ptr<Node> node5 = create_node(5);

    push_front(list, node1);
    push_front(list, node2);
    push_back(list, node3);
    push_back(list, node4);
    insert(list, node5, 2);
    erase(list, 2);

    print_list(list);

    return 0;
}