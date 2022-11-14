//
// Created by khlop on 01.11.2022.
//

#include <iostream>
#include "Memory.h"
#include "stdexcept"
#include "algorithm"


void Memory::init() {
    stack = new std::stack<Variable*>;
    memory = new std::vector<Variable*>();
}

void Memory::push_to_stack(Variable* ptr){
    stack->push(ptr);
}
Variable* Memory::get_from_stack(){
    return stack->top();
}
Variable* Memory::pop_from_stack(){
    Variable* var = stack->top();
    stack->pop();
    return var;
}


void Memory::add_to_heap(Variable* value){
    memory->push_back(value);
}
void Memory::load_from_heap_to_stack(int32_t heap) {
    if(memory->size() < heap + 1){
        throw std::invalid_argument("хуй");
    }
    push_to_stack(memory->at(heap));
}

void Memory::load_from_stack_to_heap(int32_t heap){
    if((memory->size() == heap + 1) || memory->empty()){
        memory->push_back(pop_from_stack());
        return;
    }
    if(memory->size() < heap + 1){
        throw std::invalid_argument("");
    }
    memory->at(heap) = pop_from_stack();
}


void Memory::read_all_stack() {
    while (!stack->empty()){
        Variable* var = stack->top();
        std::cout << var->get_value() << std::endl;
        stack->pop();
    }
}
void Memory::read_all_heap(){
    for (auto & i : *memory) {
        std::cout << i->get_value() << std::endl;
    }
}

