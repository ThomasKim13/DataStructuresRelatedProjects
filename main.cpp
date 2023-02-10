#include "World.h"
#include "Mario.h"
#include "FileProcessor.h"
#include "Simulation.h"
#include <iostream>
#include <string>
using namespace std;


// int main(int argc, char* argv[]){
//     FileProcessor f = FileProcessor();//instantiates FileProcessor
//     f.ProcessFile(argv[1], argv[2]);//translates the input, writes the translation to the output
//     return 0;//exit
// }
int main(){
    Simulation s;
    s.createSimulation("output.txt");
    return 0;
}