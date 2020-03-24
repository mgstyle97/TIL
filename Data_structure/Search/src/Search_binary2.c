#include <stdio.h>
#include <stdlib.h>

int array[10] = {1, 3, 5, 6, 7, 9, 11, 20, 30};

int search_binary(int key, int low, int high)
{
    int middle;

    while(low <= high){
        middle = (low + high) / 2;
        if(key == array[middle])
            return middle;
        else if(key < array[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int main()
{
    int n;

    for(int i = 0; i < 2; i++){
        scanf("%d", &n);
        if(search_binary(n, 0, 8) != -1)
            printf("Success!\n");
        else
            printf("Failed\n");
    }
}