#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <sstream>
#include "hashTable.h"

#define tableSize 10000000 + 9
hashNode *hashTable[tableSize];




using namespace std;

int getDir(string dir, vector<string> &files){
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}
void printV(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        cout << endl;
    }
}
void printQ(queue<string> myqueue){
    while (!myqueue.empty()) {
        cout << myqueue.front();
        myqueue.pop();
    }
}

string qToString(queue<string> myqueue){
    stringstream ss;
    while (!myqueue.empty()) {
        ss << myqueue.front();
        myqueue.pop();
    }
    string retVal;
    ss >> retVal;
    return retVal;
}


vector<string> returnSequences(string &filePath, int length){
    vector<string> v;
    string word;
    ifstream myfile;
    myfile.open(filePath);
    queue<string> q;
    int wordCnt = 0;
    if(myfile.is_open()){
        char c;
        while(myfile.get(c)){
            if(c != ' '){
                //ignore special charcters
                if((c > 64 && c < 91) || (c>96 && c<123)){
                    c = toupper(c);
                    word+= c;
                }
            }
            else if( c == ' '){
                wordCnt++;
                q.push(word);
                if(wordCnt >=length){
                    //printQ(q);
                    string chunk = qToString(q);
                    v.emplace_back(chunk);
                    q.pop();
                }
                word = "";
            }
        }
        return v;
    }
    else{
        cout << "Error: file not open" << endl;
        return v;
    }
}

long long hashValue(string sequence){
    const int p = 31;
    long long m = tableSize;

    long long hashVal = 0;
    long long power = 1;
    for(int i = 0; i < sequence.length(); i++){
        //int test = sequence[i];

        hashVal = (hashVal + (sequence[i] - 'A' + 1) * power) % tableSize;
        power = (power*p) % tableSize;

    } //edit with hash value
    //cout << hashVal << endl;
    return hashVal;
}

void hashString(string sequence, string fileName, int index){
    long long hashVal = hashValue(sequence);

    hashNode *n = new hashNode(hashVal, index, fileName, hashTable);

}



int main(int argc, char *argv[]) {
    int length = 6;
    std::cout << "cheaters!" << std::endl;
    // must change to use program args at some point
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getDir(dir,files);
    int numFiles = files.size() - 2;
    cout << numFiles << endl;

    /*
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i <<": " << files[i] << endl;
    }
     */
    stringstream ss;
    //ss << "sm_doc_set/" << files[2];
    string filePath;
    ss >> filePath;
    cout << filePath;
    cout << endl;
    //vector<string> v = returnSequences(filePath, 6);
    //printV(v);
    //getDir(dir,files);
    vector <string> fileNames;

    int collisionTable[numFiles][numFiles];

    for(int i = 0; i < numFiles; i++) {
        for (int j = 0; j < numFiles; j++) {
            collisionTable[i][j] = 0;
        }
    }


    for (unsigned int i = 2; i < files.size(); i++) {
        int index = i - 2;
        stringstream sss;
        sss << "sm_doc_set/" << files[i];
        string filePaths;
        sss >> filePath;

        cout << index << ":" << filePath << endl;
        fileNames.push_back(filePath);
        //cout << filePath << endl;
        vector<string> chunks = returnSequences(filePath, length);

        for(int j = 0; j < chunks.size(); j++){
            hashString(chunks[j], filePath, index);
            //long long testHash = hashValue(chunks[j]);
            //cout << hashTable[testHash]->getHash() << " this should be hash" << endl;
            //cout << hashTable[testHash]->index << endl;
            //cout << hashTable[testHash]->getFileName() << " this should be file" << endl;
        }




    }


    // below for loop is used for calculating amount of collisions for files (does not work)

    for(int i = 0; i < fileNames.size(); i++){
        vector <string> chunks = returnSequences(fileNames[i], length);

        for(int j = 0; j < chunks.size(); j++){
            long long hashCheck = hashValue(chunks[j]);
            if(hashTable[hashCheck]->next != NULL){
                hashNode *tempPtr = hashTable[hashCheck]->next;
                hashNode *prvPtr = hashTable[hashCheck];
                int index2 = prvPtr->index;
                collisionTable[i][index2] += 1;
                while(tempPtr->next != NULL){
                    prvPtr = tempPtr;
                    tempPtr = tempPtr->next;
                    index2 = prvPtr->index;
                    collisionTable[i][index2] += 1;

                }

                prvPtr->next = NULL;
                free(tempPtr);

            }
        }

    }


    for(int i = 0; i < fileNames.size(); i++){
        for(int j = 0; j <fileNames.size(); j++){
            cout << collisionTable[i][j] << " ";
        }
        cout << endl;
    }
    vector <string> chunkTest = returnSequences(fileNames[0], length);
    vector <string> chunkChecker = returnSequences(fileNames[11], length);
    int bruteCounter = 0;

    for (int i = 0; i < chunkTest.size(); ++i){
        string testString = chunkTest[i];
        for(int j = 0; j < chunkChecker.size(); j++){
            string testAgainst = chunkChecker[j];
            if(testAgainst == testString){
                bruteCounter++;
            }

        }

    }

    cout << bruteCounter << endl;








    /*
    hashNode(0, "test", hashTable);
    hashNode(0, "next1", hashTable);
    hashNode(0, "next2", hashTable);


    cout << hashTable[0]->getFileName() << endl;
    cout << hashTable[0]->next->getFileName() << endl;
    cout << hashTable[0]->next->next->getFileName() << endl;
     */








    return 0;
}