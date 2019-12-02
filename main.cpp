#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"

hashNode *hashTable[100000];

using namespace std;
int getdir (string dir, vector<string> &files){
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

int main(int argc, char *argv[]) {
    std::cout << "cheaters!" << std::endl;
    // must change to use program args at some point
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    getdir(dir,files);
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i <<": " << files[i] << endl;
    }

    hashNode(0, "test", "test", hashTable);
    hashNode(0, "next1", "next1", hashTable);
    hashNode(0, "next2", "next2", hashTable);


    cout << hashTable[0]->getFileName() << endl;
    cout << hashTable[0]->next->getFileName() << endl;
    cout << hashTable[0]->next->next->getFileName() << endl;








    return 0;
}