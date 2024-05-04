#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <chrono>
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

    // Задаём количество элементов
    int n = 100000;

    // Заполняем вектор
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

        double start;

        //subset
        start = get_time();
        insert(&sn, j/3 + 3);
        f2 << get_time() - start << std::endl;

        //set
        start = get_time();
        s.insert(j/3 + 3);
        g2 << get_time() - start << std::endl;

        //map
        start = get_time();
        m.insert({j/3 + 3, j/3 + 17});
        u2 << get_time() - start << std::endl;

        //multiset
        start = get_time();
        ms.insert(j/3 + 3);
        h2 << get_time() - start << std::endl;

        //multimap
        start = get_time();
        mm.insert({j/3 + 3, j/3 + 17});
        v2 << get_time() - start << std::endl;

        //Clearing
        destructor(&sn);
        s.clear();
        m.clear();
        ms.clear();
        mm.clear();
    }
    return 0;
}

