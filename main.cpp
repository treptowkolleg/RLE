
#include <thread>

#include "src/Encoder.h"
#include "src/FileSystem.h"
#include "src/System/Color.h"
#include "src/System/In.h"
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
        In::readLine(inputFileName, "Input-Datei angeben: ");
        if(!inputFileName.empty() and inputFile.isReadable(inputFileName)) {
            Out::printLn("Datei gefunden!",FG_LIGHT_CYAN);
            Out::printLn("");
            encoder.setData(inputFile.read());
            break;
        }
        Out::printLn("Datei nicht gefunden!",FG_LIGHT_RED);
    }

    while (true) {
        In::readLine(action, "[d]ecodieren oder [e]ncodieren: ");
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
    Out::printLn("Daten erfolgreich konvertiert.", FG_LIGHT_CYAN);
    Out::printLn("");

    while (true) {
        In::readLine(outputFileName,  "Output-Datei angeben: ");
        if(!outputFileName.empty() and outputFile.isWritable(outputFileName)) {
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

    Out::print("Programm wird beendet ");
    int i = 10;
    while (i > 0) {
        this_thread::sleep_for(chrono::milliseconds(250));
        Out::print(".");
        i--;
    }
    return 0;
}

