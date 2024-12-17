#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

class Photo : public Multimedia
{
private:
    float latitude;
    float longitude;

public:
    Photo(std::string name, std::string filename, float latitude, float longitude) : Multimedia(name, filename), latitude(latitude), longitude(longitude) {

    }
    ~Photo();

    void setLatitude(float latitude);
    void setLongitude(float longitude);

    float getLatitude();
    float getLongitude();

    void displaysPhoto() {
        std::string command = "imagej " + this->getFilename() + " &";
        system(command.data());
    }
};

#endif // PHOTO_H
