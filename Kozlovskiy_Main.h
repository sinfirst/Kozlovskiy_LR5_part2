#ifndef KOZLOVSKIY_MATHTASK_H
#define KOZLOVSKIY_MATHTASK_H

#include <string>
#include <iostream>
#include <math.h>
using namespace std;

bool ValidateInputToMenu(string input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    try {
        int number = stoi(input);
        if (number < 0 || number > 5) return false;
    } catch (...) {
        return false;
    }
    return true;
}


bool ValidateInputToFloat(string input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isdigit(c)) {
            if (c != '.'){
                return false;
            } 
        }
    }
    try {
        stof(input);
    } catch (...) {
        return false;
    }
    return true;
}


float EnterNumber(string label) {
    string input;
    cout << label << ": ";
    getline(cin, input);
    while (!ValidateInputToFloat(input)) {
        cout << "Не валидный ввод!\n " << label << ": ";
        getline(cin, input);
    }
    return stof(input);
}

float inputX(){
    float value = EnterNumber("Введите число x");
    return value;
}
float inputY(){
    float value = EnterNumber("Введите число y");
    return value;
}

float inputZ(){
    float value = EnterNumber("Введите число z");
    return value;
}


int firstTask(float x, float y, float z){
    return (int) x + y + z;
}

float secondTask(float x, float y, float z){
    return sqrt(fabs(x)*fabs(y)*fabs(z)) - floor(sqrt(fabs(x)*fabs(y)*fabs(z)));
}

#endif