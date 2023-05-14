#pragma once

template<typename T>
void Merge(T* vec, int left, int middle, int right){
    int i=left,j=middle+1, k=0;

    T* tmp = new T[right-left+1];

    while(i<=middle && j<=right){
        if(vec[j]<vec[i]){
            tmp[k++]=vec[j++];
        }
        else{
            tmp[k++]=vec[i++];
        }
    }

    if(i<=middle)
        while(i<=middle){
            tmp[k++]=vec[i++];
        }
    else
        while(j<=right){
            tmp[k++]=vec[j++];
        }

    for(int t=0;t<=right-left;t++){
        vec[left+t]=tmp[t];
    }
    delete[] tmp;
}

template<typename T>
void Mergesort(T* vec, int left, int right){
    if(left>=0 && left<right){
        int middle = (left+right)/2;
        Mergesort(vec, left,middle);
        Mergesort(vec,middle+1,right);

        Merge(vec,left,middle,right);
    }
}