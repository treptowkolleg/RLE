//
// Created by BenjaminWagner on 06.11.2024.
//

#include "In.h"

#include <iostream>

#include "Out.h"

void In::readLine(string &target, const string &text) {
    Out::print(text);
    getline(cin, target);
}
