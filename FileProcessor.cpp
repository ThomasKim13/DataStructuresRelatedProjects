//
// Created by Thomas Kim on 9/24/22.
//
#include "FileProcessor.h"
#include <iostream>
#include <string>
using namespace std;

FileProcessor::FileProcessor() {
    cout << "File is being processed" << endl;
}
FileProcessor::~FileProcessor() {}

void FileProcessor::levelMaker(string inputFile) {
    string line;
    ifstream inFile;
    inFile.open(inputFile);


    if(inFile.is_open()){
        for(int i = 1; getline(inFile,line) && i <= 8; i++){ //cplusplus.com user "outcome" posted how to do this
            switch(i){
                case 1:
                    numLevels = line;
                case 2:
                    dimensionGrid = line;
                case 3:
                    initialLives = line;
                case 4:
                    percentageCoins = line;
                case 5:
                    percentageNothing = line;
                case 6:
                    percentageGoomba = line;
                case 7:
                    percentageKooba = line;
                case 8:
                    percentageMushroom = line;

            }
        }

        inFile.close();
    }

}
int FileProcessor::getNumLevel() {
    return stoi(numLevels);

}

int FileProcessor::getDimensionGrid(){
    return stoi(dimensionGrid);

}

int FileProcessor::getInitialLives() {
    return stoi(initialLives);

}

int FileProcessor::getPercentageCoins() {
    return stoi(percentageCoins);

}

int FileProcessor::getPercentageNothing() {
    return stoi(percentageNothing);

}
int FileProcessor::getPercentageGoomba() {
     return stoi(percentageGoomba);

}

int FileProcessor::getPercentageKooba() {
    return stoi(percentageKooba);
}

int FileProcessor::getPercentageMushroom() {
    return stoi(percentageMushroom);
}
