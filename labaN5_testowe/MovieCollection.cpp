#include "MovieCollection.hpp"

std::map<char, std::vector<Movie<double>>> MovieCollection::getMoviesByLetter() const{
    return this->moviesByLetter;
};
std::vector<Movie<double>> MovieCollection::getAllMovies() const  {
    std::vector<Movie<double>> Movies;
    for(auto [key,value] : this->moviesByLetter){
        
        for(auto value2:value){
          Movies.push_back(value2);
        }
    }
    return Movies;
};


void MovieCollection::addMovie(const Movie<double>& movie){
    const std::string& title = movie.getTitle();
    if (title.empty()) {
        std::cout<<"ERRROR";
        throw std::runtime_error("Empty movie title");
    }
    char litera = title[0];
    std::vector<Movie<double>> Movies;
    for(auto& [key,value] : this->moviesByLetter){
        
        if(key == litera){
            value.push_back(movie);
            return;
        }
    }
    std::vector<Movie<double>> a ;
    a.push_back(movie);
    this->moviesByLetter[litera] = a;
};

std::ostream& operator<<(std::ostream& os ,const MovieCollection& movie){
    for(const auto [key,value] : movie.getMoviesByLetter()){
        os<<"==="<<key<<"==="<<std::endl;
        for(auto i : value){
            os<<i<<std::endl;
        }
    }
    return os;
};
std::optional<Movie<double>> MovieCollection::findMovieWithAverageAbove(double threshold) const {
    struct HasAverageAbove {
        double threshold;
        explicit HasAverageAbove(double threshold) : threshold(threshold) {}

        bool operator()(const Movie<double>& movie) const {
            return movie.getAverageRating() > threshold;
        }
    };

    auto allMovies = getAllMovies()  ;
    auto it = std::find_if(allMovies.begin(), allMovies.end(), HasAverageAbove(threshold));
    if (it != allMovies.end()) {
        return *it;
    }
    return std::nullopt;
}

void MovieCollection::sortMovies() {
    for (auto& [key, vec] : this->moviesByLetter) {
        std::sort(vec.begin(), vec.end());
    }
}