#include <stdio.h>

int list[10] = {3, 9, 15, 22, 31, 55, 67, 88, 89, 91};

int interpol_search(int key, int n)
{
    int low, high, j;

    low = 0;
    high = n-1;
    while(key <= list[high] && key > list[low]){
        j = ((float)(key-list[low])/(list[high]-list[low])*(high-low))+low;
        if(key > list[j])
            low = j+1;
        else if(key < list[j])
            high = j-1;
        else
            low = j;
    }
    if(list[low] == key)
        return low;
    else
        return -1;
}

int main()
{
    int n;

    for(int i = 0; i < 2; i++){
        scanf("%d", &n);
        if(interpol_search(n, 10) != -1)
            printf("Success!\n");
        else
            printf("Failed\n");
    }
}