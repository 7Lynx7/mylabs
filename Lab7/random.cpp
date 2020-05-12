#include <stdlib.h>
#include <time.h>


//инициализация рандома
void sRand()
{
    srand(time(NULL));
}


//фунцкия перевода рандомного Int в float для максимального значения в 0.5
float randF() {
    float r = (float) rand();
    r = r / RAND_MAX * 0.5;
    return r;
}

//функция для вывода нормализированных  (по Гауссу) чисел
float randG() {
    float r = 0;
    for (int i = 0; i < 30; i++) {
        r += randF();

    }
    return r / 30;
}
