//
// Created by BenjaminWagner on 06.11.2024.
//

#ifndef OUT_H
#define OUT_H

#include <string>

#include "Color.h"

using namespace std;

class Out {


    static void generateFrame(const string &text,const string &frameChar = "#", const int &whitespace = 1, const Color &color = FG_LIGHT_CYAN, const Color &background = BG_NONE);

    public:
    static void print(const string &text, const Color &color = FG_WHITE, const Color &background = BG_NONE);
    static void printLn(const string &text, const Color &color = FG_WHITE, const Color &background = BG_NONE);
    static void printHeading(const string &text, const Color &color = FG_LIGHT_CYAN, const Color &background = BG_NONE, const int &whitespace = 6);
    static string setColor(const Color& color);
    static void clear();
};



#endif //OUT_H
