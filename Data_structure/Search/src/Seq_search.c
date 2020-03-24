#include <stdio.h>
#include <stdlib.h>

int array[5] = {9, 5, 8, 3, 7};

int seq_search(int key, int low, int high)
{
    int i;

    for(i = low; i <= high; i++){
        if(key == array[i])
            return i;
    }
    return -1;
}

int main()
{
    int n;

    for(int i = 0; i < 2; i++){
        scanf("%d", &n);
        if(seq_search(n, 0, 4) != -1)
            printf("Success!\n");
        else
            printf("Failed\n");
    }
}

