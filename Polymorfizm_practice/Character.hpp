#pragma once 

#include <string>
#include <iostream>


class Character{
    protected:
        std::string name;
        int health;
        int maxHealth;
    public:
        Character(std::string name , int health=100):name(name),health(health){};

        virtual ~Character(){};

        std::string getName(){
            return this->name;
        };
        int getHealth(){
            return this->health;
        }
        bool isAlive(){
            if(this->health>0)return true;
            return false;
        }
        void takeDamage(int damage){
            std::cout<<this->name<< " takes "<< damage <<" points of damage \n";
            this->health = this->health - damage ;
            std::cout<<this->name<< " has "<< this->health <<" points of health \n";
            if(!this->isAlive()){
                std::cout<<"This character is dead \n";
            }
        };
        void heal(int heal){
            std::cout<<this->name<< "heals "<< heal <<"points  \n";
            this->health = this->health + heal ;
            std::cout<<this->name<< " has "<< this->health <<" points of health \n";
            if(!this->isAlive()){
                std::cout<<"This character is dead \n";
            };
        }
        virtual void attack(Character* attack) = 0 ;
};

class Mage: public Character{
    private:
        int spellDamage;
        int mana;
    public:
        Mage(const std::string name , int health=80 , int mana=150 , int damage=20):Character(name,health){
            this->mana = mana;
            this->spellDamage = damage;
        };
        
        void attack(Character* character)override{
            std::cout<<this->name<<" attacks ";
            character->takeDamage(spellDamage);
        };
};

class Warrior:public Character{
private:
        int meleeDamage;
    public:
        Warrior(const std::string name , int health=80  , int damage=20):Character(name,health){
            this->meleeDamage = damage;
        };
        
        void attack(Character* character) override{
            std::cout<<this->name<<" attacks ";
            character->takeDamage(meleeDamage);
        };
};