//
// Created by BenjaminWagner on 04.11.2024.
//

#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <string>
#include <vector>

using namespace std;

class FileSystem {

    string filename;
    FILE* file{};
    bool open(const string& file, const string& mode);
    void close();

    public:
    FileSystem() = default;
    explicit FileSystem(const string& file);

    vector<unsigned char> read();
    void write(const vector<unsigned char>& data);
    bool isReadable(const string& file);
    bool isWritable(const string& file);

};



#endif //FILESYSTEM_H
