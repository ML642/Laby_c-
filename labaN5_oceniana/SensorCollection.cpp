
#include "SensorCollection.hpp"


void SensorCollection::addSensor(const std::string& type, const Sensor<double>& sensor){
    for(auto& [key,value] : this->sensorsByType){
        if(key == type){
            value.push_back(sensor);
            return;
        }
    }
    std::list<Sensor<double>> l;
    l.push_back(sensor);
    this->sensorsByType[type] = l; 
};

const std::unordered_map<std::string, std::list<Sensor<double>>>& SensorCollection::getSensorsByType() const  {
    return this->sensorsByType;
};

const std::unordered_map<std::string, std::list<Sensor<double>>>& SensorCollection::getSensorsByType()   {
    return this->sensorsByType;
};

const std::list<Sensor<double>> SensorCollection::getAllSensors() const {
    std::list <Sensor<double>> all_sensors;

    for(auto [key,value]: this->sensorsByType){
        for(auto meas : value){
            all_sensors.push_back(meas);
        
        }
    }
    return all_sensors;
};


std::ostream& operator<<(std::ostream& os , const SensorCollection& collection){

    for(const auto& [key,value] : collection.getSensorsByType()){

        os << "===================" << key << "==================\n";

        for(const auto& sensor : value){
            os << sensor << '\n';
        }
    }

    return os;
}