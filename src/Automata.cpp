//Copyright 2022 UNN-IASR

#include "../include/Automata.h"

Automata::Automata() {
    Cash = 0;
    Menu = {
        "Чай",
        "Кофе",
        "Молоко"
    };
    Prices = { 10, 20, 30 };
    State = STATES::OFF;
}

void Automata::on() {
    if (State == STATES::OFF) {
        State = STATES::WAIT;
    }
    getMenu();
}

void Automata::off() {
    if (State == STATES::WAIT) {
        State = STATES::OFF;
    }
}

void Automata::coin(const int Coin) {
    if (State == STATES::WAIT) {
        State = STATES::ACCEPT;
        Cash += Coin;
    }
}

void Automata::getMenu() {
    for (int i = 0; i < Menu.size(); i++) {
        std::cout << Menu[i] << " " << Prices[i] << std::endl;
    }
}

int Automata::getState() {
    return State;
}

void Automata::choice(const int Choice) {
    if (State == STATES::ACCEPT) {
        State = STATES::CHECK;
    }
}

void Automata::check() {
    if (State == STATES::CHECK) {
        if (Cash >= Prices.at(Choice)) {
            std::cout << "Достаточно денег" << std::endl;
            Cash -= Prices.at(Choice);
        } else {
            std::cout << "Не достаточно денег" << std::endl;
        }
    }
}

void Automata::cancel() {
    if (State == STATES::ACCEPT || State == STATES::CHECK) {
        State = STATES::WAIT;
        Cash = 0;
    }
}

void Automata::cook() {
    if (State == STATES::CHECK) {
        State = STATES::COOK;
    }
}

void Automata::finish() {
    if (State == STATES::COOK) {
        State = STATES::WAIT;
    }
}
