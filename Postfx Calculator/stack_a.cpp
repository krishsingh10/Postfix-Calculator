#include "stack_a.h" 
#include<iostream>
#include<stdexcept>
using namespace std;

Stack_A::Stack_A(){
 this->size = 0;
}

void Stack_A::push(int data){
    if(size>=1024){
      throw runtime_error("Stack Full");
    }
    else{
        this->stk[size] = data;
        size++;
    }

}

int Stack_A::pop(){
    if(size == 0){
        throw runtime_error("Empty Stack");
    }
    else{
        size--;
       int num = this->stk[size];
        return num;
    }
   
}

 int Stack_A:: get_element_from_top(int idx){
    if(idx<0 || idx>=1024){
        throw runtime_error("Index out of range");
    }
    else{
        int top = this->stk[size - idx -1];
        return top;
    }
 }

 int Stack_A:: get_element_from_bottom(int idx){
    if(idx<0 || idx>=1024){
        throw runtime_error("Index out of range");
    }
    else{
        int bottom = this->stk[idx];
        return bottom;
    }
 }

 void Stack_A:: print_stack(bool top_or_bottom){
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

    int Stack_A::add(){
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
    int Stack_A:: subtract(){
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
     int Stack_A::multiply(){
         if(size<2){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            int num1 = this->pop();
            int num2 = this->pop();
            int mult = num1*num2;
            this->push(mult);
            return mult;
        }
     }
    int Stack_A:: divide(){
          if(size<2){
            throw runtime_error("Not Enough Arguments");
        }
         int num1 = this->pop();
         int num2 = this->pop();
        if(num1 == 0){
            throw runtime_error("Divide by Zero Error");
        }
        if(num1*num2>=0){
            int devide = num2/num1;
            this->push(devide);
            return devide;
        }
        else{
            int devide = -((-num2)/num1)-1;
            this->push(devide);
            return devide;
        }
    } 
    int* Stack_A::get_stack(){
        return this->stk;
    }
    int Stack_A::get_size(){
        return this->size;
    }


    



