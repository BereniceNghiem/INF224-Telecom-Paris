#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"

class Video : public Multimedia
{
private:
    int duration;

public:
    Video(std::string name, std::string filename) : Multimedia(name, filename), duration(0) {}
    Video(std::string name, std::string filename, int duration) : Multimedia(name, filename), duration(duration) {
    }
    ~Video() override {};

    void setDuration(int duration);

    int getDuration();

    void display() const override {
        std::cout << "Ceci est une vidéo." << std::endl;
        std::string command = "mpv " + this->getFilename() + " &";
        system(command.data());
    }
};

#endif // VIDEO_H
