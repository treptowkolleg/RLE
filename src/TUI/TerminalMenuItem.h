//
// Created by BenjaminWagner on 12.11.2024.
//

#ifndef TERMINALMENUITEM_H
#define TERMINALMENUITEM_H
#include <functional>
#include <string>

using namespace std;

class TerminalMenuItem {

    string question;
    function<bool()> action;
    public:

    TerminalMenuItem(const string &question, const function<bool()> &action);

    string getQuestion();

    function<bool()> getAction();

};

#endif //TERMINALMENUITEM_H
