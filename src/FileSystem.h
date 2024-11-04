//
// Created by BenjaminWagner on 04.11.2024.
//

#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <string>
#include <vector>

using namespace std;

class FileSystem {
    private:
    FILE* file{};
    bool open(const string& file, const string& mode);
    void close() const;

    public:
    FileSystem();

    vector<unsigned char> read(const string& file);
    void write(const string& file, const vector<unsigned char>& data);

};



#endif //FILESYSTEM_H
