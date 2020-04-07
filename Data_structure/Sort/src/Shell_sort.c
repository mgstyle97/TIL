#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int list[MAX_SIZE];

void inc_insertion_sort(int first, int last, int gap)
{
    int i, j, key;
    for(i = first+gap; i <= last; i += gap){
        key = list[i];
        for(j = i-gap; j >=first && list[j] > key; j -= gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

void shell_sort()
{
    int gap;
    for(gap = MAX_SIZE/2; gap > 0; gap /= 2){
        if(gap%2 == 0)
            gap++;
        for(int i = 0; i < gap; i++)
            inc_insertion_sort(i, MAX_SIZE-1, gap);
    }
}

int main()
{
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    shell_sort();
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}