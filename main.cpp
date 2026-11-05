#include <iostream>
#include "Character.h"
#include "Item.h"

int main() {
    std::cout << "=== STARTING MAZES & MONSTERS TEST ===\n\n";

    // 1. Test Default Constructor
    std::cout << "--- 1. Testing Default Constructor ---\n";
    Character hero1;
    hero1.printAll(); 

    // 2. Test Setters & Getters
    std::cout << "--- 2. Testing Setters & Getters ---\n";
    
    // Using explicit char arrays to satisfy 'char*' parameter constraints
    char hero1Name[] = "Clarissa the Mage";
    hero1.setName(hero1Name);
    
    hero1.setClass(2);          
    hero1.setAlignment(1);      
    hero1.setHitPoints(45);
    hero1.setStrength(10);
    hero1.setDexterity(14);
    hero1.setConstitution(12);
    hero1.setIntelligence(18);
    hero1.setWisdom(16);
    hero1.setCharisma(15);
    
    std::cout << "Verified Name via getter: " << hero1.getName() << "\n";
    std::cout << "Verified Intel via getter: " << hero1.getIntelligence() << "\n\n";

    // 3. Test Struct Items System (addItem, getItem, dropItem)
    std::cout << "--- 3. Testing Struct-Based Inventory ---\n";
    
    // Creating items using aggregate initialization matching Item struct fields
    Item sword = {"Excalibur", 1, 500.0, 8.5};
    Item potion = {"Health Potion", 5, 50.0, 0.5};
    Item shield = {"Iron Shield", 2, 120.0, 15.0};

    // Add them to Clarissa's inventory
    hero1.addItem(&sword);
    hero1.addItem(&potion);
    hero1.addItem(&shield);
    
    std::cout << "Clarissa's inventory after adding 3 items:\n";
    hero1.printAll();

    // Try to locate an item
    std::cout << "Searching for 'Health Potion'...\n";
    char lookupPotion[] = "Health Potion";
    Item* foundItem = hero1.getItem(lookupPotion);
    if (foundItem != nullptr) {
        std::cout << "Found it! Confirmed Weight: " << foundItem->m_dWeight << " lbs\n\n";
    } else {
        std::cout << "Error: Potion not found!\n\n";
    }

    // Dropping an item
    std::cout << "Dropping 'Excalibur'...\n";
    char dropSword[] = "Excalibur";
    Item* dropped = hero1.dropItem(dropSword);
    
    if (dropped != nullptr) {
        std::cout << "Successfully dropped item: " << dropped->m_sItemName << "\n";
        delete dropped; // Clear dynamic allocation returned by dropItem
    } else {
        std::cout << "Error: Could not drop Excalibur!\n";
    }

    std::cout << "\nClarissa's inventory after dropping Excalibur:\n";
    hero1.printAll();

    std::cout << "=== TEST COMPLETE ===\n";
    return 0;
}
