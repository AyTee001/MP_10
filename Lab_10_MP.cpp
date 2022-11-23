/* Лабораторна робота 10 "Створення лінійних програм. Розгалуження"
Мурадханян Парнак Тигранович 1-5 ФІТ
Варіант 14*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <cmath>
#include <Windows.h>

using namespace std;

void Ex_1_1() {

    /* Радіус Місяця 1740 км. Обчислити площу поверхні S=4πr^2 та об’єм планет V=4πr^3/3.*/

    setlocale(0, ".1251");
    int r = 1740;
    float s = 4 * M_PI * pow(r, 2);
    float v = (4 * M_PI * pow(r, 3)) / 3;
    cout << "Об'єм Місяця: " << v << endl;
    cout << "Площа поверхні Місяця: " << s << endl;

};

void Ex_1_2() {

    /* Обчислити об’єм та площу бічної поверхні куба, якщо відоме ребро.*/

    float x;
    cout << "Введіть значення ребра куба: ";
    cin >> x;

    float sqr = 6 * pow(x, 2);
    float ob = pow(x, 3);
    cout << "Об'єм куба: " << ob << endl;
    cout << "Площа бічної поверхні куба: " << sqr << endl;

};

void Ex_2() {

    /* Трикутник задано координатами вершин A(0;0),B(i;i-1),C(-i;i+1), де і – 14. Обчислити медіану  та радіус описаного кола.*/
    setlocale(0, ".1251");
    int a[2] = { 0, 0 };
    int b[2] = { 14, 13 };
    int c[2] = { -14, 15 };

    int ab[2] = { b[0] - a[0], b[1] - a[1] };
    int bc[2] = { c[0] - b[0], c[1] - b[1] };
    int ac[2] = { c[0] - a[0], c[1] - a[1] };

    float l_ab = sqrt(pow(ab[0], 2) + pow(ab[1], 2));
    float l_bc = sqrt(pow(bc[0], 2) + pow(bc[1], 2));
    float l_ac = sqrt(pow(ac[0], 2) + pow(ac[1], 2));

    float m_a = 0.5 * sqrt((2 * pow(l_ac, 2)) + (2 * pow(l_ab, 2)) - (pow(l_bc, 2))) / 2;
    cout << "Медіана: " << m_a << endl;

    float p = (l_ac + l_bc + l_ac) / 2;
    float s = sqrt(p * ((p - l_ab) * (p - l_bc) * (p - l_ac)));
    float r = (l_bc * l_ac * l_ab) / (4 * s);
    cout << "Радіус описаного кола: " << r << endl;

};

void Ex_3() {

    /* Написати програму, яка обчислює вирази за двома формулами. Попередньо
    підготуйте тестові приклади для другої формули з допомогою калькулятора (результати обчислення
    за двома формулами мають співпадати). Номер 14*/
    setlocale(0, ".1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    cout << "a: ";
    cin >> a;
    int z1 = (cos(a) + sin(a)) / (cos(a) - sin(a));
    int z2 = (tan(2 * a) + 1 / cos(2 * a));
    cout << "z1: " << z1 << endl;
    cout << "z2: " << z2 << endl;

    system("pause");
};

void Ex_4() {

    /* Скласти структурну схему алгоритму та програму обчислення значень функції y=F(x) відповідно до завдань, зазначених у таблиці.
    Примітка. Значення першого з двох параметрів, які наведені в таблиці, задати як константу, значення другого ввести з клавіатури.
    */
    setlocale(0, ".1251");
    const int x = 11;
    float p;
    cout << "p: ";
    cin >> p;

    float a = log10(fabs(x));
    cout << "a: " << a << endl;
    float b = x + pow(p, 3);
    cout << "b: " << b << endl;
    float y = (sqrt(x) * sin(a)) + (sqrt(b) * cos(x));
    cout << "y: " << y << endl;

};

void Ex_5() {

    /* Використовуючи відповідні компоненти створити додаток для розв’язування
    наступної задачі: знайти значення виразу  врахувавши область визначення.
    Облсть визначення є R*/
    setlocale(0, ".1251");
    float m;
    float y;
    cout << "Уведіть m: ";
    cin >> m;
    cout << "Уведіть y: ";
    cin >> y;
    float a = (pow(m, 2) + (2.8 * m) + 0.355) / (cos(2 * y) + 3.6);
    cout << "a :" << a << endl;
};

int main() {
    setlocale(0, ".1251");
    system("chcp 1251");
    int task_numb = 0;
    cout << "\a\a\a\n";
    cout << "Введіть номер завдання: ";
    cin >> task_numb;

    switch (task_numb) {
    case 1:
        cout << "\a\a\a\n";
        Ex_1_1();
        cout << "\n\n" << endl;
        Ex_1_2();
        break;

    case 2:
        cout << "\a\a\a\n";
        Ex_2();
        break;

    case 3:
        cout << "\a\a\a\n";
        Ex_3();
        break;

    case 4:
        cout << "\a\a\a\n";
        Ex_4();
        break;
    case 5:
        cout << "\a\a\a\n";
        Ex_5();
        break;
    default:
        cout << "\a\a\a\n";
        cout << "Завдання з таким номером не існує!!!!!" << endl;
        Beep(900, 7000);
        break;
    }
    return 0;
}