#pragma once 

#include <string>
#include <iostream>
#include "Cargoes.hpp"

void generateLogisticsReport(const std::vector<TransportVessel*>& allVessels){
    for (auto& i : allVessels) {
        std::cout<<"- ID:" << i->getID()<<" , Type: class";
        if(typeid(*i) == typeid(Freighter)){
            std::cout<<" Freighter \n";
        }
        else {
            std::cout<<" ScoutShip \n";
        }
        std::cout<<'\t'<<"Current load : "<<i->getCurrentLoad()<<'/'<<i->getMaxCapacity()<<std::endl;
        std::cout<<'\t'<<"Cargo Inventory:\n";
        int ind = 0 ;
        if(i->getLoadedCargo().size()==0){
            std::cout<<"------------PUSTO-----------------\n";
        }
        for(auto odchody : i->getLoadedCargo()){
            std::cout<<'\t'<<ind<<'.'<<' '; 
            std::cout<<odchody->getDescription()<<std::endl;
            ind++;
        }
    }
}