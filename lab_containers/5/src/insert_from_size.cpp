#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <chrono>
#include <random>
#include "subset.h"

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e3;
}


int main()
{
    // Creation subset
    subset_node *sn;
    init(&sn);

    std::set<int> s;
    std::map<int, int> m;
    std::multiset<int> ms;
    std::multimap<int, int> mm;

    std::ofstream f1("subset_size.csv", std::ios::out);
    std::ofstream f2("subset_time.csv", std::ios::out);

    std::ofstream g1("set_size.csv", std::ios::out);
    std::ofstream g2("set_time.csv", std::ios::out);

    std::ofstream u1("map_size.csv", std::ios::out);
    std::ofstream u2("map_time.csv", std::ios::out);

    std::ofstream h1("multiset_size.csv", std::ios::out);
    std::ofstream h2("multiset_time.csv", std::ios::out);

    std::ofstream v1("multimap_size.csv", std::ios::out);
    std::ofstream v2("multimap_time.csv", std::ios::out);

    int n = 100000;

    for (int j = 100; j <= n; j += 100)
    {
        for (int i = 0; i < j; i += 10)
        {
            insert(&sn, i);
            s.insert(i);
            m.insert({i, i});
            ms.insert(i);
            mm.insert({i, i});
        }
        f1 << size(sn) << std::endl;
        g1 << s.size() << std::endl;
        u1 << m.size() << std::endl;
        h1 << ms.size() << std::endl;
        v1 << mm.size() << std::endl;

        double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
        double start;
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        std::uniform_int_distribution<> dist(51, 54); // distribute results between 1 and 6 inclusive.
        int num = dist(gen);

        for (int i = 0; i < 1000; i++)
        {
            start = get_time();
            insert(&sn, num);
            sum1 += get_time() - start;
            start = get_time();
            s.insert(num);
            sum2 += get_time() - start;
            start = get_time();
            m.insert({num, num});
            sum3 += get_time() - start;
            start = get_time();
            ms.insert(num);
            sum4 += get_time() - start;
            start = get_time();
            mm.insert({num, num});
            sum5 += get_time() - start;
        }

            f2 << sum1 / 1000 << std::endl;

            //set

            g2 << sum2 / 1000 << std::endl;

            //map

            u2 << sum3 / 1000 << std::endl;

            //multiset

            h2 << sum4 / 1000 << std::endl;

            //multimap

            v2 << sum5 / 1000 << std::endl;

        //Clearing
        destructor(&sn);
        s.clear();
        m.clear();
        ms.clear();
        mm.clear();
    }
    return 0;
}

