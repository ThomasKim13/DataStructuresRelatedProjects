#ifndef SIMULATION_H //header guard
#define SIMULATION_H
#include <string>
using namespace std;
class Simulation{
    public:
        Simulation(); //default constructor
        // Simulation(int levels); //overloaded constructor
        virtual ~Simulation(); //destructor
        // int getLevelNum(); //accessor
        // void setLevelNum(int levelNum); //mutator
        void createSimulation(string outputFile);
    // private:
    //     private:
    //     int m_levelNum;
    //     // Level* m_owner; //declares a pointer variable to a Level
};
#endif