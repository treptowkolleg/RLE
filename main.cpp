
#include "src/Encoder.h"
#include "src/FileSystem.h"
#include "src/System/Color.h"
#include "src/System/In.h"
#include "src/System/Out.h"
#include "src/System/System.h"

using namespace std;

int main(const int argc, const char **argv) {

    string cliInput;
    FileSystem file;
    Encoder encoder;
    vector<unsigned char> data;

    Out::clear();
    Out::printHeading("RLE-Konverter");

    Out::printLn("Versuche, die mitgelieferte 'in.txt' zu encodieren.\n",FG_GREY);

    // TODO: Input-Abfrage und Verarbeitung sind algorithmisch identisch und könnten mittels Closure-Implementierung
    // sowie ausgelagerter while-Loop erledigt werden. Sowas wie "TerminalMenu": .addItem(), .run()

    // I
    while (true) {
        In::readLine(cliInput, "Input-Datei angeben: ");
        if(!cliInput.empty() and file.isReadable(cliInput)) {
            Out::printLn("Datei gefunden!",FG_LIGHT_CYAN);
            Out::printLn("");
            encoder.setData(file.read());
            break;
        }
        Out::printLn("Datei nicht gefunden!",FG_LIGHT_RED);
    }

    // II
    while (true) {
        In::readLine(cliInput, "[d]ecodieren oder [e]ncodieren: ");
        if(cliInput == "e") {
            data = encoder.rleEncode();
            break;
        }
        if(cliInput == "d") {
            data = encoder.rleDecode();
            break;
        }
        Out::printLn("Bitte [d] oder [e] angeben.", FG_LIGHT_RED);
    }
    Out::printLn("Daten erfolgreich konvertiert.", FG_LIGHT_CYAN);
    Out::printLn("");

    // III
    while (true) {
        In::readLine(cliInput,  "Output-Datei angeben: ");
        if(!cliInput.empty() and file.isWritable(cliInput)) {
            Out::printLn("Datei schreibbar!",FG_LIGHT_CYAN);
            Out::printLn("");
            file.write(data);
            break;
        }
        Out::printLn("Datei nicht schreibbar!",FG_LIGHT_RED);
    }
    Out::print("Datei ");
    Out::print(cliInput, FG_LIGHT_CYAN);
    Out::print(" wurde erfolgreich nach ");
    Out::print(cliInput, FG_LIGHT_CYAN);
    Out::printLn(" konvertiert.");

    System::exit();
}

