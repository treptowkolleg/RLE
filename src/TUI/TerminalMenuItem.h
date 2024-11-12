//
// Created by BenjaminWagner on 12.11.2024.
//

#ifndef TERMINALMENUITEM_H
#define TERMINALMENUITEM_H
#include <functional>
#include <string>

using namespace std;

class TerminalMenuItem {
    public:
    // TODO: Nachfragen, wie Closures als Argument übergeben werden können.
    TerminalMenuItem(const string &question, const function<bool(string input)> &action);
};

#endif //TERMINALMENUITEM_H
