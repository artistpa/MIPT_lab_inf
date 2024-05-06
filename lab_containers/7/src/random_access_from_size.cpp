#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <chrono>
#include <random>
#include "subvector.h"

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count();
}

int random_access(std::vector<int> v, int i)
{
    return v[i];
}

int random_access(subvector sv, int i)
{
    return sv.mas[i];
}

int main()
{   // Creation subvector and vector
    subvector v1;
    std::vector<int> v2;

    std::ofstream f1("subvector_size.csv", std::ios::out);
    std::ofstream f2("subvector_time.csv", std::ios::out);

    std::ofstream g1("standard_vector_size.csv", std::ios::out);
    std::ofstream g2("standard_vector_time.csv", std::ios::out);

    int n = 100000;

    for (int j = 100; j < n; j += 100)
    {
        v2.reserve(j / 10 + 5);
        for (int i = 0; i < j; i += 10)
        {
            v1.push_back(i);
            v2.push_back(i);
        }

        f1 << v1.top << std::endl;
        g1 << v2.size() << std::endl;

        double sum1 = 0, sum2 = 0;
        double start;
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        std::uniform_int_distribution<> dist(1, v2.size() - 2); // distribute results between 1 and 6 inclusive.
        int num = dist(gen);

        for (int i = 0; i < 100000; i++)
        {
            start = get_time();
            random_access(v1, num);
            sum1 += get_time() - start;
            start = get_time();
            random_access(v2, num);
            sum2 += get_time() - start;
        }

        f2 << sum1 / 100000 << std::endl;
        g2 << sum2 / 100000 << std::endl;

        //Clearing
        v1.clear();
        v2.clear();
    }

    v1.destructor();

    return 0;
}
