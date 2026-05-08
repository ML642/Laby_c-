#include "MovieCollection.hpp"

#include <numeric>

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



void MovieCollection::removeMoviesOlderThan(char letter , int year){
    struct functor{
        functor(int year):x(year){};
        int x;
        bool operator()(const Movie<double>& movie){
            if( movie.getYear() < x ) {
                //std::cout<<"USUWAM";
                return true;}
            return false; 
        }
    };
    
    for(auto& [key,vec] : this->moviesByLetter){
        if(key == letter){
            //std::cout<<"dafdsafasdfasd";
            vec.erase(std::remove_if(vec.begin() , vec.end() , functor(year)),vec.end());
        }
    }
};


float MovieCollection::getAverageTopRating(){
    std::vector<Movie<double>> ALL_movies = this->getAllMovies();

    struct functor_acc{
        float operator()(float accumulate,Movie<double> movie2){
            return accumulate + movie2.getTopRating();
        }
    };

    float all = std::accumulate(ALL_movies.begin() ,  ALL_movies.end() , 0.0f , functor_acc() );

    return all/ALL_movies.size();
};

std::vector<Movie<double>> MovieCollection::getMoviesByDirector(const std::string& director)const {
    std::vector<Movie<double>> ALL_movies = this->getAllMovies();

    std::vector<Movie<double>> movies_by_Director;

    struct funktor_d{
        funktor_d(const std::string& name){
            this->director = name ;
        }
        std::string director;
        bool operator()(const Movie<double>& movie){
            std::string director1;
            if(std::holds_alternative<Movie<double>::Director>(movie.getDirector())){
                director1 = std::get<typename Movie<double>::Director>(movie.getDirector()).name;
            }
            else{
                
                director1= std::get<typename std::string>(movie.getDirector());
            }
            if(director1 == this->director){
                return true;
            }
            else {
                return false;
            }
        };

    };
    std::copy_if(ALL_movies.begin(),ALL_movies.end(),std::back_inserter(movies_by_Director),funktor_d(director));

    return movies_by_Director;
}

