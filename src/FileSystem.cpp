//
// Created by BenjaminWagner on 04.11.2024.
//

#include "FileSystem.h"

#include <iostream>
#include <vector>

FileSystem::FileSystem() = default;

bool FileSystem::open(const string& file, const string& mode) {
    this->file = fopen(file.c_str(), mode.c_str());
    if (!this->file) {
        return false;
    }
    return true;
}

vector<unsigned char> FileSystem::read(const string& file) {

    if(!this->open(file, "rb")) {
        cerr << "Fehler beim Öffnen der Eingabedatei!" << endl;
        exit(23);
    }

    vector<unsigned char> buffer;
    unsigned char temp[4096]; // Temporärer Puffer
    size_t bytes_read;

    // Buffer beschreiben
    while ((bytes_read = fread(temp, sizeof(unsigned char), sizeof(temp), this->file)) > 0) {
        buffer.insert(buffer.end(), temp, temp + bytes_read);
    }
    close();
    return buffer;
}

void FileSystem::write(const string& file, const vector<unsigned char>& data) {

    if(!this->open(file, "wb")) {
        cerr << "Fehler beim Öffnen der Ausgabedatei!" << endl;
        exit(5);
    }

    const size_t bytes_written = fwrite(data.data(), sizeof(unsigned char), data.size(), this->file);
    if (bytes_written != data.size()) {
        cerr << "Fehler beim Schreiben in die Ausgabedatei!" << endl;
        exit(6);
    }
    close();
}

void FileSystem::close() const {
    fclose(this->file);
}






