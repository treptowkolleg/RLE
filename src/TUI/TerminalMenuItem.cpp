//
// Created by BenjaminWagner on 12.11.2024.
//

#include "TerminalMenuItem.h"
#include "../System/In.h"


TerminalMenuItem::TerminalMenuItem(const string& question, const function<bool()>& action) {
    this->question = question;
    this->action = action;
}

string TerminalMenuItem::getQuestion() {
    return question;
}

function<bool()> TerminalMenuItem::getAction() {
    return action;
}
