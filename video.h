#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"

class Video : public Multimedia
{
private:
    int duration;

public:
    Video(std::string name, std::string filename, int duration) : Multimedia(name, filename), duration(duration) {
    }
    ~Video();

    void setDuration(int duration);

    int getDuration();

    void displaysVideo() {
        std::string command = "mpv " + this->getFilename() + " &";
        system(command.data());
    }
};

#endif // VIDEO_H
