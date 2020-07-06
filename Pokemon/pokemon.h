#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class pokemon {
private:

    string name;
    string nickname;
    int maxHealth, health, attack, defense, speed, specAtk, specDef;
    int baseHealth, baseAttack, baseDefense, baseSpeed, baseSpecAtk, baseSpecDef;
    int level, xp;
    int iv;

public:


    pokemon();

    pokemon(string name, string nickname, int health, int attack, int defense, int speed, int specAtk, int specDef, int level);

    //Getters
    int getAttack();

    int getHealth();

    int getSpeed();

    int getSpecAtk();

    int getSpecDef();

    int getXp();

    int getLevel();

    //Fight commands

    void takeDamage(int damage);

    int dealDamage(int lvl, int pow, int atk, int def);
    
    void defeatedPokemon(int lvl);

    //misc commands

    void heal(int heal);

    void levelUp();

    bool isAlive();

    void printStatus();

    void displayStats();
};
#endif