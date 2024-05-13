#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public ::testing::Test {
protected:
    Automata one;
};

TEST_F(AutomataTest, InitialState_1) {
    EXPECT_EQ(one.getState(), Automata::STATES::OFF);
    EXPECT_EQ(one.Cash, 0);
}

TEST_F(AutomataTest, TurnOnAndOff_2) {
    one.on();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    one.off();
    EXPECT_EQ(one.getState(), Automata::STATES::OFF);
}

TEST_F(AutomataTest, InsertCoin_3) {
    one.on();
    one.coin(10);
    EXPECT_EQ(one.getState(), Automata::STATES::ACCEPT);
    EXPECT_EQ(one.Cash, 10);
}

TEST_F(AutomataTest, DisplayMenu_4) {
    one.on();
    one.getMenu();
    EXPECT_TRUE(true);
}

TEST_F(AutomataTest, MakeChoice_5) {
    one.on();
    one.coin(20);
    one.choice(0); 
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::CHECK);
    EXPECT_EQ(one.Cash, 10); 
}

TEST_F(AutomataTest, CancelOperation_6) {
    one.on();
    one.coin(20);
    one.choice(0); 
    one.cancel();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 0); 
}

TEST_F(AutomataTest, CookingProcess_7) {
    one.on();
    one.coin(20);
    one.choice(0); 
    one.check();
    one.cook();
    one.finish();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
}

TEST_F(AutomataTest, CheckInsufficientFunds_8) {
    one.on();
    one.coin(10);
    one.choice(0); 
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); 
}

TEST_F(AutomataTest, CheckSufficientFunds_9) {
    one.on();
    one.coin(20);
    one.choice(0); 
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); 
}

TEST_F(AutomataTest, MultipleChoices_10) {
    one.on();
    one.coin(20);
    one.choice(0); 
    one.choice(1); 
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); 
}
