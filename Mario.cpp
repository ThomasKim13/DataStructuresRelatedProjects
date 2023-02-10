//
// Created by Thomas Kim on 9/18/22.
//

#include "Mario.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std; 

Mario::Mario() {
    marioHealth = 0;
    marioPowerLevel = 0;
    marioCoins = 0;
}
Mario::Mario(int health, int powerLevel, int coins) {
    marioHealth = health;
    marioPowerLevel = powerLevel;
    marioCoins = coins;
}
Mario::~Mario() {}

void Mario::CoinInteraction() {
    marioCoins += 1;
}
void Mario::setCoins(int coins) {
    marioCoins = coins;
}
void Mario::setHealth(int health) {
    marioHealth = health;
}
void Mario::setPowerLevel(int powerLevel) {
    marioPowerLevel = powerLevel;
}
int Mario::getCoins() {
    return marioCoins;
}
int Mario::getHealth() {
    return marioCoins;
}
int Mario::getPowerLevel() {
    return marioPowerLevel;
}

int Mario::Movement() {
    int num = rand() % 4;
    return num;
}

bool Mario::goombaInteraction() {
    int num = rand()% 100 + 1;
    if(num > 80){
        if(marioPowerLevel > 0){
            marioPowerLevel -= 1;
            return false;
        }
        else{
            marioHealth -= 1;
            return false;
        }


    }
    return true;
}

bool Mario::koopaInteraction() {
    int num = rand() % 100 + 1;
    if(num > 65){
        if(marioPowerLevel > 0){
            marioPowerLevel -= 1;
            return false;
        }
        else{
            marioHealth -= 1;
            return false;
        }
    }
    return true;
}

int Mario::mushroomInteraction() {
    marioPowerLevel += 1;
    return marioPowerLevel;
}

bool Mario::bossInteraction() {
    while(marioHealth > 0){
        int num = rand() % 2;
        if(num == 0){
            if(marioPowerLevel > 0){
                marioPowerLevel -=2;
                return false;
            }
            else{
                marioHealth -=1;
                return false;
            }
        }


    }
    return true;

}