
#include <cstdio>
#include <iostream>
#include <thread>


#include "src/Encoder.h"
#include "src/FileSystem.h"
#include "src/System/Color.h"
#include "src/System/Out.h"

using namespace std;

int main(const int argc, const char **argv) {

    string inputFileName, outputFileName, action;
    FileSystem inputFile, outputFile;
    Encoder encoder;
    vector<unsigned char> encodedData;

    Out::clear();
    Out::printHeading("RLE-Konverter");

    while (true) {
        Out::print("Input-Datei angeben: ");
        getline(cin, inputFileName);
        if(inputFile.isReadable(inputFileName)) {
            Out::printLn("Datei gefunden!",FG_LIGHT_CYAN);
            Out::printLn("");
            encoder.setData(inputFile.read());
            break;
        }
        Out::printLn("Datei nicht gefunden!",FG_LIGHT_RED);
    }

    while (true) {
        Out::print("[d]ecodieren oder [e]ncodieren: ");
        getline(cin, action);
        if(action == "e") {
            encodedData = encoder.rle_encode();
            break;
        }
        if(action == "d") {
            encodedData = encoder.rle_decode();
            break;
        }
        Out::printLn("Bitte [d] oder [e] angeben.", FG_LIGHT_RED);
    }
    Out::printLn("Daten erfolgreich konvertiert.");
    Out::printLn("");

    while (true) {
        Out::print("Output-Datei angeben: ");
        getline(cin, outputFileName);
        if(outputFile.isWritable(outputFileName)) {
            Out::printLn("Datei schreibbar!",FG_LIGHT_CYAN);
            Out::printLn("");
            outputFile.write(encodedData);
            break;
        }
        Out::printLn("Datei nicht schreibbar!",FG_LIGHT_RED);
    }

    Out::print("Datei ");
    Out::print(inputFileName, FG_LIGHT_CYAN);
    Out::print(" wurde erfolgreich nach ");
    Out::print(outputFileName, FG_LIGHT_CYAN);
    Out::printLn(" konvertiert.");

    Out::print("Fenster wird geschlossen ");
    int i = 10;
    while (i > 0) {
        this_thread::sleep_for(chrono::milliseconds(500));
        Out::print(".");
        i--;
    }
    return 0;
}

