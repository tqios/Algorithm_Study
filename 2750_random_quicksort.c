#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int start, int end){
  srand(time(NULL));
  int rng = start+(rand()%(end-start+1));
  int temp;

  temp = A[rng];
  A[rng] = A[end];
  A[end] = temp;

  int pivot = A[end];
  int mid = start;

  for (int i=start; i<end; i++){
    if(A[i] < pivot){
      temp = A[mid];
      A[mid] = A[i];
      A[i] = temp;
      mid++;
    }
  }

  temp = A[mid];
  A[mid] = A[end];
  A[end] = temp;

  return mid;
}

void quickSort(int A[], int start, int end){
  int index;
  if(start<end){
    index=partition(A, start, end);
    quickSort(A, start, index-1);
    quickSort(A, index+1, end);
  }
}

int main(){
  int num;
  scanf("%d", &num);

  int A[num];
  for(int i=0; i<num; i++){
    scanf("%d", &A[i]);
  }

  quickSort(A, 0, num-1);

  for(int i=0; i<num; i++){
    printf("%d ", A[i]);
  }
}