#include "Simulation.h"
#include "Level.h"
#include "Mario.h"
#include "FileProcessor.h"
#include "World.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

Simulation::Simulation(){ //default constructor
}

Simulation::~Simulation(){ //destructor
}

void Simulation::createSimulation(string outputFile) {
    srand(time(NULL));
    FileProcessor f;
    f.levelMaker("input.txt");
    int levelNumber = f.getNumLevel();
    int size = f.getDimensionGrid();
    int health = f.getInitialLives();



    Mario m;
    m.setPowerLevel(0);
    m.setCoins(0);

    World *world = new World(levelNumber);
    char ***simWorld = world->createWorld();
    char ***noMario = world->createWorld();
    int marioRow = (rand() % size);
    int marioColumn = (rand() % size);

    ofstream outFile;
    outFile.open(outputFile);
    for(int lvl = 0; lvl < levelNumber; lvl ++){
        outFile << "Level: " << lvl + 1 << endl;
        for(int row = 0; row < size; row++){
            for(int column = 0; column < size; column++){
                outFile << noMario[lvl][row][column] << " ";


            }
            outFile << endl;
        }

    }
//    outFile << "Level: 1" << endl;
//    for(int row = 0; row < size; row++){
//        for(int column = 0; column < size; column++){
//
//            outFile << simWorld[0][row][column] << " ";
//        }
//        outFile << endl;
//
//
//    }
    outFile << "Mario is at row " << marioRow << " and at column " << marioColumn << endl;
    outFile << "Mario power level is " << m.getPowerLevel() << endl;
    int power = 0;
    string play;
    string end;
    bool winLose;
    int counter = 0;

    for(int lvl = 0; lvl < levelNumber; lvl ++){


        while(health > 0){
            int oldRow = marioRow;
            int oldColumn = marioColumn;
            outFile << "Level: " << lvl + 1 << endl;

            int move = m.Movement();
            switch (move){
                case 0:
                    outFile << "UP" << endl;
                    break;
                case 1:
                    outFile << "DOWN" << endl;
                    break;
                case 2:
                    outFile << "LEFT" << endl;
                    break;
                case 3:
                    outFile << "RIGHT" << endl;
                    break;
            }

//            simWorld[lvl][marioRow][marioColumn] = 'H';
            if(move == 0){
                if(marioRow == size - 1){
                    marioRow = 0;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }

                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                        play = "Mario fought the level boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';
                }
                else{
                    marioRow += 1;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                        play = "Mario fought the level boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';
                }
            }
            if(move == 1){
                if(marioRow == 0){
                    marioRow = size - 1;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                       bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                        play = "Mario fought the level boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';
                }
                else{
                    marioRow -= 1;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                        play = "Mario fought the level boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';
                }
            }
            if(move == 2){
                if(marioColumn == 0){
                    marioColumn = size - 1;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                        play = "Mario fought the level boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';
                }
                else{
                    marioColumn -= 1;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                        play = "Mario fought the boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';
                }
            }
            if(move == 3){
                if(marioColumn == size - 1){
                    marioColumn = 0;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = " Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                        bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }
                    simWorld[lvl][marioRow][marioColumn] = 'H';

                }
                else{
                    marioColumn += 1;
                    if(simWorld[lvl][marioRow][marioColumn] == 'm'){
                        m.mushroomInteraction();
                        play = "Mario ate a mushroom";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'c'){
                        m.CoinInteraction();
                        play = "Mario got a coin";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'x'){
                        play = "Position is empty";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'g'){
                       bool x = m.goombaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a goomba";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'k'){
                        bool x = m.koopaInteraction();
                        if(x == false){
                            if(power > 0){
                                power -= 1;
                            }
                            health -= 1;
                        }
                        play = "Mario fought a koopa";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'b'){
                        bool x = m.bossInteraction();
                        if(x == false){
                            if(power > 1){
                                power -= 2;
                            }
                            if(health > 0) {
                                health -= 1;
                            }
                            else{
                                winLose = false;
                                break;
                            }
                        }
                        if(lvl == levelNumber - 1 && x == true){
                            winLose = true;
                            break;
                        }


                        play = "Mario fought the level boss";
                    }
                    else if(simWorld[lvl][marioRow][marioColumn] == 'w'){
                        play = "Mario warped";
                        lvl++;
                    }


                    simWorld[lvl][marioRow][marioColumn] = 'H';
                    ++counter;

                }
            }
            simWorld[lvl][oldRow][oldColumn] = 'x';
            for(int row = 0; row < size; row++){
                for(int column = 0; column < size; column++){
                    outFile << simWorld[lvl][row][column] << " ";
                }
                outFile << endl;
            }
            outFile << "Mario is at row " << marioRow << " and at column " << marioColumn << endl;
            outFile << "Mario power level is " << m.getPowerLevel() << endl;
            outFile << play << endl;
            outFile << "Lives: " << health << endl;
            outFile << "Coins: " << m.getCoins() << endl;
            outFile << "Plays: " << counter << endl;
            if(winLose== false){
                outFile << "Mario LOST" << endl;
            }
            else{
                outFile << "Mario  WON" << endl;
            }




        }

    }












}