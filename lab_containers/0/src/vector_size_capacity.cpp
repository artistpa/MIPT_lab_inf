#include <iostream>
#include <fstream>
#include <vector>
#define c vector

using namespace std;

int main()
{
    // Создаём вектор
    c<int> v;

    ofstream f1("size_without_reserve.csv", ios::out);
    ofstream f2("capacity_without_reserve.csv", ios::out);

    // Задаём количество элементов
    int n;
    cin >> n;

    // Если сделать resize сразу на нужный размер, то всё будет хорошо.
    // Но сначала стоит посмотреть поведение без reserve-а.
    //v.reserve(n);

    cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;

    // Заполняем вектор
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
        f1 << v.size() << endl;
        f2 << v.capacity() << endl;
    }

    return 0;
}
