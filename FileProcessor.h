//
// Created by Thomas Kim on 9/21/22.
//

#ifndef PA2_FILEPROCESSOR_H
#define PA2_FILEPROCESSOR_H
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class FileProcessor {
public:
    FileProcessor();
    ~FileProcessor();
    void levelMaker(string inputFile);
    void marioMovesProcessor(string outputFile);
    int getNumLevel();
    int getDimensionGrid();
    int getInitialLives();
    int getPercentageCoins();
    int getPercentageNothing();
    int getPercentageGoomba();
    int getPercentageKooba();
    int getPercentageMushroom();
private:
    string numLevels;
    string dimensionGrid;
    string initialLives;
    string percentageCoins;
    string percentageNothing;
    string percentageGoomba;
    string percentageKooba;
    string percentageMushroom;

};


#endif //PA2_FILEPROCESSOR_H
