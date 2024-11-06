//
// Created by BenjaminWagner on 06.11.2024.
//

#include "Out.h"
#include "Color.h"

#include <cstring>
#include <string>

using namespace std;

void Out::print(const string& text, const Color& color, const Color& background) {

    printf("%s%s%s",setColor(color).c_str(),setColor(background).c_str(),text.c_str());
    printf("%s%s",setColor(FG_WHITE).c_str(),setColor(BG_NONE).c_str());
}

void Out::printLn(const string& text, const Color& color, const Color& background) {
    print(text, color, background);
    print("\n");
}

void Out::printHeading(const string &text, const Color &color, const Color &background, const int &whitespace) {
    generateFrame(text, "=",  whitespace, color, background);
}

void Out::generateFrame(const string &text, const string &frameChar, const int &whitespace, const Color &color, const Color &background) {
    string horizontalLine, whitespaceLine;
    for(int i = 1; i <= strlen(text.c_str()) + 2*whitespace+2; i++) horizontalLine += frameChar;
    for(int i = 1; i <= whitespace; i++) whitespaceLine += " ";
    printLn(horizontalLine, color, background);
    printLn(frameChar + whitespaceLine + text + whitespaceLine + frameChar, color, background);
    printLn(horizontalLine, color, background);
    printLn("");
}

void Out::clear() {
    printf("\033[2J\033[1;1H");
}

void Out::hideCursor() {
    printf("\033[?25l");
}


string Out::setColor(const Color& color) {
    return  "\033[" + color + "m";
}