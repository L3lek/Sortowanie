#include "intro.h"
#include "merge.h"
#include "quick.h"
#include "file.h"

#include <iostream>
#include <chrono>



struct Movie {
    std::string name;
    short rating;
    bool operator<(Movie compared){return(rating < compared.rating);}
    bool operator>(Movie compared){return(rating > compared.rating);}
};

void average(Movie* movies, int size){
    float average=0;
    for(int i=0; i<size; i++){
        average+=movies[i].rating;
    }
    average /= size;

    std::cout << "Średnia ocen: " << average << std::endl;
}

void median(Movie* movies, int size){
    int median;
    if(size%2!=0){
        median = movies[size/2].rating;
    }else{
        median=(movies[(size-1)/2].rating+movies[size/2].rating)/2;
    }

    std::cout << "Mediana ocen: " << median << std::endl;
}


int main() {
int a[]={10000, 100000, 500000, 1000000};

for(int n:a){

    std::cout <<"------------------------------------------------------------"<<std::endl << "Wielkość tablicy: " << n << std::endl <<std::endl;
    Movie* movie = new Movie[n];
    int unrated=wczytaj(movie, n);
    int real_size=n-unrated;

        if(unrated>0){
            std::cout << "> Filmy bez oceny: " << unrated << '\n'<<std::endl;
        }else{
            std::cout << "> Wszystkie filmy są poprawnie ocenione\n"<<std::endl;
        }


    Movie* rated_movies = new Movie[real_size];

    int j=0,i=0;

    auto duration_start = std::chrono::high_resolution_clock::now();
        while(j<n){
            if(movie[j].rating !=-1){
                rated_movies[i++]=movie[j++];
            }else{
                j++;
            }
        }
    auto duration_end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();

        if(unrated>0)
            std::cout << "Po przefiltrowaniu zostało: " << real_size << ". Czas filtracji: " << duration <<" ms." << std::endl;

    delete[] movie;

    Movie* intro_movie = new Movie[real_size];
    Movie* quick_movie = new Movie[real_size];
    Movie* merge_movie = new Movie[real_size];

    std::cout << "Sortowanie przy użyciu algorytmu sortowania introspectywnego" <<std::endl <<std::endl;
    
    for(int i=0;i<real_size;i++){
    intro_movie[i] = rated_movies[i];
    }

    duration_start = std::chrono::high_resolution_clock::now();
    hybrid_IntroSort(intro_movie,0,n-unrated-1);
    duration_end = std::chrono::high_resolution_clock::now();
    auto duration_intro = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();
    std::cout << "Czas trwania sortowania introspectywnego: " << duration_intro<< " ms."<<std::endl;

    average(intro_movie,real_size);
    median(intro_movie,real_size);

    std::string file_name = "Introsort "+ std::to_string(n) + ".csv";
    zapisz(intro_movie,file_name, real_size);




    std::cout << "Sortowanie przy użyciu algorytmu sortowania quicksort" <<std::endl <<std::endl;

    for(int i=0;i<real_size;i++){
    quick_movie[i] = rated_movies[i];
    }
    
    duration_start = std::chrono::high_resolution_clock::now();
    Quicksort(quick_movie,0,n-unrated-1);
    duration_end = std::chrono::high_resolution_clock::now();
    auto duration_quick = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();
    std::cout << "Czas trwania sortowania quicksort: " << duration_quick<< " ms."<<std::endl;

    average(quick_movie,real_size);
    median(quick_movie,real_size);

    file_name = "Quicksort "+ std::to_string(n) + ".csv";
    zapisz(quick_movie,file_name, real_size);

    



    std::cout << "Sortowanie przy użyciu algorytmu sortowania przez scalanie" <<std::endl <<std::endl;

    for(int i=0;i<real_size;i++){
    merge_movie[i] = rated_movies[i];
    }

    duration_start = std::chrono::high_resolution_clock::now();
    Mergesort(merge_movie,0,real_size-1);
    duration_end = std::chrono::high_resolution_clock::now();
    auto duration_merge = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();
    std::cout << "Czas trwania sortowania przez scalanie: " << duration_merge << " ms." <<std::endl;


    average(merge_movie,real_size);

    median(merge_movie,real_size);
    std::cout <<std::endl;

    file_name = "Mergesort "+ std::to_string(n) + ".csv";
    zapisz(merge_movie,file_name, real_size);

    delete[] intro_movie;
    delete[] quick_movie;
    delete[] merge_movie;
    delete[] rated_movies;

    }
    return 0;
}

