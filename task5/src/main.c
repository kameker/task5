#include "../include/deque.h"
#include <stdio.h>
// #include <omp.h>

int main()
{
    deque dq;
    int size = 100000000;
    make_deque(&dq, size);

    double start = omp_get_wtime();

#pragma omp parallel for

    for (int i = 0; i < size; i++)
    {
#pragma omp critical
        {
            add_last(&dq, i * i - 1);
        }
    }

    double end = omp_get_wtime();
    printf("Время выполнения: %f секунд\n", end - start);

    while (!is_empty(&dq))
    {
        rem_first(&dq);
    }

    return 0;
}