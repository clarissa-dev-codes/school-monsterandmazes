#include "Character.h"
#include <iostream>

using namespace std; //just because I don't like typing std:: every line

// ♥─────────────────────────────────────────────♥
//   Traits Array element
//   Strength: 0
//   Dexterity: 1
//   Constitution: 2
//   Intelligence: 3
//   Wisdom: 4
//   Charisma: 5
// ♥─────────────────────────────────────────────♥

/* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Constructors ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
Character::Character(){
    m_sName[0] = '\0'; // Initialize name to empty string
    m_iClass = 0;
    m_iAlignment = 0;
    m_iHitPoints = 0;
    for(int i = 0; i < 6; ++i) {
        m_iCharTraits[i] = 0; // Initialize all traits to 0 
    }
    for(int i = 0; i < 10; ++i) {
        m_Items[i].m_sItemName[0] = '\0'; // Initialize item names to empty strings
    }
    m_pNext = nullptr; // Initialize the next pointer to nullptr
}

Character::Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr){
    //wanted to use the setter functions, but it felt illegal so I copy
    //  and pasted
    
    int i = 0;
    while(name[i] != '\0' && i < 64){
        m_sName[i] = name[i];
        i++;
    }
    m_sName[i] = '\0'; // Ensure null at the end of the string

    m_iClass = cl;
    m_iAlignment = al;
    m_iHitPoints = hp;
    m_iCharTraits[0] = str;
    m_iCharTraits[1] = dex;
    m_iCharTraits[2] = con;
    m_iCharTraits[3] = itl;
    m_iCharTraits[4] = wis;
    m_iCharTraits[5] = chr;

    m_pNext = nullptr; // Initialize the next pointer to nullptr
    
}

/* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Getters ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
char* Character::getName(){
    return m_sName;
}
int Character::getClass(){
    return m_iClass;
}
int Character::getAlignment(){
    return m_iAlignment;
}
int Character::getHitPoints(){
    return m_iHitPoints;    
}
int Character::getStrength(){
    return m_iCharTraits[0];
}
int Character::getDexterity(){
    return m_iCharTraits[1];
}
int Character::getConstitution(){
    return m_iCharTraits[2];
}
int Character::getIntelligence(){
    return m_iCharTraits[3];
}
int Character::getWisdom(){
    return m_iCharTraits[4];
}
int Character::getCharisma(){
    return m_iCharTraits[5];
}
/* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Setters ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
void Character::setName(char *name){
    //this way works and it doesn't use strcpy since I'm not sure that 
    //  I can use anything other than the files that I make 

    int i = 0;

    while(name[i] != '\0' && i < 64){
        m_sName[i] = name[i];
        i++;
    }
    m_sName[i] = '\0'; // Ensure null at the end of the string
}
void Character::setClass(int cl){
    m_iClass = cl;
}
void Character::setAlignment(int al){
    m_iAlignment = al;
}
void Character::setHitPoints(int hp){
    m_iHitPoints = hp;
}
void Character::setStrength(int str){
    m_iCharTraits[0] = str;
}
void Character::setDexterity(int dex){
    m_iCharTraits[1] = dex;
}
void Character::setConstitution(int cn){
    m_iCharTraits[2] = cn;
}
void Character::setIntelligence(int itl){
    m_iCharTraits[3] = itl;
}
void Character::setWisdom(int wis){
    m_iCharTraits[4] = wis;
}
void Character::setCharisma(int chr){
    m_iCharTraits[5] = chr;
}

/* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ The additional stuff ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
bool Character::addItem(Item *newItem){
    if (newItem == nullptr) {
        return false; // Cannot add a null item
    }

    for(int i = 0; i < 10; ++i) {
        if (m_Items[i].m_sItemName[0] == '\0') { // Check for empty slot
            m_Items[i] = *newItem; // Copy the item into the array
            return true; // Item added successfully
        }
    }
    return false; // inventory full
}

Item *Character::getItem(char *itemName){
    if (itemName == nullptr) {
        return nullptr; // Cannot search for a null item name
    }

    for(int i = 0; i < 10; ++i) {
        char *currentItemName = m_Items[i].m_sItemName;
        if (currentItemName == nullptr) {
            continue; // Skip empty slots
        }
        int j = 0;
        while(currentItemName[j] != '\0' && itemName[j] != '\0') {
            if (currentItemName[j] != itemName[j]) {
                break; // Characters do not match   
            }
            j++;
        }
            if (currentItemName[j] == '\0' && itemName[j] == '\0') {
                return &m_Items[i]; // Return pointer to the found item
            }
        }
        return nullptr; // Item not found
}

Item *Character::dropItem(char *itemName){
    if (itemName == nullptr) {
        return nullptr; // Cannot drop a null item name
    }

    for(int i = 0; i < 10; ++i) {
        char *currentItemName = m_Items[i].m_sItemName;
        if (currentItemName == nullptr) {
            continue; // Skip empty slots
        }
        int j = 0;
        while(currentItemName[j] != '\0' && itemName[j] != '\0') {
            if (currentItemName[j] != itemName[j]) {
                break; // Characters do not match   
            }
            j++;
        }
            if (currentItemName[j] == '\0' && itemName[j] == '\0') {
                Item *droppedItem = new Item(m_Items[i]); // Create a copy of the item to return
                m_Items[i].m_sItemName[0] = '\0'; // Mark the slot as empty
                return droppedItem; // Return pointer to the dropped item
            }
        }
        return nullptr; // it ain't there
}

/* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Printer ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
void Character::printAll(){
    cout << "Character Name: " << m_sName << endl;
    cout << "Class: " << m_iClass << endl;
    cout << "Alignment: " << m_iAlignment << endl;
    cout << "Hit Points: " << m_iHitPoints << endl;
    cout << "Strength: " << m_iCharTraits[0] << endl;
    cout << "Dexterity: " << m_iCharTraits[1] << endl;
    cout << "Constitution: " << m_iCharTraits[2] << endl;
    cout << "Intelligence: " << m_iCharTraits[3] << endl;
    cout << "Wisdom: " << m_iCharTraits[4] << endl;
    cout << "Charisma: " << m_iCharTraits[5] << endl;

    cout << "Items:" << endl;
    for(int i = 0; i < 10; ++i) {
        if (m_Items[i].m_sItemName[0] != '\0') { // Check for non-empty slot
            cout << "- Item Name: " << m_Items[i].m_sItemName 
                 << ", Type: " << m_Items[i].m_iType 
                 << ", Value: " << m_Items[i].m_dValue 
                 << ", Weight: " << m_Items[i].m_dWeight 
                 << endl;
        }
    }
}

/* ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ♥ Destructor ♥ ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ */
Character::~Character(){
    if (m_pNext != nullptr) {
        delete m_pNext; // delete it one at a time
        m_pNext = nullptr; 
    }
}
