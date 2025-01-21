#include "database.h"
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <algorithm>


std::shared_ptr<Photo> Database::createPhoto(const std::string& name, const std::string& filename) {
        auto photo = std::make_shared<Photo>(name, filename);
        mediaTable[name] = photo;
        return photo;
    }

std::shared_ptr<Video> Database::createVideo(const std::string& name, const std::string& filename, int duration) {
    auto video = std::make_shared<Video>(name, filename, duration);
    mediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> Database::createFilm(const std::string& name, const std::string& filename, int duration, const int* durations, size_t count) {
    auto film = std::make_shared<Film>(name, filename, duration, durations, count);
    mediaTable[name] = film;
    return film;
}

std::shared_ptr<Group> Database::createGroup(const std::string& name) {
    auto group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void Database::displayMedia(const std::string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->display();
    } else {
        std::cout << "Objet multimédia '" << name << "' non trouvé." << std::endl;
    }
}

void Database::displayGroup(const std::string& name) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        std::cout << "Groupe '" << name << "' : " << std::endl;
        it->second->display();
    } else {
        std::cout << "Groupe '" << name << "' non trouvé." << std::endl;
    }
}

void Database::playMedia(const std::string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->display();
    } else {
        std::cout << "Objet multimédia '" << name << "' non trouvé." << std::endl;
    }
}

void Database::deleteMedia(const std::string& name) {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        mediaTable.erase(it);
        std::cout << "Objet multimédia '" << name << "' supprimé." << std::endl;
    } else {
        std::cout << "Objet multimédia '" << name << "' non trouvé." << std::endl;
    }
}

void Database::deleteGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);
        std::cout << "Groupe '" << name << "' supprimé." << std::endl;
    } else {
        std::cout << "Groupe '" << name << "' non trouvé." << std::endl;
    }
}


