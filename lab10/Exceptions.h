#pragma once
#include <exception>
#include <iostream>
class InvalidIndex : public std::exception {
public:
    virtual const char* what() const override {
        return "Invalid Index: out of range";
    }
};