//
// Created by BenjaminWagner on 12.11.2024.
//

#include "TerminalMenuItem.h"
#include "../System/In.h"


TerminalMenuItem::TerminalMenuItem(const string& question, const function<bool(string input)>& action) {
    // TODO: gehört in TerminalMenu::run();
    while (true) {
        string input;
        In::readLine(input, question + ": ");
        if(action(input))
            return;
    }
}