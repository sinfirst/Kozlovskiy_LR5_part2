#include <iostream>
#include "Kozlovskiy_Main.h"

using namespace std;

int main(){
    string input;
    int vibor;
    float x, y, z;
    while(true)
    {
        cout<<"Выберите действие\n";
        cout<<"№1 Введение числа x\n";
        cout<<"№2 Введение числа y\n";
        cout<<"№3 Введение числа z\n";
        cout<<"№4 Целая часть суммы 3-х чисел\n";
        cout<<"№5 Дрбная часть среднего геометрического модулей 3-х чисел\n";
        cout<<"Введите 0 чтобы завершить выполнение программы\n";
        getline(cin, input);
        while (!ValidateInputToMenu(input)) {
            cout << "Не валидный ввод!";
            getline(cin, input);
        }
        vibor = stoi(input);
        switch(vibor){
        case 1:
            x = inputX();
            break;
        case 2:
            y = inputY();
            break;
        case 3:
            z = inputZ();
            break;
        case 4:
            cout<<firstTask(x, y, z)<<endl;
            break;
        case 5:
            cout<<secondTask(x, y, z)<<endl;
            break;
        case 0:
            return 0;
        };
    }
    return 0;
}