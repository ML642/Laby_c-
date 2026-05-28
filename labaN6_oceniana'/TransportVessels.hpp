#pragma once 

#include <string>
#include "Cargoes.hpp"

class TransportVessel{
    private:
        std::string name;
        std::vector<Cargo*> lista;
        double currentLoad;
    public:
        TransportVessel(std::string name){
            this->name = name;
        }
        virtual ~TransportVessel()=default;
        double& getCurrentLoad(){
            return currentLoad;
        }
        std::string getID(){
            return this->name;
        }
        std::vector<Cargo*>& getLoadedCargo(){
            return this->lista;
        };
        virtual double getMaxCapacity()=0;
        virtual bool loadCargo(Cargo* cargo)=0;
};

class Freighter : public TransportVessel{
    private:
        double capacity;
    
    public:
        Freighter(std::string name, double capacity):TransportVessel(name){
            this->capacity = capacity;
        };
        
        double getMaxCapacity() override{
            return this->capacity;
        }
        bool loadCargo(Cargo* cargo)  override {
            if(this->getCurrentLoad() + cargo->getWeight() <= capacity){
                auto HAZARD = dynamic_cast<HazardousWasteCargo*>(cargo);
                if(HAZARD){
                    std::cout<<"WARNING:Hazardous Waste Cargo "<<HAZARD->getDescription();   
                };


                this->getLoadedCargo().push_back(cargo);
                this->getCurrentLoad()+=cargo->getWeight();
                std::string pole = this->getID()+" loaded "+ cargo->getDescription() + '\n';
                std::cout<<pole;
                return true;
            }
            else{
                std::string pole = this->getID()+" Exceeds capacity of "+ std::to_string(this->capacity) + " units \n";
                std::cout<<pole;
                return false;
            }
        };
};
class ScoutShip : public TransportVessel{
    private:
        double capacity;
    public:
        ScoutShip(std::string id , double capacity):TransportVessel(id){
            this->capacity = capacity;
        };
        double getMaxCapacity(){
            return this->capacity;
        }
        bool loadCargo(Cargo* cargo){
            if(this->getCurrentLoad()+cargo->getWeight() <= capacity  && cargo->getWeight()<200 ){
                auto HAZARD = dynamic_cast<HazardousWasteCargo*>(cargo);
                if(HAZARD){
                    std::cout<<"WARNING:Hazardous Waste Cargo "<<HAZARD->getDescription();    
                };
                if(HAZARD && (HAZARD->getDanger()==DangerLevel::HIGH || HAZARD->getDanger()==DangerLevel::CRITICAL) ){
                    std::cout<<"Too toxic to carry on";
                    return false;
                }
                this->getLoadedCargo().push_back(cargo);
                this->getCurrentLoad()+=cargo->getWeight();
                std::string pole = this->getID()+" loaded "+ cargo->getDescription() + '\n';
                std::cout<<pole;
                
                return true;
            }
            else{
                std::string pole = this->getID()+" Exceeds capacity of "+ std::to_string(this->capacity) + " units \n";
                std::cout<<pole;
                return false;
            }
        };
};