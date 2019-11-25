#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

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
void printQ(queue<string> myqueue){
    while (!myqueue.empty()) {
        cout << ' ' << myqueue.front();
        myqueue.pop();
    }
}

void printSequences(string &filePath, int length){
    string word;
    ifstream myfile;
    myfile.open(filePath);
    queue<string> q;
    int wordCnt = 0;
    if(myfile.is_open()){
        cout << "file open" << endl;
        char c;
        while(myfile.get(c)){
            if(c != ' '){
                //ignore special charcters
                if(c < 46 || c > 122){
                    //ignoring special characters
                }
                else{
                    word+= c;
                }
            }
            else if( c == ' '){
                wordCnt++;
                q.push(word);
                if(wordCnt >=6){
                    printQ(q);
                    q.pop();
                    cout << endl;
                }
                word = "";
            }
        }
    }
    else{
        cout << "file not open" << endl;
    }
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
    stringstream ss;
    ss << "sm_doc_set/" << files[2];
    string filePath;
    ss >> filePath;
    cout << endl;
    printSequences(filePath, 6);


    return 0;
}