//
//  main.cpp
//  findDiff
//
//  Created by Yiran Wang on 11/15/17.
//  Copyright © 2017 Yiran Wang. All rights reserved.
//

#include <iostream>
#include "findDiff1.hpp"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ofstream out_file;
    out_file.open("isDiff.txt");
    //out_file.open("home/vagrant/FuzzInvariant/afl-2.52b/script/isDiff.txt");
    string path = "/home/vagrant/FuzzInvariant/afl-2.52b/script/"; 
    string t1 = path + argv[0];
    string t2 = path + argv[1];
    bool res = findDiff1(t1, t2);
    out_file << res;
    out_file.close();
    return 0;
}
