#pragma once 
#include <list>
#include <variant>
#include <optional>
#include <string>

template<typename RatingType>
class Movie{
  
    public:
        struct Director{
        std::string name ;
        int numberOfOscars;
        Director(std::string name , int numberOfOscars):name(name),numberOfOscars(numberOfOscars){};

    };
        Movie<RatingType>& operator+(RatingType rate){
            ratings.emplace_back(rate);
            return *this;
        };

        Movie(std::string title, int year , std::variant<Director,std::string> direktor):title(title),year(year),director(direktor){ };
        Movie(std::string title, int year , std::variant<Director,std::string> direktor,std::string opis):title(title),year(year),director(direktor),description(opis){ };

        std::string getTitle()const {return this->title;}
        int getYear()const{return this->year;}
        std::optional<std::string> getDescription()const {return this->description;}
        const std::variant<Director,std::string>& getDirector()const {return this->director;}
        const std::list<RatingType>& getRatings()const {return this->ratings;}

        RatingType getAverageRating()const {
            if(this->ratings.size() == 0 )return RatingType(0);
            RatingType average = 0;
            for (const auto i:this->ratings )
                {
                    average+=i;
                }
            average = average / this->ratings.size();
            return average;
        };
        RatingType getTopRating() const {
            if(this->ratings.size() == 0)return RatingType(0);
            RatingType max = -1; 
            for (const auto i:this->ratings) 
                {
                    if(max < i)max=i;
                }
            return max;
        };
       
      

    private:
        std::string title;
        int year;
        std::variant<Director,std::string> director;
        std::optional<std::string> description;
        std::list<RatingType> ratings;
        

};


template<class RatingType>
std::ostream& operator<<(std::ostream& os, const Movie<RatingType>& movie) {
    os << movie.getTitle() << " (" << movie.getYear() << "), ";

    if (std::holds_alternative<typename Movie<RatingType>::Director>(movie.getDirector())) {
        const auto& director = std::get<typename Movie<RatingType>::Director>(movie.getDirector());
        os << "Director: " << director.name << " (Oscars: " << director.numberOfOscars << "), ";
    } else {
        os << "Director: " << std::get<std::string>(movie.getDirector()) << ", ";
    }

    os << "Avg: " << movie.getAverageRating() << ", Top: " << movie.getTopRating();

    if (movie.getDescription()) {
        os << "\nDescription: " << *movie.getDescription();
    }

    return os;
}

template<typename RatingType>
bool operator<(const Movie<RatingType>& other1 , const Movie<RatingType>& other2)  {
            if(other1.getTitle()==other2.getTitle()){
                if(other1.getYear() < other2.getYear()){
                    return true ;
                }
                else {
                    return false;
                }
            }
            if(other1.getTitle() < other2.getTitle()){
                return true;
            }
            return false;
        };
template<typename RatingType>
bool operator==(Movie<RatingType>& other , Movie<RatingType>& other2){
            if(other2.getTitle() == other.getTitle() && other2.getTitle() == other.getTitle()){
                return true;
            }
            return false;
}


