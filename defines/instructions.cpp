#include "instruction.h"
#include "../memory/Memory.h"
#pragma once

class IConst : Instruction {
public:
    IConst() = default;

    byte reserve_static() override {
        return sizeof(int32_t);
    }

    byte reserve_dynamic(byte *static_args) override {
        return 0;
    }

    void run(byte *static_args, byte *dynamic_args) override {
        auto* value = (int32_t*)static_args;
        Memory::push_to_stack(new IntVariable(*value));
    }
};

class SConst : Instruction{
    SConst() = default;

    byte reserve_static() override {
        return sizeof(int16_t);
    }

    byte reserve_dynamic(byte *static_args) override {
        return 0;
    }

    void run(byte *static_args, byte *dynamic_args) override {
        auto* value = (int16_t *)static_args;
        Memory::push_to_stack(new ShortVariable(*value));
    }
};

class StringConst : Instruction{
    StringConst() = default;

    byte reserve_static() override {
        return sizeof(int8_t);
    }

    byte reserve_dynamic(byte *static_args) override {
        return *((byte*)static_args);
    }

    void run(byte *static_args, byte *dynamic_args) override {
        Memory::push_to_stack(new StringVariable(
                *((std::string*)dynamic_args)
                ));
    }
};

class ILoad : Instruction{

    byte reserve_static() override {
        return sizeof(int32_t);
    }

    byte reserve_dynamic(byte *static_args) override {
        return 0;
    }

public:
    ILoad() = default;

    void run(byte *static_args, byte *dynamic_args) override {
        Memory::load_from_stack_to_heap(*(int32_t*)static_args);
    }
};


