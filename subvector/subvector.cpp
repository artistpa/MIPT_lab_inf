#include "subvector.h"
#define NULL nullptr

using namespace std;

subvector::subvector(){
    top = 0;
    capacity = 0;
    mas = NULL;
}

bool subvector::resize(unsigned int new_capacity){
    if (top <= new_capacity){
        int* new_a = new int[new_capacity];
        for (unsigned int i = 0; i < top; i++) {
            new_a[i] = mas[i];
        }
        delete[] mas;
        mas = new_a;
        capacity = new_capacity;
    }
    if (top > new_capacity){
        int* new_a = new int[new_capacity];
        for (unsigned int i = 0; i < new_capacity; i++) {
            new_a[i] = mas[i];
        }
        delete[] mas;
        mas = new_a;
        capacity = new_capacity;
    }
    return(true);
}

bool subvector::push_back(int d) {
    if(top + 1 > capacity)
        resize(top + 1);
    mas[top] = d;
    top = top + 1;
    return(true);
}
int subvector::pop_back(){
    if(top == 0) {
        return 0;
    }
    top = top - 1;
    return(mas[top]);
}

void subvector::shrink_to_fit(){
    int* new_a = new int[top];
    for (unsigned int i = 0; i < top; i++) {
        new_a[i] = mas[i];
    }
    delete[] mas;
    mas = new_a;
    capacity = top;
}

void subvector::clear(){
    top = 0;
}

subvector::~subvector(){
    delete[] mas;
    top = 0;
    capacity = 0;
    mas = NULL;
}

void subvector::insert(int value, int pos){
    //Некорректный запрос
    if (pos < 0 || pos > top) {
        return;
    }

    //Добавление элемента в конец
    push_back(value);

  //Перемещение элементов, начиная с конца и до указанной позиции
    for (int i = top - 1; i > pos; --i) {
        int temp;
        temp = mas[i];
        mas[i] = mas[i-1];
        mas[i-1] = temp;
    }
}
