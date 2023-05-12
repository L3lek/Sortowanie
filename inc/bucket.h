#include<iostream>
#include <vector>
#include <algorithm>

template<typename T>
void bucket_sort(T& arr) {
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());

    // Oblicz długość każdego kubełka i ilość kubełków
    int bucket_size = 10;
    int bucket_count = (max_val - min_val) / bucket_size + 1;

    // Inicjalizuj kubełki jako puste listy
    std::vector<std::vector<int>> buckets(bucket_count);

    // Rozdziel każdą liczbę z wektora do odpowiedniego kubełka
    for (int num : arr) {
        int index = (num - min_val) / bucket_size;
        buckets[index].push_back(num);
    }

    // Posortuj każdy kubełek osobno
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    // Połącz kubełki w jedną posortowaną listę
    int i = 0;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            arr[i++] = num;
        }
    }
}