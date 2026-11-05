#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H

#include "Character.h"
#include "Item.h"

class CharacterList{
    private:
        Character *m_pCharList[10]; //array of 10 character pointers
        int m_iNumChars; //number of characters in the list

    public:
        /* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ constructor(parameters and not) and destructor ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
        CharacterList();
        ~CharacterList();

        /* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Getters/Setters ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
        bool addCharacter(Character *newCharacter);
        Character *deleteCharacter(char *characterName);
        bool addItem(char *characterName, Item *newItem);
        Item *getItem (char *characterName, char *itemName);
        Item *dropItem(char *characterName, char *itemName);

        /* ▬▬▬▬▬▬ ♥ Print All Characters in List ♥ ▬▬ */
        void printCharacters();

}; //end of character list class
#endif