#pragma once 

#include <string>
#include <iostream>
#include <exception>

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
class NoManaException : public  std::exception{

    public:
        const char* what() const noexcept override {
        return "No mana Exception";
    }

};

class CanCastSpells{
    private:
        int mana;
        int maxMana;
    public:
        CanCastSpells(int mana , int maxMana):mana(mana),maxMana(maxMana){};
        int getMana(){return this->mana;}

        void addMana(int amount){
            this->mana+=amount;
            if(this->mana > this->maxMana){
                this->mana = this->maxMana;
            }
            std::cout<<"This character now has"<< this->mana<<"/"<<this->maxMana<<std::endl; 
        };
        void useMana(int mana){
            if(this->mana-mana < 0){
                throw NoManaException();
            }
            this->mana-=mana;
            std::cout<<mana<<" points of mana have been used "<<this->mana<<"remains";
        }

        virtual void castSpell(Character* target)=0;
};

class CanUseMelee {
    public:
        virtual void performMeleeAttack(Character* target)=0;
};


class Mage: public Character , public CanCastSpells {
    private:
        int spellDamage;
        int mana;
    public:
        Mage(const std::string name , int health=80 , int mana=150 , int damage=20):Character(name,health),CanCastSpells(mana,200){
            this->mana = mana;
            this->spellDamage = damage;
        };
        
        void attack(Character* character) override{
            auto cha = dynamic_cast<Warrior*>(character);
            if(cha){
                this->castSpell(character);
                this->castSpell(character);
            }
            
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



class BattleMage: public Character, public CanCastSpells , public CanUseMelee{
    private:
        int meleDmg;
        int spellDmg;

    public:
    BattleMage(const std::string name , int health=100 , int mana=100,int meleeDamage=10, int damage=15):Character(name,health),CanCastSpells(mana,200){
            this->meleDmg = meleeDamage;
            this->spellDmg = damage;
    };
    void performMeleeAttack(Character* character) override{
        
            character->takeDamage(meleDmg);
        };
    void castSpell(Character* character) override{
            std::cout<<this->name<<" prepares to attack \n";
            this->useMana(10);
            std::cout<<this->name<<" attacks\n";

            character->takeDamage(spellDmg);
        }
    void attack(Character* character){
        try{
            castSpell(character);
        }
        catch(NoManaException){
            std::cout<<"Not enough mana, trying to use melee attack";
            performMeleeAttack(character) ;
        };
        }
    };
   
class Rogue : public Character, public CanUseMelee{
    private:
        int basicAttackDamage;
        int backstabDamage;
    public:
        Rogue(std::string name,int health=90,int basicDmg=12,int backstabDamage=30):Character(name,health),CanUseMelee(){
            this->basicAttackDamage = basicDmg;
            this->backstabDamage = backstabDamage;
        };

        void backstab(Character* character){
            if(typeid(character)==typeid(Mage)){
                std::cout<<"Rogue backstabs mage and deals" << backstabDamage;
                character->takeDamage(backstabDamage);
            }
            else{
                std::cout<<"Backstab was failed";
            }
        };
        void performMeleeAttack(Character* character){
            character->takeDamage(this->basicAttackDamage);
        };
        void attack(Character* character)override{
            if (rand() % 2 == 0)
                    performMeleeAttack(character);
                else
                    backstab(character);
        }
};