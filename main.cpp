
#include "src/Encoder.h"
#include "src/FileSystem.h"
#include "src/System/Color.h"
#include "src/System/In.h"
#include "src/System/Out.h"
#include "src/System/System.h"
#include "src/TUI/TerminalMenu.h"
#include "src/TUI/TerminalMenuItem.h"

using namespace std;


int main(const int argc, const char **argv) {

    static FileSystem file;
    static Encoder encoder;
    static vector<unsigned char> data;
    TerminalMenu terminalMenu;

    Out::clear();
    Out::printHeading("RLE-Konverter");

    Out::printLn("Versuche, die mitgelieferte 'in.txt' zu encodieren.\n",FG_GREY);

    terminalMenu.addItem("Input-Datei angeben: ", [] {
        if(!In::input.empty() and file.isReadable(In::input)) {
            Out::printLn("Datei gefunden!\n",FG_LIGHT_CYAN);
            encoder.setData(file.read());
            return true;
        }
        Out::printLn("Datei nicht gefunden!",FG_LIGHT_RED);
        return false;
    });

    terminalMenu.addItem("[d]ecodieren oder [e]ncodieren: ", [] {
        if(In::input == "e") {
            data = encoder.rleEncode();
            Out::printLn("Daten erfolgreich encodiert.\n", FG_LIGHT_CYAN);
            return true;
        }
        if(In::input == "d") {
            data = encoder.rleDecode();
            Out::printLn("Daten erfolgreich decodiert.\n", FG_LIGHT_CYAN);
            return true;
        }
        Out::printLn("Bitte [d] oder [e] angeben.", FG_LIGHT_RED);
        return false;
    });

    terminalMenu.addItem("Output-Datei angeben: ", [] {
        if(!In::input.empty() and file.isWritable(In::input)) {
            file.write(data);
            Out::print("Datei wurde erfolgreich nach ");
            Out::print(In::input, FG_LIGHT_CYAN);
            Out::printLn(" konvertiert.\n");
            return true;
        }
        Out::printLn("Datei nicht schreibbar!",FG_LIGHT_RED);
        return false;
    });

    terminalMenu.run();
}

