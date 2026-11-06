// ♥─────────────────────────────────────────────♥
//   Name: Clarissa Edwards
//   Assignment: Mazes and Monsters
// ♥─────────────────────────────────────────────♥

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Item.h"
#include "Possessions.h"

class Character{
    private:
        char m_sName[64]; //char array of 64 char
        int m_iClass;
        int m_iAlignment;
        int m_iHitPoints; 
        int m_iCharTraits[6]; //for Strength, Dexterity, Constitution, Intelligence, Wisdom, and Charisma
        Possessions *m_pBattleItems;
        Possessions *m_pTreasureItems;

    public:
        Character *m_pNext; //pointer to next character in list

        /* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ constructor(parameters and not) and destructor ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
        Character();
        ~Character();

        Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr);

        /* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Getters/Setters ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
        char* getName();
        int getClass();
        int getAlignment();
        int getHitPoints();
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getIntelligence();
        int getWisdom();
        int getCharisma();


        void setName(char *name);
        void setClass(int cl);
        void setAlignment(int al);
        void setHitPoints(int hp);
        void setStrength(int str);
        void setDexterity(int dex);
        void setConstitution(int cn);
        void setIntelligence(int itl);
        void setWisdom(int wis);
        void setCharisma(int chr);

        /* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ The additional stuff ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
        bool addItem(Item *newItem);
        Item *getItem(char *itemName);
        Item *dropItem(char *itemName);


        /* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Printer ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
        void printAll(); //does the character stats and items
        

}; //end of character class

#endif