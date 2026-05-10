#pragma once 
#include <string>
#include <vector>
#include <variant>
#include <optional>

#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>

template<typename T>
class Sensor{
        public:
            struct Identity{
            Identity(std::string hardwareID , std::string type):hardwareID(hardwareID),type(type){};
            std::string hardwareID;
            std::string type;
        };
        Sensor(std::string name , std::variant<Identity,std::string> source,std::optional<std::string> t = std::nullopt):label(name),source(source),unit(t){};
        
        std::string getLabel() const {
            return this->label;
        };
        std::variant<Identity,std::string> getSource()const{
            return this->source;
        };
        
        std::optional<std::string> getUnit()const {
            return this->unit;
        };
        std::vector<T> getMeasurements()const {
            return this->measurements;
        } ;

        double getRMS()const {
            if(this->measurements.size()==0) return T(0);
            auto begin = this->measurements.begin();
            auto end = this->measurements.end();

            struct Acuu{
                T operator()(T acc , T numer2){
                    return acc + numer2*numer2;
                }
            };


            double sum = std::accumulate(begin,end, 0.0f , Acuu());
           
            return sqrt(sum/this->measurements.size());
        };
        double getMin() const {
            if(this->measurements.size()==0) return T(0);

            
            return *std::min_element(this->measurements.begin(),this->measurements.end());
        }

        bool operator>(Sensor& sensor){
            if(this->label > sensor.label){
                return true;
            }
            if(this->label < sensor.label){
                return false;
            }
            if(this->measurements.size() > sensor.measurements.size()){
                return true;
            }
            return false;
        }
        bool operator!=(Sensor sensor){
            if(this->label!=sensor.label){
                return true;
            }
            return false;
        }
        Sensor& operator<<(T pomiar){
            this->measurements.push_back(pomiar);
            return *this;
        };

        

        private:
            std::string label;
            std::variant<Identity,std::string> source;
            std::optional<std::string> unit;
            std::vector<T> measurements;


};

template<typename T>
std::ostream& operator<<(std::ostream& os ,const  Sensor<T>& sensor){
    os<<sensor.getLabel()<<'['<<' ';

    if(std::holds_alternative<typename Sensor<T>::Identity>(sensor.getSource())){
        auto id = std::get<typename Sensor<T>::Identity>(sensor.getSource());
        os<<id.hardwareID<<' '<<id.type<<']';
    }
    else{
        std::string id = std::get<std::string>(sensor.getSource());
        os<<id << ']';
    }

    os<<" RMS: "<<sensor.getRMS()<<", MIN: "<<sensor.getMin();

    if(sensor.getUnit()){
        os<< '\n';
        os<< *(sensor.getUnit());
    }
    os<<'\n';
    return os;
};
