#pragma once
#include <vector>

template<typename T>
void Quicksort(T& vec, int left, int right){
    if(left>=right)
        return;

    int pivot=vec[(left+right)/2];
    int i=left;
    int j=right;

    while(i<=j){
        while(vec[i]<pivot)
            i++;
        while(vec[j]>pivot)
            j--;

        if(i<=j){
            std::swap(vec[i],vec[j]);
            i++;
            j--;
        }
    }
    Quicksort(vec, left, j);
    Quicksort(vec, i, right);
}