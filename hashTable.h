//
// Created by Davo on 11/25/2019.
//
#ifndef CHEATERS_HASHTABLE_H
#define CHEATERS_HASHTABLE_H
#include <string>

using namespace std;

class hashNode{
private:
    int hash;
    string fileName;
    string nWordSequence;




public:

    hashNode *next;



    hashNode();
    hashNode(int hash, string fileName, string entry, hashNode *hashTable[]);
    void setKey(int key);
    void setFile(string filename);
    void setSequence(string sequence);


    int getHash();
    string getFileName();
    string getNWordSequence();

    //void setNext(hashNode &sameKey);


};






#endif //CHEATERS_HASHTABLE_H
