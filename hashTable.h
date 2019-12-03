//
// Created by Davo on 11/25/2019.
//
#ifndef CHEATERS_HASHTABLE_H
#define CHEATERS_HASHTABLE_H
#include <string>

using namespace std;

class hashNode{
private:

    string fileName;
    //string nWordSequence;




public:
    long long hash;

    hashNode *next;



    hashNode();
    hashNode(long long hash, string fileName, hashNode *hashTable[]);
    void setKey(long long key);
    void setFile(string filename);
    //void setSequence(string sequence);


    long long getHash();
    string getFileName();
    //string getNWordSequence();

    //void setNext(hashNode &sameKey);


};






#endif //CHEATERS_HASHTABLE_H
