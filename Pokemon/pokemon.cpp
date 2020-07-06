#include "pokemon.h"

pokemon::pokemon() {
	name = "Missing No.";
	nickname = "Missing No.";
	maxHealth = 10;
	health = 10;
	attack = 10;
	defense = 10;
	specDef = 10;
	specAtk = 10;
	level = 1;
	xp = 0;
	baseHealth = health;
	baseAttack = attack;
	baseDefense = defense;
	baseSpecAtk = specAtk;
	baseSpecDef = specDef;
	srand(time(0));
	iv = rand() % 16;
}

pokemon::pokemon(string name, string nickname, int health, int attack, int defense, int speed, int specAtk, int specDef, int level) {
	this->name = name;
	this->nickname = nickname;
	this->maxHealth = health;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->specDef = specDef;
	this->specAtk = specAtk;
	this->level = level;
	this->xp = xp;
	baseHealth = health;
	baseAttack = attack;
	baseDefense = defense;
	baseSpecAtk = specAtk;
	baseSpecDef = specDef;
	srand(time(0));
	iv = rand() % 16;
}

//Getters
int pokemon::getAttack() {
	return attack;
}

int pokemon::getHealth() {
	return health;
}

int pokemon::getSpeed() {
	return speed;
}

int pokemon::getSpecAtk() {
	return specAtk;
}

int pokemon::getSpecDef() {
	return specDef;
}

int pokemon::getXp() {
	return xp;
}

int pokemon::getLevel() {
	return level;
}

//Fight commands

void pokemon::takeDamage(int damage) {
	health -= damage;
}

int pokemon::dealDamage(int lvl, int pow, int atk, int def) {
	int damage = ((2 * lvl / 5 + 2) * pow * atk / def) / 50 + 2;
	return damage;
}

void pokemon::defeatedPokemon(int lvl) {
	int xpGain = lvl / 7 + 1;
	xp += xpGain;
	if (xp >= (level ^ 3)) {
		levelUp();
	}
}

//misc commands

void pokemon::heal(int heal) {
	health += heal;
	if (health > maxHealth) {
		health = maxHealth;
	}
}

void pokemon::levelUp() {
	int hpGain = (2 * baseHealth + iv) * level / 100 + 5;
}

bool pokemon::isAlive() {
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}

void pokemon::printStatus() {

}

void pokemon::displayStats() {

}