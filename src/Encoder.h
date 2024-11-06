//
// Created by BenjaminWagner on 04.11.2024.
//

#ifndef ENCODER_H
#define ENCODER_H

#include <vector>

using namespace std;

class Encoder {

    vector<unsigned char> buffer;

    public:
    Encoder() = default;
    explicit Encoder(const vector<unsigned char> &buffer);
    void setData(const vector<unsigned char> &buffer);
    vector<unsigned char> rle_encode() const;
    vector<unsigned char> rle_decode() const;

};



#endif //ENCODER_H
