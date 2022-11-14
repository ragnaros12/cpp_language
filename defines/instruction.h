#pragma once
#include "variables.h"

class Instruction{
public:
    virtual byte reserve_static() = 0;
    virtual byte reserve_dynamic(byte* static_args) = 0;
    virtual void run(byte* static_args, byte* dynamic_args) = 0;
};