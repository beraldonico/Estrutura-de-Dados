#include<stdio.h>
#include<stdlib.h>

void heapinsert (int * heap, int n){
    while(n > 0){
        int pai = ((n + 1)/2) - 1;
        if(heap[n] > heap[pai]){
            int temp = heap[n];
            heap[n] = heap[pai];
            heap[pai] = temp;
        }
        else{
            break;
        }
        n = pai;
    }
}

void fixheap(int *heap, int n){
    int i= 0;
    while(i<n){
        int f1 = ((i+1)+2)-1;
        int f2 = ((i+1)+2);
        if(f1 >= n){
            break;
        }
        if(f2<n && heap[f2] > heap[f1]){
            f1=f2;
        }
        if(heap[f1] > heap [i]){
            int temp = heap[i];
            heap[i] = heap[f1];
            heap[f1] = heap[i];
        }
        else{
            break;
        }
        i = f1;
    }
}

void heapSort(int *vector, int n){
    int i;
    for( i = 0; i<n;i++){
        heapinsert(vector,i);
    }
    int c;
        for(c =0;c<10;c++){
            printf("%i,", vector[c]);
        }
    printf("\n");
    for(i=n-1;i>0;i--){
        int temp = vector[i];
        vector[i] = vector[0];
        vector[0] = temp;
        fixheap(vector,i);
    }
    for(c = 0;c<10;c++){
        printf("%i,", vector[c]);
    }
    printf("\n");
}

int main(){
    int vector[10] = {8,10,1,5,3,7,2,4,6,9};
    heapSort(vector, 10);
    return 0;
}
