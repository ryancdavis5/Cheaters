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

#define tableSize 10^9 + 9
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

int hashValue(string sequence){
    const int p = 31;
    int m = tableSize;

    int hashVal = 0;
    //int power = 1;
    for(int i = 0; i < sequence.length(); i++){
        hashVal = (hashVal + ((sequence[i] - 'A' + 1) ^ i));
        //power = (power*p) % tableSize;

    } //edit with hash value
    hashVal %= tableSize;
    return hashVal;
}

void hashString(string sequence, string fileName){
    int hashVal = hashValue(sequence);

    hashNode nodeEntry = hashNode(hashVal, fileName, sequence, hashTable);

}


int main(int argc, char *argv[]) {
    std::cout << "cheaters!" << std::endl;
    // must change to use program args at some point
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    getDir(dir,files);
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i <<": " << files[i] << endl;
    }
    stringstream ss;
    ss << "sm_doc_set/" << files[2];
    string filePath;
    ss >> filePath;
    cout << filePath;
    cout << endl;
    vector<string> v = returnSequences(filePath, 6);
    printV(v);

    hashNode(0, "test", "test", hashTable);
    hashNode(0, "next1", "next1", hashTable);
    hashNode(0, "next2", "next2", hashTable);


    cout << hashTable[0]->getFileName() << endl;
    cout << hashTable[0]->next->getFileName() << endl;
    cout << hashTable[0]->next->next->getFileName() << endl;








    return 0;
}