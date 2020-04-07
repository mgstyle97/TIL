#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void insertion_sort()
{
    int i, j = 0, key = 0;

    for(i = 1; i < MAX_SIZE; i++){
        key = list[i];
        for(j = i-1; j >= 0 && list[j] > key; j--)
            list[j+1] = list[j];
        list[j+1] = key;
    }
}

int main()
{
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    insertion_sort();
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}