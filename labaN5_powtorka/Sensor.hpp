#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <optional>
#include <cmath>
#include <algorithm>
#include <numeric>


template<typename T>
class Sensor{
    public:
        struct Identity{
            Identity(std::string type , std::string hardwareID):type(type),hardwareID(hardwareID){};
            std::string type;
            std::string hardwareID;
        };
        Sensor(std::string label,std::variant<Identity,std::string> source,std::optional<std::string> unit = std::nullopt):label(label),source(source),unit(unit){};
        
        const std::string& getLabel() const{
            return this->label;
        }
        const std::variant<Identity,std::string>& getSource() const{
            return this->source;
        }
        const std::optional<std::string>& getUnit() const{
            return this->unit;
        }
        const std::vector<T>& getMeasurements() const {
            return this->measurements;
        }
        

        double getRMS(){
            if(this->measurements.size() == 0 )return T(0);
            struct Acc{
                T operator()(T acc,T element){
                    return element*element+acc;
                }
            };
            
            return sqrt(std::accumulate(this->measurements.begin(),this->measurements.end(),0.0f,Acc())/this->measurements.size());
        };
        T getMin(){
            if(this->measurements.size() == 0 )return T(0);

            return *std::min_element(this->measurements.begin(),this->measurements.end());
        };

    bool operator>(Sensor sensor){
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
    };
    bool operator!=(Sensor sensor){
        if(this->label != sensor.label){
            return true;
        }
        return false;
    };

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
std::ostream& operator<<(std::ostream& os , Sensor<T> sensor){
    os<<sensor.getLabel()<<'[';

    if(std::holds_alternative<typename Sensor<T>::Identity>(sensor.getSource())){
        auto identyty = std::get<typename Sensor<T>::Identity>(sensor.getSource());
        os<<identyty.type<<identyty.hardwareID<<']';
    }
    else{
        os<<std::get<std::string>(sensor.getSource());
    }
    os<<"RMS:"<<sensor.getRMS()<<" ,Min: "<<sensor.getMin();
    os<<'\n';

    if(sensor.getUnit()){
        os<<"Unit:" <<*sensor.getUnit()<<'\n';
    }
    return os;
}