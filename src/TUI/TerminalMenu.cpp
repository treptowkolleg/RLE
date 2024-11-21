//
// Created by BenjaminWagner on 12.11.2024.
//

#include "TerminalMenu.h"

#include "../System/In.h"
#include "../System/System.h"

TerminalMenu::TerminalMenu(const vector<TerminalMenuItem>& $items) {
    this->items = $items;
}

void TerminalMenu::addItem(const TerminalMenuItem& item) {
    this->items.push_back(item);
}

void TerminalMenu::addItem(const string &question, const function<bool()>&action) {
    this->items.emplace_back(question, action);
}

void TerminalMenu::run() {
    for (TerminalMenuItem& item : this->items) {
        while (true) {
            In::readLine(In::input, item.getQuestion());
            if(function<bool()> action = item.getAction(); action()) {
                break;
            }
        }
    }
    System::exit();
}
