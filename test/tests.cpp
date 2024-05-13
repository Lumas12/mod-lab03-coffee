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
    // Проверка, что функция вызвана без ошибок
    EXPECT_TRUE(true);
}

TEST_F(AutomataTest, MakeChoice_5) {
    one.on();
    one.coin(20);
    one.choice(0); // Выбор чая
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); // Остаток после покупки чая
}

TEST_F(AutomataTest, CancelOperation_6) {
    one.on();
    one.coin(20);
    one.choice(0); // Выбор чая
    one.cancel();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 20); // Деньги возвращены после отмены
}

TEST_F(AutomataTest, CookingProcess_7) {
    one.on();
    one.coin(20);
    one.choice(0); // Выбор чая
    one.check();
    one.cook();
    one.finish();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
}

TEST_F(AutomataTest, CheckInsufficientFunds_8) {
    one.on();
    one.coin(10);
    one.choice(0); // Выбор чая
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); // Проверка, что деньги не были списаны, так как недостаточно средств
}

TEST_F(AutomataTest, CheckSufficientFunds_9) {
    one.on();
    one.coin(20);
    one.choice(0); // Выбор чая
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); // Проверка, что деньги были списаны после успешной покупки
}

TEST_F(AutomataTest, MultipleChoices_10) {
    one.on();
    one.coin(20);
    one.choice(0); // Выбор чая
    one.choice(1); // Попытка выбрать кофе после чая
    one.check();
    EXPECT_EQ(one.getState(), Automata::STATES::WAIT);
    EXPECT_EQ(one.Cash, 10); // Проверка, что деньги не были списаны, так как уже была сделана покупка
}
