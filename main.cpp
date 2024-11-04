
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

    // Schritt 1: Daten einlesen
    FileSystem inputFile;
    const vector<unsigned char> inputData = inputFile.read(argv[2]);

    // Schritt 2: Daten de- oder encodieren
    vector<unsigned char> encoded_data;

    // Encoder instantiieren
    const Encoder encoder(inputData);

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
    FileSystem outputFile;
    outputFile.write(argv[3], encoded_data);

    cout << argv[2] << " wurde erfolgreich mit " << argv[1] << " nach " << argv[3] <<  " konvertiert." << endl;
    return 0;
}

