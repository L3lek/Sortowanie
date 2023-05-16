#pragma once
#include <string>
#include <fstream>
#include <filesystem>

template<typename T>
int wczytaj(T* movie, int n){

    std::ifstream film_list;
    std::string line,temp,folder="../files/";
    char identifier;
    int unrated=0;
    film_list.open(folder+"filmy.csv");

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

return unrated;


}


template<typename T>
void zapisz(T* movies, std::string name, int size){
    std::string folder = "../files/";
        std::ofstream sorted_list;
        std::filesystem::create_directories(folder);
        sorted_list.open(folder+ name);
        if(sorted_list.is_open()){
        sorted_list << ",movie,rating\n";
        for(int i=0;i<size; ++i){
            
            sorted_list << i << ",\"" << movies[i].name << "\"," << movies[i].rating <<"\n";
        }
        sorted_list.close();
    }else{
        std::cout << "Nie można zapisać \n";
    }


}