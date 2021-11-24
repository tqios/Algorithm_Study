#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))


int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do{
        do
        {
            low++;
        } while (list[low]<pivot);
        do
        {
            high--;
        } while (list[high]>pivot);
        if(low<high){
            SWAP(list[low], list[high], temp);
        }
    } while(low<high);
    SWAP(list[left], list[high], temp);
    return high;
}

int select(int A[], int p, int r, int i){
    if (p==r){
        return A[p];
    }
    int q = partition(A, p, r);
    int k = q-p+1;
    if(i<k){
        return select(A, p, q-1, i);
    }
    else if (i==k){
        return A[q];
    }
    else{
        return select(A, q+1, r, i-k);
    }
    

}

int main(void){
    int list[] = {8,6,1,4,9,7,3,5,0,2};
    int num;
    scanf("%d", &num);
    int selected = select(list,0,9,num);
    printf("%d", selected);
    printf("\n");
    return 0;
}