#include "stack_b.h" 
#include<iostream>
#include<stdexcept>
using namespace std;

Stack_B::Stack_B(){
    this->capacity = 1024;
    stk = new (nothrow) int[capacity]; 
    this->size = 0;
    if (this->stk == nullptr) {
        throw runtime_error("Out of Memory");
    }
}

Stack_B::~Stack_B() {
    delete[] stk;
}

void Stack_B::push(int data){
    if(size >=capacity ){
        int changecapacity =capacity*2;
       int* changestk = new(nothrow) int[changecapacity];
      if(changestk == nullptr){
        throw runtime_error("Out of Memory");
      }
       for(int i = 0; i<size; i++){
        changestk[i] = this->stk[i];
       }

       delete[] stk;
       stk = changestk;
       this->capacity = changecapacity;
    }
      this->stk[size] = data;
      size++;
}


int Stack_B::pop() {
    if (size == 0) {
        throw runtime_error("Empty Stack");
    }
    
    if (size < 1024 && capacity > 1024) {
        int changecapacity = max(this->capacity / 2, 1024);
        int* newstk = new (std::nothrow) int[changecapacity];
        if (newstk == nullptr) {
            throw runtime_error("Out of Memory");
        }
        else {
            for (int i = 0; i < this->size; i++) {
                newstk[i] = this->stk[i];
            }
            delete[] this->stk;
            this->stk = newstk;
            this->capacity = changecapacity;
        }
    }
    
    size--;
    int value = this->stk[size];
    return value;
}


int Stack_B::get_element_from_top(int idx){
    if(idx<0 || idx>=size){
        throw runtime_error("Index out of range");
    }
    else{
        int top = this->stk[size - idx - 1];
        return top;
    }
}

int Stack_B::get_element_from_bottom(int idx){
    if(idx<0 || idx>=size){
        throw runtime_error("Index out of range");
    }
    else{
        int bottom = this->stk[idx];
        return bottom;
    }
}

void Stack_B::print_stack(bool top_or_bottom){
    if(top_or_bottom){
        for(int i = size -1; i>=0; i--){
            cout<<this->stk[i]<<endl;
        }
    }
    else{
        for(int i = 0; i<size; i++){
            cout<<this->stk[i]<<endl;
        }
    }
}
int Stack_B::add(){
    if(size<2){
        throw runtime_error("Not Enough Arguments");
    }
    else{
    int num1 = this->pop();
    int num2 = this->pop();
    int sum = num1 + num2;
    this->push(sum);
    return sum;
    }
}
 int Stack_B::subtract(){
    if(size<2){
        throw runtime_error("Not Enough Arguments");
    }
    else{
    int num1 = this->pop();
    int num2 = this->pop();
    int diff = num2 - num1;
    this->push(diff);
    return diff;
    }
 }

 int Stack_B::multiply(){
     if(size<2){
        throw runtime_error("Not Enough Arguments");
    }
    else{
    int num1 = this->pop();
    int num2 = this->pop();
    int multy = num1*num2;
    this->push(multy);
    return multy;
    }
 }
 int Stack_B::divide(){
     if(size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int num1 = this->pop();
    int num2 = this->pop();
    if(num1 == 0){
        throw runtime_error("Divide by Zero Error");
    }
    if(num1*num2>0){
        int devide = num2/num1;
        this->push(devide);
        return devide;
    }
    else{
        int devide = -((-num2)/num1) -1;
        this->push(devide);
        return devide;
    }
 }
 
    int* Stack_B::get_stack(){
        return this->stk;
    }
    int Stack_B::get_size(){
        return this->size;
    }



    