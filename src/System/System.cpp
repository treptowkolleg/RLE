//
// Created by BenjaminWagner on 06.11.2024.
//

#include "System.h"

#include <thread>

#include "Out.h"

bool System::hasToken(const string &token) {
    if(this->tokens.find(token) != tokens.end()) {
        return true;
    }
    return false;
}

void System::exit(const int &code) {
    Out::hideCursor();
    Out::print("Programm wird beendet ");
    int i = 20;
    while (i > 0) {
        this_thread::sleep_for(chrono::milliseconds(50));
        Out::print(".");
        i--;
    }
    std::exit(code);
}
