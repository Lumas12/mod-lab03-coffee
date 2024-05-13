// Copyright 2022 UNN-IASR

#pragma once
#include <iostream>
#include <array>
#include <string>
#include <stdexcept>

class Automata {
 public:
    Automata();

 public:
    void on();
    void off();
    void coin(const int);
    void getMenu();
    int getState();
    void choice(const int);
    void check();
    void cancel();
    void cook();
    void finish();    

 private:
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };

 private:
    size_t Choice;
    double Cash;
    std::array<std::string, 10> Menu;
    std::array<int, 10> Prices;
    STATES State;
};
