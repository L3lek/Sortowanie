#include<iostream>
#include <cmath>
#include <algorithm>
#include "quick.h"

template<typename T>
void heapify(T* arr, int start, int end) {
    int largest = end;  // Węzeł o największej wartości
    int left = 2 * end+ 1;  // Lewe dziecko
    int right = 2 * end + 2;  // Prawe dziecko

    // Sprawdzenie, czy lewe dziecko jest większe od korzenia
    if (left < start && arr[left] > arr[largest])
        largest = left;

    // Sprawdzenie, czy prawe dziecko jest większe od korzenia
    if (right < start && arr[right] > arr[largest])
        largest = right;

    // Jeśli korzeń nie jest największy, zamiana z największym dzieckiem
    if (largest != end) {
        std::swap(arr[end], arr[largest]);

        // Rekurencyjne wywołanie heapify dla poddrzewa
        heapify(arr, start, largest);
    }
}

template<typename T>
void heap_sort(T* arr, int size) {
    int n = size;

    // Budowanie kopca (heapify) - tworzenie kopca maksymalnego
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Wyodrębnianie elementów z kopca (sortowanie)
    for (int i = n - 1; i > 0; i--) {
        // Zamiana korzenia (największego elementu) z ostatnim elementem
        std::swap(arr[0], arr[i]);

        // Ponowne wywołanie heapify dla zmniejszonego kopca
        heapify(arr, i, 0);
    }
}

template<typename T>
void insertion_sort(T* arr, int size) {
    int n = size;

    for (int i = 1; i < n; i++) {
        T key = arr[i];  // Aktualny element do wstawienia na właściwe miejsce
        int j = i - 1;  // Indeks poprzedniego elementu

        // Przesuwanie elementów większych od klucza w prawo
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Przesunięcie elementu w prawo
            j--;  // Przejście do poprzedniego elementu
        }

        arr[j + 1] = key;  // Wstawienie elementu na właściwe miejsce w posortowanej sekwencji
    }
}

template <typename T>
void introSort(T* array, int start, int end, int maxdepth) {
    // Jeśli osiągnięto maksymalną głębokość rekursji, przechodzi do sortowania przez kopcowanie
    if (maxdepth <= 0) {
        heap_sort(array, end - start);
        return;
    }
    
    // Podział tablicy wokół pivota
    int i = partition(array, start, end);
    
    // Rekurencyjne wywołanie introSort dla lewej części tablicy, jeśli jest większa niż 9 elementów
    if (i > 9)
        introSort(array, start, i, maxdepth - 1);
    
    // Rekurencyjne wywołanie introSort dla prawej części tablicy, jeśli jest większa niż 9 elementów
    if (end - i > 9)
        introSort(array, i + 1, end, maxdepth - 1);
}

template <typename T>
void hybrid_IntroSort(T* array, int start, int end) {
    // Wywołanie sortowania hybrydowego introSort
    // z maksymalną głębokością równą 2-krotności logarytmu z rozmiaru sortowanej części tablicy
    introSort(array, start, end, (2 * log(end - start)));

    // Sortowanie przez wstawianie na małych podtablicach
    insertion_sort(array, end - start);
}





















//template<typename T>
//void bucket_sort(T* arr, int n, int max) {
//    // Find maximum rating to determine the range of buckets

//    // Create buckets
//    std::vector<T> buckets[max + 1];

//    // Add each element to the appropriate bucket
//    for (int i = 0; i < n; i++) {
//        buckets[arr[i].rating].push_back(arr[i]);
//    }

//    // Sort each bucket and concatenate the results
//    int k = 0;
//    for (int i = max; i >= 0; i--) {
//        Quicksort(buckets,0,max+1);
//        for (unsigned int j = 0; j < buckets[i].size(); j++) {
//            arr[k] = buckets[i][j];
//            k++;
//        }
//    }
//}