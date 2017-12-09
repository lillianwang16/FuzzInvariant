//
//  main.cpp
//  findDiff
//
//  Created by Yiran Wang on 11/15/17.
//  Copyright © 2017 Yiran Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

bool findDiff1(string text1, string text2) {
    ifstream file1;
    file1.open(text1);
    ifstream file2(text2);
    bool diff = false;
    unordered_set<string> cnt;
    string w1, w2;
    while (file1.good()) {
        file1 >> w1;
	cnt.insert(w1);
    }
    file1.close();
    fstream file1_w;
    file1_w.open(text1, fstream :: out | fstream :: app);
    while (file2.good()) {
        file2 >> w2;
        if (cnt.find(w2) == cnt.end()) {
            diff = true;
            file1_w << " " << w2;
        }
    }
    file1_w.close();
   return diff;
}




int main(int argc, const char * argv[]) {
    ofstream out_file;
    out_file.open("isDiff.txt");
    //out_file.open("home/vagrant/FuzzInvariant/afl-2.52b/script/isDiff.txt");
    //string path = "/home/vagrant/FuzzInvariant/afl-2.52b/script/"; 
    string path = "";
    string t1 = path + argv[1];
    string t2 = path + argv[2];
    bool res = findDiff1(t1, t2);
    out_file << res;
    out_file.close();
    return 0;
}
