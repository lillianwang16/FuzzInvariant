//
//  main.cpp
//  findDiff
//
//  Created by Yiran Wang on 11/15/17.
//  Copyright © 2017 Yiran Wang. All rights reserved.
//

#include <iostream>
#include "findDiff.hpp"
#include "findDiff1.hpp"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ofstream out_file("isDiff.txt");
    bool res = findDiff1();
    out_file << res;
    return 0;
}
