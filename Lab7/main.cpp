#include <iostream>
#include "random.h"


int main()
{
    sRand();//инициализация рандома
    float count[5] = { 0 };
    for (int i = 0; i < 500000; i++) {
        int a = (int)(randF() * 10); // число а - индекс диапазона
        count[a != 5 ? a : 4]++; //проверка на выход за пределы массива и подсчет

    }
    for (int i = 0; i < 5; i++) {
        std::cout << count[i] / 500000 << std::endl;
    }
    return 0;

}

