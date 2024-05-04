#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono>
#include "subvector.h"

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e3;
}


int main()
{
    // Создаём сабвектор
    subvector v1;
    std::vector<int> v2;

    std::ofstream f1("subvector_size.csv", std::ios::out);
    std::ofstream f2("subvector_time.csv", std::ios::out);

    std::ofstream g1("standard_vector_size.csv", std::ios::out);
    std::ofstream g2("standard_vector_time.csv", std::ios::out);

    //checking of correct work
/*    int n = 10;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i);
    }
    v1.erase(5);
    for(int i = 0; i < v1.top; i++)
        std::cout << v1.mas[i] << " ";
    std::cout << std::endl;
    v2.erase(v2.begin() + 5);
    for(int i = 0; i < v1.top; i++)
        std::cout << v1.mas[i] << " ";
*/
    // Задаём количество элементов
    int n = 10000;

    // Заполняем вектор
    for (int j = 100; j <= n; j += 100)
    {
        for (int i = 0; i < j; i++)
        {
            v1.push_back(i);
            v2.push_back(i);
        }
        f1 << j << std::endl;
        g1 << j << std::endl;
        auto it = v2.begin() + v2.size() / 2;
        double start;
        start = get_time();
        v1.erase(v1.top / 2);
        f2 << get_time() - start << std::endl;
        start = get_time();
        v2.erase(it);
        g2 << get_time() - start << std::endl;
    }

    return 0;
}
