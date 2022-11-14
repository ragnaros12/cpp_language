#pragma once

#include <cstdint>
#include <string>
#include <utility>

typedef unsigned char byte;

#pragma pack(push, 1)
class Variable{
public:
    virtual std::string get_value() = 0;
};

class IntVariable : public Variable{
public:
    int32_t value;

    explicit IntVariable(int32_t value){
        this->value = value;
    }

    std::string get_value() override{
        return std::to_string(value);
    }
};
class ShortVariable : public Variable{
public:
    int16_t value;

    explicit ShortVariable( int16_t value){
        this->value = value;
    }
     std::string get_value() override{
        return std::to_string(value);
    }
};

class StringVariable : public Variable{
public:
    std::string value;

    explicit StringVariable(std::string value){
            this->value = std::move(value);
    }

    std::string get_value() override{
        return value;
    }
};

#pragma pack(pop)
