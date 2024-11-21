//
// Created by BenjaminWagner on 12.11.2024.
//

#ifndef TERMINALMENU_H
#define TERMINALMENU_H
#include <vector>

#include "TerminalMenuItem.h"

using namespace std;

class TerminalMenu {

    vector<TerminalMenuItem> items;

public:
    TerminalMenu() = default;
    explicit TerminalMenu(const vector<TerminalMenuItem>& $items);
    void addItem(const TerminalMenuItem &item);
    void addItem(const string &question, const function<bool()> &action);
    void run();
};



#endif //TERMINALMENU_H
