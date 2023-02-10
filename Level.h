#ifndef LEVEL_H //header guard
#define LEVEL_H
#include <string>
using namespace std;
class Level{
    public:
        Level(); //default constructor
        Level(int size, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent); //overloaded constructor
        virtual ~Level(); //destructor
        int getSize(); //accessors
        int getCoinPercent();
        int getNothingPercent();
        int getGoombaPercent();
        int getKoopaPercent();
        int getMushroomPercent();
        void setSize(int size); //mutators
        void setCoinPercent(int coinPercent);
        void setNothingPercent(int nothingPercent);
        void setGoombaPercent(int goombaPercent);
        void setKoopaPercent(int koopaPercent);
        void setMushroomPercent(int mushroomPercent);
        char** createLevel(int size, int coinPercent, int nothingPercent, int goombaPercent, int koopaPercent, int mushroomPercent);
    private:
        private:
        int m_size;
        int m_coinPercent;
        int m_nothingPercent;
        int m_goombaPercent;
        int m_koopaPercent;
        int m_mushroomPercent;
        Level* m_Level; //declares a pointer variable to a Level
};
#endif