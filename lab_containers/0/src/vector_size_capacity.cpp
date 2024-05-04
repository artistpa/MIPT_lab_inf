#include <iostream>
#include <fstream>
#include <vector>
#define c vector

using namespace std;

int main()
{
    // ������ ������
    c<int> v;

    ofstream f1("size_without_reserve.csv", ios::out);
    ofstream f2("capacity_without_reserve.csv", ios::out);

    // ����� ���������� ���������
    int n;
    cin >> n;

    // ���� ������� resize ����� �� ������ ������, �� �� ����� ������.
    // �� ������� ����� ���������� ��������� ��� reserve-�.
    //v.reserve(n);

    cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;

    // ��������� ������
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
        f1 << v.size() << endl;
        f2 << v.capacity() << endl;
    }

    return 0;
}
