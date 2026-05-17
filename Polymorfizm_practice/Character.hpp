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

class Mage: public Character , public CanCastSpells{
    private:
        int spellDamage;
        int mana;
    public:
        Mage(const std::string name , int health=80 , int mana=150 , int damage=20):Character(name,health),CanCastSpells(){
            this->mana = mana;
            this->spellDamage = damage;
        };
        
        void attack(Character* character) override{
            this->castSpell(character);
        };

        void castSpell(Character* character) override{
            std::cout<<this->name<<" prepares to attack \n";
            this->useMana(10);
            std::cout<<this->name<<" attacks\n";

            character->takeDamage(spellDamage);
        }
};

class Warrior: public Character , public CanUseMelee{
private:
        int meleeDamage;
    public:
        Warrior(const std::string name , int health=80  , int damage=20):Character(name,health){
            this->meleeDamage = damage;
        };
        
        void attack(Character* character) override{
            std::cout<<this->name<<" attacks ";
            this->performMeleeAttack(character);
        };
        void performMeleeAttack(Character* character) override{
        
            character->takeDamage(meleeDamage);
        };
};


class NoManaException : std::exception{

    std::string what(){
        return "No mana Exception";
    }

};

class CanCastSpells(){
    private:
        int mana;
        int maxMana;
    public:
        int getMana(){return this->mana};

        void addMana(int amount){
            this->mana+=amount;
            if(this->mana > this->maxMana){
                this->mana = this->maxMana;
            }
            std::cout<<"This character now has"<< this->mana<<"/"<<this->maxMana<<std::endl; 
        };
        void useMana(int mana){
            if(this->mana-mana < 0){
                throw NoManaException;
            }
            this->mana-=mana;
            std::cout<<mana<<" points of mana have been used "<<this->mana<<"remains";
        }

        virtual castSpell(Character* target)=0;
};

class CanUseMelee {
    public:
        virtual performMeleeAttack(Character* target)=0;
};

class BattleMage: public Character, public CanCastSpells , public CanUseMelee{
    private:
        int meleDmg;
        int spellDmg;

    public:
    BattleMage(const std::string name , int health=100 , int mana=100,int meleeDamage=10, int damage=15):Character(name,health),CanCastSpells(){
            this->mana = mana;
            this->meleDmg = meleDamage;
            this->spellDmg = damage;
    };
    void performMeleeAttack(Character* character) override{
        
            character->takeDamage(meleeDamage);
        };
    void castSpell(Character* character) override{
            std::cout<<this->name<<" prepares to attack \n";
            this->useMana(10);
            std::cout<<this->name<<" attacks\n";

            character->takeDamage(spellDamage);
        }
    void attack(Character* character){
        try{
            castSpell(character);
        }
        catch(NoManaException){
            std::cout<<"Not enough mana, trying to use melee attack";
            performMeleeAttack(Character* character) ;
        };
        }
   
   
    }
   