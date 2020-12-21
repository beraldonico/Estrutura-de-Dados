#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int key;
}element;

typedef struct{
    element * vector;
    unsigned int vectorsize;
    unsigned int listsize;
}List;

element *binarysearchekey(element *vector, int first ,int last, int skey){
    if(last<first){
        return NULL;
    }
    if (last== first){
        if (vector[first].key == skey){
            return &(vector[first]);
        }
        else{
            return NULL;
        }
    }
    int m = (last + first)*0.5;
    if (vector[m].key == skey){
        return &(vector[m]);
    }
    if(skey < vector[m].key){
        return binarysearchekey(vector, first,m - 1, skey);
    }
    else{
        return binarysearchekey(vector , m , last , skey);
    }
}

element *binarysearche( List * list, int searchekey){
    if(list == NULL){
        return NULL;
    }
    return binarysearchekey( list->vector, 0 ,list -> listsize - 1, searchekey );
}

int main(){
    return 0;
}
