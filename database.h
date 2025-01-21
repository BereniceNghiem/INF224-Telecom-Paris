#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include "multimedia.h"
#include "photo.hpp"
#include "video.hpp"
#include "film.hpp"
#include "group.hpp"

class Database {
private:
    std::map<std::string, std::shared_ptr<Multimedia>> mediaTable;
    std::map<std::string, std::shared_ptr<Group>> groupTable;

public:
    std::shared_ptr<Photo> createPhoto(const std::string& name, const std::string& filename);
    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& filename, int duration);
    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& filename, int duration, const int* durations, size_t count);
    std::shared_ptr<Group> createGroup(const std::string& name);

    void displayMedia(const std::string& name) const;

    void displayGroup(const std::string& name) const;

    void playMedia(const std::string& name) const;

    void deleteMedia(const std::string& name);

    void deleteGroup(const std::string& name);
};

#endif // DATABASE_H