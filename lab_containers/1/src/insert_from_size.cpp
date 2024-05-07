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
    subvector v1;
    std::vector<int> v2;

    std::ofstream f1("subvector_size.csv", std::ios::out);
    std::ofstream f2("subvector_time.csv", std::ios::out);

    std::ofstream g1("standard_vector_size.csv", std::ios::out);
    std::ofstream g2("standard_vector_time.csv", std::ios::out);

    int n = 100000;

    for (int j = 0; j < n; j += 1000)
    {
        for (int i = 0; i < j; i++)
        {
            v1.push_back(i);
            v2.push_back(i);
        }
        f1 << v1.top << std::endl;
        g1 << v2.size() << std::endl;
        auto it = v2.begin() + j / 2;
        double start;
        start = get_time();
        v1.insert(10, j / 2);
        f2 << get_time() - start << std::endl;
        start = get_time();
        v2.insert(it, 10);
        g2 << get_time() - start << std::endl;
        v1.clear();
        v2.clear();
    }


    return 0;
}
