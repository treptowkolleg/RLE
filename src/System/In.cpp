//
// Created by BenjaminWagner on 06.11.2024.
//

#include "In.h"

#include <iostream>
#include <set>

#include "Out.h"
#include "System.h"

void In::readLine(string &target, const string &text) {
    System system;

    Out::print(text);
    cout << Out::setColor(FG_LIGHT_CYAN);
    getline(cin, target);
    cout << Out::setColor(FG_WHITE);
    if(system.hasToken(target)) System::exit();
}
