#ifndef WORLD_H //header guard
#define WORLD_H
#include <string>
using namespace std;
class World{
    public:
        World(); //default constructor
        World(int levels); //overloaded constructor
        virtual ~World(); //destructor
        int getLevelNum(); //accessor
        void setLevelNum(int levelNum); //mutator
        char*** createWorld();
    private:
        private:
        int m_levelNum;
        // Level* m_owner; //declares a pointer variable to a Level
};
#endif