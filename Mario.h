//
// Created by Thomas Kim on 9/18/22.
//

#ifndef PA2_MARIO_H
#define PA2_MARIO_H


class Mario {
public:
    Mario();
    Mario(int health, int powerLevel, int coins);
    ~Mario();
    void setHealth(int health);
    void setCoins(int coins);
    void setPowerLevel(int powerLevel);
    int getPowerLevel();
    int getHealth();
    int getCoins();
    int Movement(); //first bracket up and down second bracket left and right
    void CoinInteraction();
    int mushroomInteraction();
    bool goombaInteraction();
    bool koopaInteraction();
    bool bossInteraction();
private:
    int marioHealth;
    int marioPowerLevel;
    int marioCoins;

};


#endif //PA2_MARIO_H
