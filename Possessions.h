#ifndef POSSESSIONS_H
#define POSSESSIONS_H

struct Item{
    
};

class Possessions {
    private:
        Item* m_pRoot;

        void destroyTree(Item *rt);
        void printOne(Item *item);
        void printAll(Item *rt);

    public:
        bool addItem(Item *newItem);
        Item *dropItem(char *itemName);
        Item *getItem(char *itemName);

        void printTree();

        

};

#endif // POSSESSIONS_H