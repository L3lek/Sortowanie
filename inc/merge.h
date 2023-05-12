#pragma once
#include <vector>

template<typename T>
void Merge(T& vec, int left, int middle, int right){
    int i,j,k;
    int n1=middle-left+1;
    int n2=right-middle;

    T L(n1), R(n2);

    for(i=0;i<n1;i++)
        L[i]=vec[left+i];

    for(j=0;j<n2;j++)
        R[j]=vec[middle+1+j];

    i=0;
    j=0;
    k=left;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            vec[k]=L[i];
            i++;
        }
        else{
            vec[k]=R[j];
            j++;
        }
    k++;
    }

    while(i<n1){
        vec[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        vec[k]=R[j];
        j++;
        k++;
    }
}

template<typename T>
void Mergesort(T& vec, int left, int right){
    if(left>=right)
        return;

    int middle = left+(right-left)/2;

    Mergesort(vec, left, middle);
    Mergesort(vec, middle+1, right);

    Merge(vec, left, middle, right);
}