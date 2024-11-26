#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
const int WIDTH = 100;
const int HEIGHT = 100;
const int CENTER_ON_X = WIDTH / 2;
const int CENTER_ON_Y = HEIGHT / 2;
const int MAX_OF_X = WIDTH - CENTER_ON_X - 1;
const int MIN_OF_X = -(WIDTH - CENTER_ON_X);
const int MAX_OF_Y = HEIGHT - CENTER_ON_Y;
const int  MIN_OF_Y = -(HEIGHT - CENTER_ON_Y) + 1;
char coordPlane[HEIGHT][WIDTH];
void symbolOfGraphic(int x, int y, char symbol);
void fillArray();
void putArray();
void main()
{

    setlocale(LC_ALL, "ru");
    float x, y;
    int answer = 0;
    char symbols[5];
    cout << "Использовать сетку?(Введите 1 для да и 2 для нет)\nВаш выбор: ";
    cin >> answer;
    switch (answer) {
    case 1:
        int x, y;
        for (y = 0; y < HEIGHT; y++) {
            for (x = 0; x < WIDTH; x++) {
                if (x % 2 == 0) {
                    coordPlane[y][x] = '!';
                }
                else {
                    coordPlane[y][x] = '-';
                }
            }
        }
        break;
    case 2:
        for (y = 0; y < HEIGHT; y++) {
            for (x = 0; x < WIDTH; x++) {
                if (x % 2 == 0) {
                    coordPlane[y][x] = ' ';
                }
                else {
                    coordPlane[y][x] = ' ';
                }
            }
        }
        break;
    default:
        cout << "\nНеверное значение! Минус баллы. Удачи!";
        return;
    }
    cout << "\nЖелаете ввести произвольные символы для разных графиков? (по умолчанию для каждого графика будет установлен символ *). Введите 1 для да и 2 для нет \nВаш выбор: ";
    cin >> answer;
    switch (answer) {
    case 1:
        cout << "Введите последовательность из 5 символов (один символ для одного графика): ";
        for (int i = 0; i < 5; i++) {
            cin >> symbols[i];
        }
        break;
    case 2:
        for (int i = 0; i < 5; i++) {
            symbols[i] = '*';
        }
        break;
    default:
        cout << "\nНеверное значение! Минус баллы. Удачи!";
        return;
    }
    cout << "\nГрафики функций: (размер координатной плоскости равен " << HEIGHT << " x " << WIDTH << " )\n";
    fillArray();
    int indexOfSymbols = 0;
    //график функции |x|
    for (x = -(2 * acos(0.0)); x <= 2 * acos(0.0); x += 0.1)
    {
        y = abs(x);
        symbolOfGraphic(rintf(x * 10), rintf(y * 8), symbols[indexOfSymbols]);
    }
    indexOfSymbols++;
    //графмк функции x^2 
    for (x = -(2 * acos(0.0)); x <= 2 * acos(0.0); x += 0.1)
    {
        y = -x * x;
        symbolOfGraphic(rintf(x * 10), rintf(y * 8), symbols[indexOfSymbols]);
    }
    indexOfSymbols++;
    //график функции корня из x
    for (x = -(2 * acos(0.0)); x <= 2 * acos(0.0); x += 0.1)
    {
        y = sqrt(x);
        symbolOfGraphic(rintf(x * 10), rintf(y * 8), symbols[indexOfSymbols]);
    }
    indexOfSymbols++;
    //график функции sin(x)
    for (x = -(2 * acos(0.0)); x <= 2 * acos(0.0); x += 0.1)
    {
        y = sin(x);
        symbolOfGraphic(rintf(x * 10), rintf(y * 8), symbols[indexOfSymbols]);
    }
    indexOfSymbols++;
    //график функции cos(x)
    for (x = -(2 * acos(0.0)); x <= 2 * acos(0.0); x += 0.1)
    {
        y = cos(x);
        symbolOfGraphic(rintf(x * 10), rintf(y * 8), symbols[indexOfSymbols]);
    }
    putArray();
    return;
}
void symbolOfGraphic(int x, int y, char symbol)
{
    if (x > MAX_OF_X || x < MIN_OF_X || y > MAX_OF_Y || y < MIN_OF_Y) {
        return;
    }
    coordPlane[CENTER_ON_Y - y][CENTER_ON_X + x] = symbol;
}
void fillArray()
{
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        if (y == 0) {
            coordPlane[0][CENTER_ON_X - 1] = 'y';
            coordPlane[0][CENTER_ON_X] = '^';
            continue;
        }
        coordPlane[y][CENTER_ON_X] = '|';
    }
    for (x = 0; x < WIDTH; x++) {
        if (x == WIDTH - 1) {
            coordPlane[CENTER_ON_Y - 1][x] = 'x';
            coordPlane[CENTER_ON_Y][x] = '>';
            continue;
        }
        coordPlane[CENTER_ON_Y][x] = '—';
    }
    coordPlane[CENTER_ON_Y][CENTER_ON_X] = '+';
}
void putArray() {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++) {
            cout << coordPlane[i][j];
        }
        cout << endl;
    }
}