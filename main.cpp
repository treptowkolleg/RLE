
#include <cstdio>
#include <iostream>

#include "src/encoder.h"
#include "src/FileSystem.h"

using namespace std;

int main(const int argc, const char **argv) {

    if (argc < 4) {
        printf("Usage:\n %s [e|d] [INPUTFILE] [OUTPUTFILE]\n",argv[0]);
        return 42;
    }

    // Schritt 1: Input-Datei zuweisen
    FileSystem inputFile(argv[2]);

    // Encoder instantiieren und Daten einlesen
    const Encoder encoder(inputFile.read());

    // Schritt 2: Daten de- oder encodieren
    vector<unsigned char> encoded_data;

    // Aktion zuweisen
    const string command = argv[1];
    if(command == "e") {
        encoded_data = encoder.rle_encode();
    } else if(command == "d") {
        encoded_data = encoder.rle_decode();
    } else {
        printf("Der Befehl '%s' ist nicht definiert.\nNutzen Sie 'e' zum Enkodieren oder 'd' zum Dekodieren.\n",argv[1]);
        return 11;
    }

    // Schritt 3: Ausgabe schreiben
    FileSystem outputFile(argv[3]);
    outputFile.write(encoded_data);

    cout << argv[2] << " wurde erfolgreich mit " << argv[1] << " nach " << argv[3] <<  " konvertiert." << endl;
    return 0;
}

