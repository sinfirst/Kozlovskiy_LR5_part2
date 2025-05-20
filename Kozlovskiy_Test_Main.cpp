#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

// Подключение модуля с тестируемыми методами
#include "Kozlovskiy_Main.h"

using namespace cute;

void testfirstTask() {
    // Входные значения
    float a = 3.23;
    float b = 5.56;
    float c = 7.241;
    // Ожидаемый результат
    float expected = 15;

    // Получение значения с помощью тестируемого метода
    float actual = firstTask(a, b, c);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testsecondTask() {
    // Входные значения
    float a = 214.12;
    float b = 623.124;
    float c = 15.234;
    // Ожидаемый результат
    float expected = 0.682495;

    // Получение значения с помощью тестируемого метода
    float actual = secondTask(a, b, c);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Empty() {
    // Исходные данные
    string str = "";
    // Ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // Получение значения с помощью тестируемого метода
    bool actual = ValidateInputToFloat(str);
    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев нецифровых символов
void testUserInput_Letter() {
    // Исходные данные
    string str = "abc";
    // Ожидаемое значение
    bool expected = false;
    // Получение значения
    bool actual = ValidateInputToFloat(str);
    // Сравнение
    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев цифро-буквенных значений
void testUserInput_DigitLetterValue() {
    // Исходные данные
    string str = "123abc";
    // Ожидаемое значение
    bool expected = false;
    // Получение значения
    bool actual = ValidateInputToFloat(str);
    // Сравнение
    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий что проверка на символы не затрагивает точку
void testUserInput_DotCheck() {
    // Исходные данные
    string str = "14124.124";
    // Ожидаемое значение
    bool expected = true;
    // Получение значения
    bool actual = ValidateInputToFloat(str);
    // Сравнение
    ASSERT_EQUAL(expected, actual);
}

int main() {
    // Создаем тестовый набор
    suite s;
    // Добавляем тестовые функции в набор
    s.push_back(CUTE(testfirstTask));
    s.push_back(CUTE(testsecondTask));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_DigitLetterValue));
    s.push_back(CUTE(testUserInput_DotCheck));
    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "All UserInput Tests");
    return 0;
}