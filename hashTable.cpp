//
// Created by Davo on 11/25/2019.
//
#include "hashTable.h"
#include <string>



hashNode::hashNode(){
    hash = 0;
    fileName = "";
    nWordSequence = "";
    next = NULL;
}




hashNode::hashNode(int key, string filename, string entry, hashNode *hashTable[]){
    this->hash = key;
    this->fileName = filename;
    this->nWordSequence = entry;

    if(hashTable[key] != NULL){
        hashNode *tempPtr = hashTable[key];
        hashTable[key] = this;
        hashTable[key]->next = tempPtr;
    }


    hashTable[key] = this;

    
}

void hashNode::setFile(string filename) {
    fileName = filename;
}

void hashNode::setKey(int key) {
    hash = key;
}

void hashNode::setSequence(string sequence) {
    nWordSequence = sequence;
}


string hashNode::getFileName() {
    return hashNode::fileName;
}

string hashNode::getNWordSequence(){
    return hashNode::nWordSequence;
}

int hashNode::getHash() {
    return hashNode::hash;
}




