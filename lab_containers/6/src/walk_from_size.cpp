#include <iostream>
#include <fstream>
#include <vector>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include <chrono>

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e3;
}

template <typename T>
void walk(T& cont)
{
    for (auto c : cont)
    {
        c += 1;
    }
}

void walk(std::map<int, int>& cont){
    for(unsigned int i = 0; i < cont.size(); i++)
    {
        cont[i] += 1;
    }
}


int main()
{
    std::vector<int> v;
    std::forward_list<int> fl;
    std::list<int> l;
    std::set<int> s;
    std::map<int, int> m;

    std::ofstream f1("vector_size.csv", std::ios::out);
    std::ofstream f2("vector_time.csv", std::ios::out);

    std::ofstream g1("forward_list_size.csv", std::ios::out);
    std::ofstream g2("forward_list_time.csv", std::ios::out);

    std::ofstream u1("list_size.csv", std::ios::out);
    std::ofstream u2("list_time.csv", std::ios::out);

    std::ofstream h1("set_size.csv", std::ios::out);
    std::ofstream h2("set_time.csv", std::ios::out);

    std::ofstream v1("map_size.csv", std::ios::out);
    std::ofstream v2("map_time.csv", std::ios::out);

    // Задаём количество элементов
    int n = 100000;

    // Заполняем вектор
    for (int j = 100; j <= n; j += 100)
    {
        for (int i = 0; i < j; i++)
        {
            v.push_back(i);
            fl.push_front(i);
            l.push_front(i);
            s.insert(i);
            m.insert({i, i});
        }
        f1 << v.size() << std::endl;
        g1 << j << std::endl;
        u1 << j << std::endl;
        h1 << s.size() << std::endl;
        v1 << m.size() << std::endl;

        double start;

        //subset
        start = get_time();
        walk(v);
        f2 << get_time() - start << std::endl;

        //set
        start = get_time();
        walk(fl);
        g2 << get_time() - start << std::endl;

        //map
        start = get_time();
        walk(l);
        u2 << get_time() - start << std::endl;

        //multiset
        start = get_time();
        walk(s);
        h2 << get_time() - start << std::endl;

        //multimap
        start = get_time();
        walk(m);
        v2 << get_time() - start << std::endl;

        //Clearing
        v.clear();
        fl.clear();
        l.clear();
        s.clear();
        m.clear();
    }
    return 0;
}

