#include <stdio.h>

int array[10] = {9, 5, 8, 3, 7};

int seq_search2(int key, int low, int high)
{
    int i;
    array[high+1] = key;
    for(i = low; array[i] != key; i++)
        ;
    if(i == (high+1))
        return -1;
    return i;
}

int main()
{
    int n;

    for(int i = 0; i < 2; i++){
        scanf("%d", &n);
        if(seq_search2(n, 0, 4) != -1)
            printf("Success!\n");
        else
            printf("Failed\n");
    }
}

