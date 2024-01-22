#pragma once

#include "ImageStorageTraits.h"
#include "ppm.h"

#include <map>
#include <string>

using namespace std;

namespace graphics {
    class Image : public graphics::ImageStorageTraits {
        // unsigned char* data = nullptr;
        // int width = 0;
        // int height = 0;
        // unsigned char* pixel(unsigned int x, unsigned int y);

    public:
        //
        // Test 1
        //
        Image() : Image(800, 600) {
        }

        Image(int width, int height) {
            if (width > 0 && height > 0) {
                this->width = width;
                this->height = height;
                this->data = new unsigned char[3 * width * height];
            } else {
                this->width = 0;
                this->height = 0;
                this->data = nullptr;
            }
        }

        ~Image() {
            if (data != nullptr) {
                delete[] data;
                data = nullptr;
            }
        }

        unsigned char* operator()(int x, int y) {
            return pixel(x, y);
        }

        Image& operator=(const Image& other) {
            if ((this->width != other.width || this->height != other.height) && data != nullptr) {
                delete[] data;
                data = nullptr;
            }

            this->width = other.width;
            this->height = other.height;

            if (data == nullptr && other.width > 0 && other.height > 0) {
                this->data = new unsigned char[3 * width * height];
            }

            for (int i = 0; i < 3 * width * height; i++) {
                this->data[i] = other.data[i];
            }

            return *this;
        }

        bool operator==(const Image& other) const {
            if (this->width != other.width || this->height != other.height) {
                return false;
            }

            for (int i = 0; i < 3 * width * height; i++) {
                if (this->data[i] != other.data[i]) {
                    return false;
                }
            }

            return true;
        }

        Image(const Image& other) {
            this->width = other.width;
            this->height = other.height;

            if (other.width > 0 && other.height > 0) {
                this->data = new unsigned char[3 * width * height];

                for (int i = 0; i < 3 * width * height; i++) {
                    this->data[i] = other.data[i];
                }
            }
        }

        //
        // Test 2
        //

        // bool WritePPM(const unsigned char * data, int w, int h, std::string filename);

        bool load(const string filename) {
            int w, h;
            unsigned char* temp = ReadPPM(filename, &w, &h);

            if (temp == nullptr) {
                return false;
            }

            this->width = w;
            this->height = h;

            if (this->data != nullptr) {
                delete[] data;
            }

            data = temp;
        }

        pair<int, int> getDimensions() const {
            pair<int, int> p(width, height);
            return p;
        }

        bool save(const string filename) const {
            return WritePPM(data, width, height, filename);
        }

        //
        // Test 3
        //
        operator unsigned char*() {
            return data;
        }

        Image& operator<<(const unsigned char* const data) {
            for (int i = 0; i < 3 * width * height; i++) {
                this->data[i] = data[i];
            }
            return *this;
        }
    };
} // namespace graphics