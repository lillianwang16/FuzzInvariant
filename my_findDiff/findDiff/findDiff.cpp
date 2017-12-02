//
//  findDiff.cpp
//  findDiff
//
//  Created by Yiran Wang on 11/15/17.
//  Copyright © 2017 Yiran Wang. All rights reserved.
//

#include "findDiff.hpp"
#include <iostream>
#include <fstream>

using namespace std;

bool findDiff() {
    ifstream file1("text1.txt");
    ifstream file2("text2.txt");
    char c1, c2;
    int diff = 0;
    while (file1.good() || file2.good()) {
        c1 = file1.get();
        c2 = file2.get();
        cout << c1 << " " << c2 << endl;
        if (c1 != c2) {
            ++diff;
        }
    }
    return diff > 0;
}
