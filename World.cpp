#include "Level.h"
#include "World.h"
#include "Mario.h"
#include "FileProcessor.h"
#include <stdlib.h>
/* This is the default constructor.
It takes no parameters. */
World::World(){
    m_levelNum = 0;
}
/* This is the overloaded constructor.
It takes a size as the only parameter. */
World::World(int levelNum){
    m_levelNum = levelNum;
}
/* Default destructor. */
World::~World(){
}
/* Accessor for size. */
int World::getLevelNum(){
    return m_levelNum;
}
/* Mutator for size. */
void World::setLevelNum(int levelNum){
    m_levelNum = levelNum;
}

char*** World::createWorld(){
    srand(time(NULL));
    FileProcessor f;
    f.levelMaker("input.txt");
    int levelNumber = f.getNumLevel();
    int size = f.getDimensionGrid();
    int coinPercent = f.getPercentageCoins();
    int nothingPercent = f.getPercentageNothing();
    int goombaPercent = f.getPercentageGoomba();
    int koopaPercent = f.getPercentageKooba();
    int mushroomPercent = f.getPercentageMushroom();

    char*** world = new char**[levelNumber];
    
    bool marioPlaced = false;
    for(int i = 0; i < levelNumber; i++){
        Level* lvl = new Level(size,coinPercent,nothingPercent,goombaPercent,koopaPercent,mushroomPercent);
        char** singleLevel = lvl->createLevel(size,coinPercent,nothingPercent,goombaPercent,koopaPercent,mushroomPercent);

        int bossRow = (rand() % size);
        int bossColumn = (rand() % size);
        singleLevel[bossRow][bossColumn] = 'b';
        
        bool same;
        int warpRow = (rand() % size);
        int warpColumn = (rand() % size);
        if ((bossRow == warpRow) && (bossColumn == warpColumn)){
            same = true;
            while (same == true){
                int warpRow = (rand() % size);
                int warpColumn = (rand() % size);
                if ((bossRow != warpRow) || (bossColumn != warpColumn)){
                    if (i != (levelNumber - 1)){
                        singleLevel[warpRow][warpColumn] = 'w';
                        same = false;
                    }
                    // singleLevel[warpRow][warpColumn] = 'w';
                    // same = false;
                }
            }
    }
    else{
        if (i != (levelNumber - 1)){
            singleLevel[warpRow][warpColumn] = 'w';
        }
        // singleLevel[warpRow][warpColumn] = 'w';
    }

        world[i] = singleLevel;

        

//        if (marioPlaced == false){
//            int marioRow = (rand() % size);
//            int marioColumn = (rand() % size);
//            world[0] [marioRow][marioColumn] = 'H';
//            marioPlaced = true;
//        }
    }


    return world;
}

