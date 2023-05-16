#pragma once

template<typename T>
void Merge(T* vec, int left, int middle, int right){
    int i = left;         // Indeks początku pierwszej podtablicy
    int j = middle + 1;   // Indeks początku drugiej podtablicy
    int k = 0;            // Indeks pomocniczej tablicy tymczasowej

    T* tmp = new T[right - left + 1];  // Tworzenie tymczasowej tablicy pomocniczej

    // Scalanie dwóch posortowanych podtablic w tablicy tymczasowej
    while (i <= middle && j <= right) {
        if (vec[j] < vec[i]) {
            tmp[k++] = vec[j++];  // Przypisanie elementu z drugiej podtablicy do tablicy tymczasowej
        } else {
            tmp[k++] = vec[i++];  // Przypisanie elementu z pierwszej podtablicy do tablicy tymczasowej
        }
    }

    // Dodawanie pozostałych elementów z pierwszej podtablicy, jeśli istnieją
    if (i <= middle) {
        while (i <= middle) {
            tmp[k++] = vec[i++];
        }
    } else {  // Dodawanie pozostałych elementów z drugiej podtablicy, jeśli istnieją
        while (j <= right) {
            tmp[k++] = vec[j++];
        }
    }

    // Przepisanie posortowanej tablicy tymczasowej z powrotem do oryginalnej tablicy
    for (int t = 0; t <= right - left; t++) {
        vec[left + t] = tmp[t];
    }

    delete[] tmp;  // Zwolnienie pamięci zajmowanej przez tablicę tymczasową
}

template<typename T>
void Mergesort(T* vec, int left, int right){
    if (left >= 0 && left < right) {
        int middle = (left + right) / 2;  // Obliczenie środka tablicy

        // Rekurencyjne wywołanie Mergesort dla lewej i prawej połowy tablicy
        Mergesort(vec, left, middle);
        Mergesort(vec, middle + 1, right);

        // Scalanie posortowanych podtablic
        Merge(vec, left, middle, right);
    }
}
