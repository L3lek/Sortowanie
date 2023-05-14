#include<iostream>
#include <vector>
#include <algorithm>


template<typename T>
void bucket_sort(T arr[], int n) {
    // Find maximum rating to determine the range of buckets
    int max_rating = 10;

    // Create buckets
    std::vector<T> buckets[max_rating + 1];

    // Add each element to the appropriate bucket
    for (int i = 0; i < n; i++) {
        buckets[arr[i].rating].push_back(arr[i]);
    }

    // Sort each bucket and concatenate the results
    int k = 0;
    for (int i = max_rating; i >= 0; i--) {
        std::sort(buckets[i].begin(), buckets[i].end(), std::greater<T>());
        for (unsigned int j = 0; j < buckets[i].size(); j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}