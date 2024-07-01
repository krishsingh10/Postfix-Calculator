#include "stack_c.h"

#include <stdexcept>
#include <iostream>
using namespace std;

Stack_C::Stack_C()
{
    stk = new(nothrow) List();
     if(stk == nullptr){
        throw runtime_error("Out of Memory");
     }
}

Stack_C::~Stack_C()
{
    delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);
}

int Stack_C::pop()
{
    if (stk->get_size() == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        return stk->delete_tail();
    }
}

int Stack_C::get_element_from_top(int idx)
{
    if (idx < 0 || idx >= stk->get_size())
    {
        throw runtime_error("Index out of range");
    }
Node* temp = stk->get_head();
int count = 0;
while(count != (stk->get_size()-idx-1)){
    temp = temp->next;
    count++;
}
return temp->next->get_value();
}


int Stack_C::get_element_from_bottom(int idx)
{
    if (idx < 0 || idx >= stk->get_size())
    {
        throw runtime_error("Index out of range");
    }
    int count = 0;
    Node *temp = stk->get_head();
    while (count <= idx)
    {
        temp = temp->next;
        count++;
    }
        return temp->get_value();
}

void Stack_C::print_stack(bool top_or_bottom)
{
    Node *temp = stk->get_head()->next;
    if (top_or_bottom)
    {
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            cout << temp->get_value() << endl;
            temp = temp->prev;
        }
    }
    else
    {
        while (temp != nullptr)
        {
            cout << temp->get_value() << endl;
            temp = temp->next;
        }
    }
}

int Stack_C::add()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int num1 = pop();
        int num2 = pop();
        int sum = num2 + num1;
        push(sum);
        return sum;
    }
}

int Stack_C::subtract()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int num1 = pop();
        int num2 = pop();
        int diff = num2 - num1;
        push(diff);
        return diff;
    }
}

int Stack_C::multiply()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int num1 = pop();
        int num2 = pop();
        int multy = num1 * num2;
        push(multy);
        return multy;
    }
}

int Stack_C::divide()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int num1 = pop();
    int num2 = pop();
    if (num1 == 0)
    {
        throw runtime_error("Divide by Zero Error");
    }
    if (num1 * num2 >= 0)
    {
        int devide = num2 / num1;
        push(devide);
        return devide;
    }
    else
    {
        int devide = -((-num2) / num1) - 1;
        push(devide);
        return devide;
    }
}

List *Stack_C::get_stack()
{
    return stk;
}

int Stack_C::get_size()
{
    return stk->get_size();
}


