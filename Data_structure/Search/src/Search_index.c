#include <stdio.h>

#define INDEX_SIZE 256
typedef struct{
    int key;
    int index;
} itable;

int list[9] = {3, 9, 15, 22, 31, 55, 67, 88, 91};
itable index_list[INDEX_SIZE] = {{3, 0}, {22, 3}, {67, 6}, {9999, 9}};

int seq_search(int key, int low, int high)
{
    int i;

    for(i = low; i <= high; i++){
        if(key == list[i])
            return i;
    }
    return -1;
}

int search_index(int key, int n)
{
    int i, low, high;

    if(key < list[0] || key > list[n-1])
        return -1;

    for(i = 0; i < INDEX_SIZE; i++)
        if(index_list[i].key <= key && index_list[i+1].key > key)
            break;
    if(i == INDEX_SIZE){
        low = index_list[i-1].index;
        high = n;
    } else{
        low = index_list[i].index;
        high = index_list[i+1].index;
    }
    return seq_search(key, low, high);
}

int main()
{
    int n;

    for(int i = 0; i < 2; i++){
        scanf("%d", &n);
        if(search_index(n, 9) != -1)
            printf("Success!\n");
        else
            printf("Failed\n");
    }
}