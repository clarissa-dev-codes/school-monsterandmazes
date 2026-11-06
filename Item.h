#ifndef ITEM_H
#define ITEM_H

struct Item{
    char m_sItemName[64];
    char m_sDesc[127]; //added for p4
    int m_iType;
    double m_dValue;
    double m_dWeight;

    //added for p4
    Item *m_pLeft;
    Item *m_pRight;
};


#endif