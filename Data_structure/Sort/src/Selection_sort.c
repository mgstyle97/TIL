#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
    int least, temp;
    for(int i  = 0; i < n-1; i++){
        least = i;
        for(int j = i+1; j < n; j++)
            if(list[j] < list[least])
                least = j;
        if(i != least)
            SWAP(list[i], list[least], temp);
    }
}

int main()
{
    n = MAX_SIZE;
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    selection_sort(list, n);
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}

