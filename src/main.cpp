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
    short rating;
    bool operator<(Movie compared){return(rating < compared.rating);}
    bool operator>(Movie compared){return(rating > compared.rating);}
};

int main() {
    int n=100000;
    Movie* movie = new Movie[n];
    

    std::ifstream film_list;
    std::ofstream sorted_list;
    std::string line,temp;
    char identifier;
    int unrated=0;
    film_list.open("filmy.csv");

    if (film_list.is_open()) {
    std::cout << "Plik poprawnie otwarty" << std::endl;
}
else {
    std::cout << "Nie ma poprawnego pliku" << std::endl;
}
           std::getline(film_list, line);  // pominiecie headera
        for (unsigned int i = 0; i < n; i++) {
            // format pliku: indeks,nazwa,ocena
            std::getline(film_list, line);  // dzielenie pliku na linie
            std::stringstream split(line);
            // wczytywanie indeksu i przecinka
            std::getline(split, temp, ',');
            // wczytywanie nazwy - pomiedzy " " lub zwykla oddzielona
            // przecinkiem
            std::stringstream::pos_type positon = split.tellg();
            split >> identifier;
            if (identifier == '"') {
                std::getline(split, movie[i].name, '"');
                split >> identifier;  // ignoruj ,
            }
            else {
                split.seekg(positon);  // wroc
                std::getline(split, movie[i].name, ',');
            }
            // wczytywanie oceny
            if (!(split >> movie[i].rating)) {
                unrated++;
                movie[i].rating = -1;
            }
        }
        film_list.close();

        if(unrated>0){
            std::cout << "> Filmy bez oceny: " << unrated << '\n';
        }


        Movie* rated_movies = new Movie[n-unrated];

        int j=0,i=0;
        while(j<n){
            if(movie[j].rating !=-1){
                rated_movies[i++]=movie[j++];
            }else{
                j++;
            }
        }

    delete[] movie;


    Quicksort(rated_movies,0,n-unrated-1);



    sorted_list.open("sort.csv");
    if(sorted_list.is_open()){
        sorted_list << ",movie,rating\n";
        for(int i=0;i<n-unrated; ++i){
            
            sorted_list << i << ",\"" << rated_movies[i].name << "\"," << rated_movies[i].rating <<"\n";
        }
        sorted_list.close();
    }else{
        std::cout << "Nie można zapisać \n";
    }

    delete[] rated_movies;

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
