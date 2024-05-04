#include <iostream>
#include <fstream>
#include <list>
#include <forward_list>
#include <chrono>
#include "subforwardlist.h"

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e3;
}


int main()
{
    // Создаём сабвектор
    subforwardlist *sfl;
    init(&sfl);

    std::list<int> l;
    std::forward_list<int> fl;

    std::ofstream f1("subforwardlist_size.csv", std::ios::out);
    std::ofstream f2("subforwardlist_time.csv", std::ios::out);

    std::ofstream g1("list_size.csv", std::ios::out);
    std::ofstream g2("list_time.csv", std::ios::out);

    std::ofstream u1("forward_list_size.csv", std::ios::out);
    std::ofstream u2("forward_list_time.csv", std::ios::out);

    // Задаём количество элементов
    int n = 100000;

    // Заполняем вектор
    for (int j = 100; j <= n; j += 100)
    {
        for (int i = 0; i < j; i++)
        {
            push_forward(&sfl, i);
            l.push_front(i);
            fl.push_front(i);
        }
        f1 << size(&sfl) << std::endl;
        g1 << l.size() << std::endl;
        u1 << j << std::endl;
        double start;
        start = get_time();
        pop_forward(&sfl);
        f2 << get_time() - start << std::endl;
        start = get_time();
        l.pop_front();
        g2 << get_time() - start << std::endl;
        start = get_time();
        fl.pop_front();
        u2 << get_time() - start << std::endl;
        clear(&sfl);
        l.clear();
        fl.clear();
    }
    return 0;
}
