#pragma once 

#include <iostream>
#include "Movie.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
class MovieCollection{
    private:
        std::map<char, std::vector<Movie<double>>> moviesByLetter;
    public:
        std::map<char, std::vector<Movie<double>>> getMoviesByLetter() const ;
        std::vector<Movie<double>> getAllMovies() const  ;
        void addMovie(const Movie<double>& movie);
        void sortMovies();
        std::optional<Movie<double>> findMovieWithAverageAbove(double threshold) const;
        std::vector<Movie<double>> getMoviesByDirector(const std::string& director)const;
        float getAverageTopRating() ;
        void removeMoviesOlderThan(char letter, int year);
};

std::ostream& operator<<(std::ostream& os,const MovieCollection& movie);



