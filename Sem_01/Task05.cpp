#include <iostream>
using namespace std;

int main()
{
    int money;
    cin >> money;

    unsigned int hundred = money / 100;
    cout << hundred << "x100 lv" << endl;
    money = money % 100;

    unsigned int fifty = money / 50;
    cout << fifty << "x50 lv" << endl;
    money = money % 50;

    unsigned int twenty = money / 20;
    cout << twenty << "x20 lv" << endl;
    money = money % 20;

    unsigned int ten = money / 10;
    cout << ten << "x10 lv" << endl;
    money = money % 10;

    unsigned int five = money / 5;
    cout << five << "x5 lv" << endl;
    money = money % 5;

    unsigned int two = money / 2;
    cout << two << "x2 lv" << endl;
    money = money % 2;

    cout << money << "x1 lv" << endl;
}