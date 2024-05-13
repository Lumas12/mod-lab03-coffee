// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST1(AutomataTest, InitialState) {
    Automata automata;
    EXPECT_EQ(automata.getState(), Automata::STATES::OFF);
    EXPECT_EQ(automata.Cash, 0);
}

TEST2(AutomataTest, TurnOnAndOff) {
    Automata automata;
    automata.on();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
    automata.off();
    EXPECT_EQ(automata.getState(), Automata::STATES::OFF);
}

TEST3(AutomataTest, InsertCoin) {
    Automata automata;
    automata.on();
    automata.coin(10);
    EXPECT_EQ(automata.getState(), Automata::STATES::ACCEPT);
    EXPECT_EQ(automata.Cash, 10);
}

TEST4(AutomataTest, DisplayMenu) {
    Automata automata;
    automata.on();
    automata.getMenu();
    EXPECT_TRUE(true);
}

TEST5(AutomataTest, MakeChoice) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(0); 
    automata.check();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(automata.Cash, 10); 
}

TEST6(AutomataTest, CancelOperation) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(0); 
    automata.cancel();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(automata.Cash, 20); 
}

TEST7(AutomataTest, CookingProcess) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(0); 
    automata.check();
    automata.cook();
    automata.finish();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
}

TEST8(AutomataTest, CheckInsufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.choice(0); 
    automata.check();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(automata.Cash, 10); 
}

TEST9(AutomataTest, CheckSufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(0); 
    automata.check();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(automata.Cash, 10); 
}

TEST10(AutomataTest, MultipleChoices) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(0); 
    automata.choice(1); 
    automata.check();
    EXPECT_EQ(automata.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(automata.Cash, 10); 
}

