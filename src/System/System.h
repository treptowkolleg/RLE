//
// Created by BenjaminWagner on 06.11.2024.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include <set>
#include <string>

using namespace std;

class System {
    set<string> tokens;
    public:

    System() {
         this->tokens= {"ende","exit","quit","abort","abbruch","bye"};
    }

    bool hasToken(const string &token);
    static void exit(const int &code = 0);
};



#endif //SYSTEM_H
