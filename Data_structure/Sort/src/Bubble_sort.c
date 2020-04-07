#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];

void bubble_sort()
{
    int tmp;

    for(int i = MAX_SIZE-1; i > 0; i--)
        for(int j = 0; j < i-1; j++)
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], tmp);
}

int main()
{
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    bubble_sort();
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}