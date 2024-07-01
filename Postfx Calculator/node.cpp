#include "node.h"
#include<iostream>
#include<stdexcept>
using namespace std;

Node::Node(bool sentinel){
 this->is_sentinel = sentinel;
 this->next = nullptr;
 this->prev = nullptr;
}
 Node::Node(int v, Node* nxt, Node* prv){
    this->value = v;
    this->is_sentinel = false;
    this->next = nxt;
    this->prev = prv;
 }
 bool Node::is_sentinel_node(){
    return this->is_sentinel;
 }
 
int Node::get_value() {
    return this->value;
}