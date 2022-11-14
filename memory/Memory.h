//
// Created by khlop on 01.11.2022.
//

#ifndef LANG_MEMORY_H
#define LANG_MEMORY_H


#include <stack>
#include "../defines/variables.h"
#include "vector"

class Memory {
public:
    inline static std::stack<Variable*> *stack;
    inline static std::vector<Variable*>* memory;

    static void init();

    static void push_to_stack(Variable* ptr);
    static Variable* get_from_stack();
    static Variable* pop_from_stack();

    static void load_from_heap_to_stack(int heap);
    static void load_from_stack_to_heap(int32_t heap);


    static void add_to_heap(Variable* value);

    static void read_all_heap();
    static void read_all_stack();
};


#endif //LANG_MEMORY_H
