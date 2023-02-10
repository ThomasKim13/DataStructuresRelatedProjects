#include "Level.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <ctime>
using namespace std;
/* This is the default constructor.
It takes no parameters. */
Level::Level(){
    m_size = 0;
}
/* This is the overloaded constructor.
It takes a size as the only parameter. */
Level::Level(int size, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent){
    m_size = size;
    m_coinPercent = coinPercent;
    m_nothingPercent = nothingPercent;
    m_goombaPercent = goombaPercent;
    m_koopaPercent = koopaPercent;
    m_mushroomPercent = mushroomPercent;
}
/* Default destructor. */
Level::~Level(){
}
/* Accessor for size. */
int Level::getSize(){
    return m_size;
}

int Level::getCoinPercent(){
    return m_coinPercent;
}

int Level::getNothingPercent(){
    return m_nothingPercent;
}

int Level::getGoombaPercent(){
    return m_goombaPercent;
}

int Level::getKoopaPercent(){
    return m_koopaPercent;
}

int Level::getMushroomPercent(){
    return m_mushroomPercent;
}

/* Mutator for size. */
void Level::setSize(int size){
    m_size = size;
}

void Level::setCoinPercent(int coinPercent){
    m_coinPercent = coinPercent;
}

void Level::setNothingPercent(int nothingPercent){
    m_nothingPercent = nothingPercent;
}

void Level::setGoombaPercent(int goombaPercent){
    m_goombaPercent = goombaPercent;
}

void Level::setKoopaPercent(int koopaPercent){
    m_koopaPercent = koopaPercent;
}

void Level::setMushroomPercent(int mushroomPercent){
    m_mushroomPercent = mushroomPercent;
}

char** Level::createLevel(int size, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent){
    int coinUpperbound = coinPercent;
    int nothingUpperbound = coinUpperbound + nothingPercent;
    int goombaUpperbound = nothingUpperbound + goombaPercent;
    int koopaUpperbound = goombaUpperbound + koopaPercent;
    int mushroomUpperbound = 100 - koopaUpperbound;
    int counter = 0;

    char** level = new char*[size];
    char* column;
    // srand(time(NULL));
    for (int a = 0; a < size; a++){
        column = new char[size];
        for (int i = 0; i < size; i++){
            int random = (rand() % 100) + 1;
            // cout << random << endl;
                    if (random >= 1 && random <= coinUpperbound){
                        column[i] = 'c';
                        counter += 1;
                    }
                    if (random > coinUpperbound && random <= nothingUpperbound){
                        column[i] = 'x';
                        counter += 1;
                    }
                    if (random > nothingUpperbound && random <= goombaUpperbound){
                        column[i] = 'g';
                        counter += 1;
                    }
                    if (random > goombaUpperbound && random <= koopaUpperbound){
                        column[i] = 'k';
                        counter += 1;
                    }
                    if (random > koopaUpperbound && random <= 100){
                        column[i]= 'm';
                        counter += 1;
                    }
            // cout << column[i] << " ";
        }
        // cout << endl;
        level[a] = column;
    }
    // cout << endl;
    // int bossRow = (rand() % size);
    // int bossColumn = (rand() % size);
    // level[bossRow][bossColumn] = 'b';
    
    // bool same;
    // int warpRow = (rand() % size);
    // int warpColumn = (rand() % size);
    // if ((bossRow == warpRow) && (bossColumn == warpColumn)){
    //     same = true;
    //     while (same == true){
    //         int warpRow = (rand() % size);
    //         int warpColumn = (rand() % size);
    //         if ((bossRow != warpRow) || (bossColumn != warpColumn)){
    //             level[warpRow][warpColumn] = 'w';
    //             same = false;
    //         }
    //     }
    // }
    // else{
    //     level[warpRow][warpColumn] = 'w';
    // }
    // else{
    //     level[warpRow][warpRow] = 'w';
    // }
    // cout << counter << endl;

    // for (int i = 0; i < size; i++){
    //     for (int j = 0; j < size; j++){
    //         cout << level[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return level;
}
// int main(){
//     int size = 3;
//     Level* level = new Level(size,30,30,15,20,5);
//     char** lvl = new char*[size];
//     lvl = level->createLevel(size,30,30,15,20,5);
//     for (int i = 0; i < size; i++){
//         for (int j = 0; j < size; j++){
//             cout << lvl[i][j] << endl;
//         }
//     }
    
//     return 0;
// }