//
// Created by BenjaminWagner on 04.11.2024.
//

#include "FileSystem.h"

#include <iostream>
#include <vector>

#include "System/Out.h"

/**
 * handles file reading or writing data.
 * @param file to be handled
 */
FileSystem::FileSystem(const string& file) {
    this->filename = file;
};

/**
 *
 * @param file file to be opened
 * @param mode in wich file is being handled
 * @return
 */
bool FileSystem::open(const string& file, const string& mode) {
    this->file = fopen(file.c_str(), mode.c_str());
    if (!this->file) {
        return false;
    }
    return true;
}

/**
 * Returns data from the given input file.
 * @return file content
 */
vector<unsigned char> FileSystem::read() {

    if(!this->open(this->filename, "rb")) {
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

/**
 * Writes new file to the designated path with given data.
 * @param data to be written to the output file
 */
void FileSystem::write(const vector<unsigned char>& data) {

    if(!this->open(this->filename, "wb")) {
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

bool FileSystem::isReadable(const string& file) {
    if(open(file,"rb")) {
        close();
        this->filename = file;
        return true;
    }
    return false;
}

bool FileSystem::isWritable(const string& file) {
    if(open(file,"wb")) {
        close();
        this->filename = file;
        return true;
    }
    return false;
}

/**
 * closes current handled file
 */
void FileSystem::close() {
    fclose(this->file);
    this->file = nullptr;
}






