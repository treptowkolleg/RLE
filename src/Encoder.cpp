//
// Created by BenjaminWagner on 04.11.2024.
//

#include "Encoder.h"

#include <vector>

using namespace std;

/**
 * Encode or decode data using the RLE-algorithm.
 * @param buffer data to be encoded or decoded
 */
Encoder::Encoder(const vector<unsigned char> &buffer) {
    this->buffer = buffer;
};

void Encoder::setData(const vector<unsigned char> &buffer) {
    this->buffer = buffer;
}

/**
 * encode data with RLE-algorithm
 * @return encoded data
 */
vector<unsigned char> Encoder::rle_encode() const {
    vector<unsigned char> encoded;


    for (size_t i = 0; i < buffer.size(); ) {
        unsigned char current_byte = buffer[i];
        size_t count = 1;

        // Zähle die Anzahl der aufeinanderfolgenden gleichen Bytes
        while (i + 1 < buffer.size() && buffer[i + 1] == current_byte) {
            count++;
            i++;
            if (count == 255) {  // Maximal 255 für einen einzelnen Wert
                break;
            }
        }

        // Füge das aktuelle Byte und die Anzahl hinzu
        encoded.push_back(current_byte);
        encoded.push_back(static_cast<unsigned char>(count));
        i++;
    }

    return encoded;
}

/**
 * decode data with RLE-algorithm
 * @return decoded data
 */
vector<unsigned char> Encoder::rle_decode() const {
    vector<unsigned char> decoded;

    for (size_t i = 0; i < buffer.size(); i += 2) {
        unsigned char byte_value = buffer[i];           // Das aktuelle Byte
        const unsigned char count = buffer[i + 1];      // Die Anzahl der Wiederholungen

        // Füge das Byte 'count' mal zu den dekodierten Daten hinzu
        decoded.insert(decoded.end(), count, byte_value);
    }

    return decoded;
}
