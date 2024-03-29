//
// Created by Davo on 11/25/2019.
//
#include "hashTable.h"
#include <string>
#include <iostream>

using namespace std;



hashNode::hashNode(){
    hash = 0;
    fileName = "";
    //nWordSequence = "";
    next = NULL;
}




hashNode::hashNode(long long key, int newIndex, string filename, hashNode *hashTable[]){
    hash = key;
    index = newIndex;
    fileName = filename;
    //this->nWordSequence = entry;

    if(hashTable[key] != NULL){
        hashNode *tempPtr = hashTable[key];
        hashTable[key] = this;
        hashTable[key]->next = tempPtr;
    }else{
        hashTable[key] = this;
        this->next = NULL;
    }

}

void hashNode::setFile(string filename) {
    fileName = filename;
}

void hashNode::setKey(long long key) {
    hash = key;
}

/*
void hashNode::setSequence(string sequence) {
    nWordSequence = sequence;
}
*/


string hashNode::getFileName() {
    return hashNode::fileName;
}

/*
string hashNode::getNWordSequence(){
    return hashNode::nWordSequence;
}
 */

long long hashNode::getHash() {
    return hashNode::hash;
}

void hashNode::setIndex(int newIndex) {
    index = newIndex;
}



