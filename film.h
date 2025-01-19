#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{
private:
    int* chapterDurations;
    int numChapters;

public:
    //Film(std::string name, std::string filename) : Video(name, filename, duration), chapterDurations(nullptr), numChapters(0) {}
    Film(std::string name, std::string filename, int duration, const int* durations, int n) : Video(name, filename, duration), numChapters(n) {
        setChapters(durations, n);
    }

    ~Film() override {
        if (chapterDurations != nullptr) {
            delete[] chapterDurations;
        }
    }

    void setChapters(const int* durations, int n) {
        if (chapterDurations != nullptr) {
            delete[] chapterDurations;
        }
        numChapters = n;
        chapterDurations = new int[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterDurations[i] = durations[i];
        }
    }

    const int* getChapters() const {
        return chapterDurations;
    }

    int getNumChapters() const {
        return numChapters;
    }

    void display() const override {
        Video::display(); 
        std::cout << "Chapters (" << numChapters << "): ";
        if (chapterDurations) {
            for (int i = 0; i < numChapters; ++i) {
                std::cout << chapterDurations[i] << " ";
            }
        } else {
            std::cout << "No chapters.";
        }
        std::cout << std::endl;
    }

};

#endif // FILM_H
