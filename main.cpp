
#include <cstdio>
#include <iostream>

#include "src/encoder.h"

using namespace std;

int main(const int argc, const char **argv) {

    if (argc < 4) {
        printf("Usage:\n %s [e|d] [INPUTFILE] [OUTPUTFILE]\n",argv[0]);
        return 42;
    }
    
    // Schritt 1: Daten aus der Datei lesen
    FILE* input_file = fopen(argv[2], "rb");
    if (!input_file) {
        cerr << "Fehler beim Öffnen der Eingabedatei!" << endl;
        return 23;
    }

    // Puffer zum Speichern der Daten
    vector<unsigned char> buffer;
    unsigned char temp[4096]; // Temporärer Puffer
    size_t bytes_read;

    // Lese die Datei in den Puffer
    while ((bytes_read = fread(temp, sizeof(unsigned char), sizeof(temp), input_file)) > 0) {
        buffer.insert(buffer.end(), temp, temp + bytes_read);
    }

    fclose(input_file); // Input-Datei schließen

    // Schritt 2: Daten de- oder encodieren
    vector<unsigned char> encoded_data;

    const Encoder encoder(buffer);  // Encoder instantiieren

    const string command = argv[1];

    if(command == "e") {
        encoded_data = encoder.rle_encode();
    } else if(command == "d") {
        encoded_data = encoder.rle_decode();
    } else {
        printf("Der Befehl '%s' ist nicht definiert.\nNutzen Sie 'e' zum Enkodieren oder 'd' zum Dekodieren.\n",argv[1]);
        return 11;
    }

    // Schritt 3: In die neue Datei schreiben
    FILE* output_file = fopen(argv[3], "wb");
    if (!output_file) {
        cerr << "Fehler beim Öffnen der Ausgabedatei!" << endl;
        return 5;
    }

    const size_t bytes_written = fwrite(encoded_data.data(), sizeof(unsigned char), encoded_data.size(), output_file);
    if (bytes_written != encoded_data.size()) {
        cerr << "Fehler beim Schreiben in die Ausgabedatei!" << endl;
    }

    fclose(output_file); // Output-Datei schließen

    cout << argv[2] << " wurde erfolgreich mit " << argv[1] << " nach " << argv[3] <<  " konvertiert." << endl;
    return 0;
}

