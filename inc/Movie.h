#pragma once
#include <iostream>
#include <string>

struct Movie {
    std::string name;
    short rating;
    bool operator<(Movie compared){return(rating < compared.rating);}
    bool operator>(Movie compared){return(rating > compared.rating);}
};