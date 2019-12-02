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

hashNode *hashTable[100000];




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

//THIS FUNCTION IS CAUSING SOME PROBLEMS
void putQueueInToVec(queue<string> q, vector<string> &v){
    string wordSeq = "";
    for(int i = 0; i<q.size(); i++){
        wordSeq+= q.front();
        wordSeq+= " ";
        q.pop();
    }
    v.push_back(wordSeq);
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
                    printQ(q);
                    cout << endl;
                    //putQueueInToVec(q, v);
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
    //printV(v);

    hashNode(0, "test", "test", hashTable);
    hashNode(0, "next1", "next1", hashTable);
    hashNode(0, "next2", "next2", hashTable);


    cout << hashTable[0]->getFileName() << endl;
    cout << hashTable[0]->next->getFileName() << endl;
    cout << hashTable[0]->next->next->getFileName() << endl;








    return 0;
}