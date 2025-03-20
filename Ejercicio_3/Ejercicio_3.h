#ifndef EJERCICIO_3_H
#define EJERCICIO_3_H

#include <iostream>
#include <string>
#include <fstream>
#include <memory>

using namespace std;    

struct Node {
    int value;
    shared_ptr<Node> next;
}typedef Node;

struct List {
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size;
}typedef List;

shared_ptr<Node> create_node(int value);

void push_front(shared_ptr<List> list, shared_ptr<Node> node);

void push_back(shared_ptr<List> list, shared_ptr<Node> node);

void insert(shared_ptr<List> list, shared_ptr<Node> node, int position);

void erase(shared_ptr<List> list, int position);

void print_list(shared_ptr<List> list);


#endif