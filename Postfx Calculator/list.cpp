#include"list.h"

#include<iostream>
#include<stdexcept>
using namespace std;

List::List(){
    size = 0;
    sentinel_head = new(nothrow) Node(true);
    if(sentinel_head == nullptr){
        throw runtime_error("Out of Memory");
    }
    sentinel_tail = new(nothrow) Node(true);
    if(sentinel_tail == nullptr){
        throw runtime_error("Out of Memory");
    }
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
}

List::~List(){
    Node* initial = sentinel_head;
    while(initial != nullptr){
        Node* temp = initial;
        initial = initial->next;
        delete[] temp;
    }
}

void List::insert(int v){
    Node* fix = new Node(v, sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next = fix;
    sentinel_tail->prev = fix;
    size++;
}

int List::delete_tail(){
    Node* temp = sentinel_tail->prev;
    int ans = temp->get_value();
    sentinel_tail->prev = temp->prev;
    temp->prev->next = sentinel_tail;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete[] temp;
    size--;
    return ans;
}

int List::get_size(){
    return size;
}

Node* List::get_head(){
    return this->sentinel_head;
}