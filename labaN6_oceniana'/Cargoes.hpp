#pragma once

#include <iostream>

enum class DangerLevel{
    LOW=0,
    MEDIUM=1,
    HIGH=2,
    CRITICAL=3
};

class Cargo{
    private:
        static int numer;
        unsigned int id;
        std::string name;
    public:
        Cargo(std::string name){
            this->name=name;
            this->id=Cargo::numer;
            Cargo::numer+=1;
        }
        virtual ~Cargo()=default;
        unsigned int getID(){
            return this->id;
        }
        std::string getName(){
            return this->name;
        }

        virtual std::string getDescription()=0;
        virtual double getWeight()=0;
};

class RawMaterialCargo: public Cargo{
    private:
        double purityPercentage ;
        double weight;
    public:
        RawMaterialCargo(std::string name, double weight,double purity):Cargo(name){
            this->purityPercentage = purity;
            this->weight = weight;
        };

        std::string getDescription(){
            std::string opis =  this->getName() + " (Id:" + std::to_string(this->getID())+" ) "+"Raw material:Purity "+std::to_string(this->purityPercentage) ;
            return opis;
        }
        double getWeight(){
            return this->weight;
        }
};
class ManufacturedGoodsCargo:public Cargo{
    private:
        unsigned int unitCount;
        double weightPerUnit;
    public:
        ManufacturedGoodsCargo(std::string name, unsigned int count, double weightPU):Cargo(name){
            this->unitCount=count;
            this->weightPerUnit = weightPU;
        }
        double getWeight(){
            return this->weightPerUnit*this->unitCount;
        }
        std::string getDescription(){
            std::string opis=this->getName()+ "( ID: "+ std::to_string(this->getID())+" ) Manufactiring Goods:"+std::to_string(this->unitCount)+"units";
            return  opis;
        }
};

class HazardousWasteCargo:public Cargo{
    private:
        DangerLevel dangerLevel;
        double weight;
    public:
        HazardousWasteCargo(std::string name ,double weight , DangerLevel dangerLevel):Cargo(name){
            this->weight = weight ;
            this->dangerLevel =dangerLevel;
        };
        double getWeight(){
            return this->weight;
        };
        std::string getDescription(){
            std::string type;
            switch(this->dangerLevel){
                case DangerLevel::LOW:type="LOW";
                case DangerLevel::MEDIUM:type="MEDIUM";
                case DangerLevel::HIGH:type="HIGH";
                case DangerLevel::CRITICAL:type="CRITICIAL";
            }
            std::string opis=this->getName()+ "( ID: "+ std::to_string(this->getID())+" ) Hazard Wastes: Danger Lever"+type+" loaded ";
            return  opis;
        };
        DangerLevel getDanger(){
            return this->dangerLevel;
        };

};

int Cargo::numer=0;