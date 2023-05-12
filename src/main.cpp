#include "bucket.h"
#include "merge.h"
#include "quick.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>




struct Movie {
    std::string name;
    int rating;
};

int main() {
	int i=0;
    std::ifstream dataset;  // baza filmow (wczytywany plik)
    std::string dataset_name = "filmy.csv";
    std::ofstream sorted_dataset;  // posortowana baza (zapisywany plik)
    std::string sorted_dataset_name;

    std::vector<Movie> movies; // wektor struktur przechowujących nazwy filmów i ich oceny

    std::string line;
    while (i<10) { // dla każdej linii w pliku
        std::istringstream ss(line);
        std::string name, rating_str;
        getline(ss, name, ','); // wczytaj nazwę filmu
        getline(ss, rating_str, ','); // wczytaj ocenę jako ciąg znaków
        int rating = stoi(rating_str); // zamień ocenę na typ int
        movies.push_back({name, rating}); // dodaj film do wektora struktur
		i++;
    }

    dataset.close(); // zamknij plik

    // wyświetl nazwy filmów i ich oceny
    for (auto movie : movies) {
        std::cout << movie.name << ": " << movie.rating << std::endl;
    }

    return 0;
}































//int main(){
//std::vector<int>arr={5,6,-2,11,43,12,0,1,2,9};
//std::vector<int>merge=arr, bucket=arr, quick=arr;

//for(int i=0;i<arr.size(); i++){
//    std::cout << arr[i]<< ' ';
//}
//std::cout << std::endl;


//bucket_sort(bucket);
//for(int i=0;i<bucket.size();i++){
//    std::cout << bucket[i] << ' ';
//}
//std::cout << std::endl;

//Quicksort(quick, 0, quick.size()-1);
//for(int i=0;i<quick.size();i++){
//    std::cout << quick[i] << ' ';
//}
//std::cout << std::endl;

//Mergesort(merge, 0, merge.size()-1);
//for(int i=0;i<merge.size();i++){
//    std::cout << merge[i] << ' ';
//}
//std::cout << std::endl;


//	return 0;
//}
