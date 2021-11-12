#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right){
    int i,j,k,l;
    i = left; j = mid+1; k = left;

    while(i<=mid && j<=right){
        if(list[i]<=list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }
    if(i>mid){
        for(l = j; l<=right; l++){
            sorted[k++] = list[l];
        }
    }
    else{
        for(l=i;l<=mid; l++){
            sorted[k++] = list[l];
        }
    }
    for(l=left;l<=right;l++){
        list[l]=sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    if (left<right){
        int mid1 = (left+right)/16*1;
        int mid2 = (left+right)/16*2;
        int mid3 = (left+right)/16*3;
        int mid4 = (left+right)/16*4;
        int mid5 = (left+right)/16*5;
        int mid6 = (left+right)/16*6;
        int mid7 = (left+right)/16*7;
        int mid8 = (left+right)/16*8;
        int mid9 = (left+right)/16*9;
        int mid10 = (left+right)/16*10;
        int mid11 = (left+right)/16*11;
        int mid12 = (left+right)/16*12;
        int mid13 = (left+right)/16*13;
        int mid14 = (left+right)/16*14;
        int mid15 = (left+right)/16*15;
        merge_sort(list, left, mid1);
        merge_sort(list, mid1+1, mid2);
        merge_sort(list, mid2+1, mid3);
        merge_sort(list, mid3+1, mid4);
        merge_sort(list, mid4+1, mid5);
        merge_sort(list, mid5+1, mid6);
        merge_sort(list, mid6+1, mid7);
        merge_sort(list, mid7+1, mid8);
        merge_sort(list, mid8+1, mid9);
        merge_sort(list, mid9+1, mid10);
        merge_sort(list, mid10+1, mid11);
        merge_sort(list, mid11+1, mid12);
        merge_sort(list, mid12+1, mid13);
        merge_sort(list, mid13+1, mid14);
        merge_sort(list, mid14+1, mid15);
        merge_sort(list, mid15+1, right);
        merge(list, left, mid1, mid2, mid3, mid4, mid5, mid6, mid7, mid8, mid9, mid10, mid11, mid12, mid13, mid14, mid15, right);
    }
}

int main(void){
    int  n = MAX_SIZE;
    int list[MAX_SIZE];
    for(int i=0; i<n; i++){
        list[i]=rand();
    }
    merge_sort(list, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\n", list[i]);
    }
}