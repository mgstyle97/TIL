#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];

int partition(int left, int right)
{
    int low, high;
    int pivot, temp;

    low = left;
    high = right+1;
    pivot = list[left];

    do{
        do{
            low++;
        }while(list[low] < pivot);
        do{
            high--;
        }while(list[high] > pivot);
        if(low < high)
            SWAP(list[low], list[high], temp);
    }while(low < high);

    SWAP(list[left], list[high], temp);

    return high;
}

void quick_sort(int left, int right)
{
    if(left < right) {
        int q = partition(left, right);
        quick_sort(left, q-1);
        quick_sort(q+1, right);
    }
}

int main()
{
    srand(time(NULL));      // 균일하지 않은 난수 발생기
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    quick_sort(0, MAX_SIZE-1);
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}