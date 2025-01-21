#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

class Photo : public Multimedia
{
private:
    float latitude;
    float longitude;

public:
    Photo(std::string name, std::string filename) : Multimedia(name, filename), latitude(0), longitude(0) {}
    Photo(std::string name, std::string filename, float latitude, float longitude) : Multimedia(name, filename), latitude(latitude), longitude(longitude) {

    }
    ~Photo() override {};

    void setLatitude(float latitude);
    void setLongitude(float longitude);

    float getLatitude();
    float getLongitude();

    void display() const override {
        std::cout << "Ceci est une photo." << std::endl;
        std::string command = "imagej " + this->getFilename() + " &";
        system(command.data());
    }
};

#endif // PHOTO_H



