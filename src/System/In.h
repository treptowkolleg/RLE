//
// Created by BenjaminWagner on 06.11.2024.
//

#ifndef IN_H
#define IN_H
#include <string>

using namespace std;

class In {

    public:
    static void readLine(string &target, const string &text = "Eingabe: ");
    static string &getInput();

    static inline string input;
};



#endif //IN_H
