// #include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

struct ARGS {
    int a;
    int b;
};

DWORD WINAPI ThreadFunctionOne(LPVOID pArgs_)
{
    ARGS *pArgs = (ARGS*)pArgs_;

    int s = 0;
    while (pArgs->a <= pArgs->b) s += pArgs->b--;
    cout << "Сумма равна = " << s << endl;
    return 0;
}

DWORD WINAPI ThreadFunctionTwo(LPVOID pArgs_)
{
    ARGS *pArgs = (ARGS*)pArgs_;
    int p = 1;
    while (pArgs->a <= pArgs->b) p *= pArgs->b--;
    cout << "Произведение равно = " << p << endl;
    return 0;
}

int main()
{
    setlocale(0, "");
    int a, b;
    cout << "Введите нижнюю границу диапазона L: ";
    cin >> a;
    cout << "Введите верхнюю границу диапазона U: ";
    cin >> b;
    ARGS args = { a, b };  

    return 0; }