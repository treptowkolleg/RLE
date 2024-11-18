
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
    // Beispiel: auto f = [&] () { // Aktion implementieren };

    // I
    while (true) {
        In::readLine(cliInput, "Input-Datei angeben: ");
        if(!cliInput.empty() and file.isReadable(cliInput)) {
            Out::printLn("Datei gefunden!\n",FG_LIGHT_CYAN);
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
            Out::printLn("Daten erfolgreich encodiert.\n", FG_LIGHT_CYAN);
            break;
        }
        if(cliInput == "d") {
            data = encoder.rleDecode();
            Out::printLn("Daten erfolgreich decodiert.\n", FG_LIGHT_CYAN);
            break;
        }
        Out::printLn("Bitte [d] oder [e] angeben.", FG_LIGHT_RED);
    }

    // III
    while (true) {
        In::readLine(cliInput,  "Output-Datei angeben: ");
        if(!cliInput.empty() and file.isWritable(cliInput)) {
            file.write(data);
            Out::print("Datei wurde erfolgreich nach ");
            Out::print(cliInput, FG_LIGHT_CYAN);
            Out::printLn(" konvertiert.\n");
            break;
        }
        Out::printLn("Datei nicht schreibbar!",FG_LIGHT_RED);
    }

    System::exit();
}

