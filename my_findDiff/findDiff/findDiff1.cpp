//
//  findDiff1.cpp
//  findDiff
//
//  Created by Yiran Wang on 11/15/17.
//  Copyright © 2017 Yiran Wang. All rights reserved.
//

#include "findDiff1.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

bool findDiff1() {
    ifstream file1("text1.txt");
    ifstream file2("text2.txt");
    int diff = 0;
    unordered_map<string, int> cnt;
    string w1, w2;
    while (file1.good() || file2.good()) {
        file1 >> w1;
        file2 >> w2;
        cnt[w1]++;
        cnt[w2]--;
    }
    for (auto it : cnt) {
        if (it.second != 0) {
            ++diff;
        }
    }
    return diff > 0;
}
