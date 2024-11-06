//
// Created by BenjaminWagner on 06.11.2024.
//

#include "In.h"

#include <iostream>
#include <set>

#include "Out.h"

void In::readLine(string &target, const string &text) {

    set<string> tokens = {"ende","exit","quit","abort","abbruch","bye"};

    Out::print(text);
    cout << Out::setColor(FG_LIGHT_CYAN);
    getline(cin, target);
    cout << Out::setColor(FG_WHITE);
    if(tokens.find(target) != tokens.end()) {
        Out::clear();
        exit(0);
    }
}
