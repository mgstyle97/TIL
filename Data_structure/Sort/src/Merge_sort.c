#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted[MAX_SIZE];

void merge(int left, int mid, int right)
{
    int i, j, k, l;

    i = left;
    j = mid+1;
    k = left;
    // 분할 정렬된 list의 합병
    while(i <= mid && j <= right){
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아있는 레코드의 일괄 복사
    if(i > mid)
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];

    // 배열 sorted[]의 리스트를 배열 list[]로 재복사
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int left, int right)
{
    int mid;

    if(left < right){
        mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, mid, right);
    }
}

int main()
{
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    merge_sort(0, MAX_SIZE-1);
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}