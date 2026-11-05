#include <iostream>
#include "Character.h"
#include "CharacterList.h"

using namespace std; //just because I don't like typing std:: every line, I'm that lazy

CharacterList::CharacterList() {
    m_iNumChars = 0; // Initialize the number of characters to 0
    for(int i = 0; i < 10; ++i) {
        m_pCharList[i] = nullptr; // Initialize all character pointers to nullptr
    }
}

bool CharacterList::addCharacter(Character *newCharacter) {
    if (newCharacter == nullptr) {
        return false; // Cannot add a null character
    }
    if (m_iNumChars >= 10) {
        return false; // List is full
    }
    m_pCharList[m_iNumChars] = newCharacter; // Add the new character to the list
    m_iNumChars++; // Increment the number of characters
    return true; // Character added successfully
}

Character *CharacterList::deleteCharacter(char *characterName) {
    if (characterName == nullptr) {
        return nullptr; // Cannot delete a character with a null name
    }
    for(int i = 0; i < m_iNumChars; ++i) {
        char *currentCharName = m_pCharList[i]->getName();
        if (currentCharName == nullptr) {
            continue; // Skip null character pointers
        }
        int j = 0;
        while(currentCharName[j] != '\0' && characterName[j] != '\0') {
            if (currentCharName[j] != characterName[j]) {
                break; // Characters do not match   
            }
            j++;
        }
        if (currentCharName[j] == '\0' && characterName[j] == '\0') {
            Character *deletedCharacter = m_pCharList[i]; // Store the pointer to the character to be deleted
            for(int k = i; k < m_iNumChars - 1; ++k) {
                m_pCharList[k] = m_pCharList[k + 1]; // Shift characters down in the list
            }
            m_pCharList[m_iNumChars - 1] = nullptr; // Set the last pointer to nullptr
            m_iNumChars--; // Decrement the number of characters
            return deletedCharacter; // Return the deleted character pointer
        }
    }
    return nullptr; // Character not found
}

Item *CharacterList::getItem(char *characterName, char *itemName) {
    if (characterName == nullptr || itemName == nullptr) {
        return nullptr; // Cannot get an item with null character or item name
    }
    for(int i = 0; i < m_iNumChars; ++i) {
        char *currentCharName = m_pCharList[i]->getName();
        if (currentCharName == nullptr) {
            continue; // Skip null character pointers
        }
        int j = 0;
        while(currentCharName[j] != '\0' && characterName[j] != '\0') {
            if (currentCharName[j] != characterName[j]) {
                break; // Characters do not match   
            }
            j++;
        }
        if (currentCharName[j] == '\0' && characterName[j] == '\0') {
            return m_pCharList[i]->getItem(itemName); // Return the item from the found character
        }
    }
    return nullptr; // Character not found
}

Item *CharacterList::dropItem(char *characterName, char *itemName) {
    if (characterName == nullptr || itemName == nullptr) {
        return nullptr; // Cannot drop an item with null character or item name
    }
    for(int i = 0; i < m_iNumChars; ++i) {
        char *currentCharName = m_pCharList[i]->getName();
        if (currentCharName == nullptr) {
            continue; // Skip null character pointers
        }
        int j = 0;
        while(currentCharName[j] != '\0' && characterName[j] != '\0') {
            if (currentCharName[j] != characterName[j]) {
                break; // Characters do not match   
            }
            j++;
        }
        if (currentCharName[j] == '\0' && characterName[j] == '\0') {
            return m_pCharList[i]->dropItem(itemName); // Drop the item from the found character
        }
    }
    return nullptr; // Character not found
}

void CharacterList::printCharacters() {
    for(int i = 0; i < m_iNumChars; ++i) {
        if (m_pCharList[i] != nullptr) {
            m_pCharList[i]->printAll(); // Print all details of the character
        }
    }
}
