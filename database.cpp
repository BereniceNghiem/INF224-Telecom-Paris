#include "database.h"
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <algorithm>


std::shared_ptr<Multimedia> Database::createMultimedia(const std::string & type) {
        if (type == "Photo") return std::make_shared<Photo>();
        else if (type == "Video") return std::make_shared<Video>();
        else if (type == "Film") return std::make_shared<Film>();
        return nullptr;
    }

std::shared_ptr<Photo> Database::createPhoto(const std::string& name, const std::string& filename) {
    if (mediaTable.find(name) != mediaTable.end()) {
        throw DuplicateName();
    }

    if (!std::regex_match(name, std::regex("^[a-zA-Z0-9_]+$"))) {
        throw InvalidName();
    }

    auto photo = std::make_shared<Photo>(name, filename);
    mediaTable[name] = photo;
    return photo;
}

std::shared_ptr<Video> Database::createVideo(const std::string& name, const std::string& filename, int duration) {
    if (mediaTable.find(name) != mediaTable.end()) {
        throw DuplicateName();
    }

    if (!std::regex_match(name, std::regex("^[a-zA-Z0-9_]+$"))) {
        throw InvalidName();
    }

    auto video = std::make_shared<Video>(name, filename, duration);
    mediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> Database::createFilm(const std::string& name, const std::string& filename, int duration, const int* durationChapters, size_t count) {
    if (mediaTable.find(name) != mediaTable.end()) {
        throw DuplicateName();
    }

    if (!std::regex_match(name, std::regex("^[a-zA-Z0-9_]+$"))) {
        throw InvalidName();
    }

    auto film = std::make_shared<Film>(name, filename, duration, durationChapters, count);
    mediaTable[name] = film;
    return film;
}

std::shared_ptr<Group> Database::createGroup(const std::string& name) {
    if (groupTable.find(name) != groupTable.end()) {
        throw DuplicateName();
    }

    if (!std::regex_match(name, std::regex("^[a-zA-Z0-9_]+$"))) {
        throw InvalidName();
    }

    auto group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void Database::findMedia(const std::string& name, std::ostream& out) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->printValues(out);
    } else {
        out << "Objet multimédia '" << name << "' non trouvé.";
    }
}

void Database::findGroup(const std::string& name, std::ostream& out) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->printValues(out);
    } else {
        out << "Groupe '" << name << "' non trouvé.";
    }
}

void Database::playMedia(const std::string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Objet multimédia '" << name << "' non trouvé." << std::endl;
    }
}

void Database::deleteMedia(const std::string& name) {
    if (mediaTable.find(name) == mediaTable.end()) {
        throw NotFound();
    }
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {                        // enlever le média dans chaque groupe
        mediaTable.erase(it);
        std::cout << "Objet multimédia '" << name << "' supprimé." << std::endl;
    } else {
        std::cout << "Objet multimédia '" << name << "' non trouvé." << std::endl;
    }
}

void Database::deleteGroup(const std::string& name) {
    if (groupTable.find(name) == groupTable.end()) {
        throw NotFound();
    }
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);
        std::cout << "Groupe '" << name << "' supprimé." << std::endl;
    } else {
        std::cout << "Groupe '" << name << "' non trouvé." << std::endl;
    }
}



bool Database::saveAll(const std::string & filename) {
    std::ofstream f(filename);
    if (!f) {   // vérifier que le ficher est ouvert
        std::cerr << "Can't open file " << filename << std::endl;
        return false;
    }
    for (auto& it : mediaTable) {
        f << it.second->getType() << '\n'; // écrire la classe puis les attributs
        it.second->write(f);
    }
    if (f.fail()) {                       
        std::cerr << "Write error in " << filename << std::endl;
        return false;
    } 
    return true;
}

bool Database::readAll(const std::string & filename) {
    std::ifstream f(filename);
    if (!f) {
        std::cerr << "Can't open file " << filename << std::endl;
        return false;
    }
    std::string line;  
    while (std::getline(f,line)) {
        std::shared_ptr<Multimedia> obj = createMultimedia(line);  // factory qui crée les objets
        if (obj) {
            obj->read(f);  // pareil que (*obj).read(f);
        } else {
            std::cerr << "Unknown multimedia type: " << line << std::endl;
            return false;
        }
        if (f.fail()) {                       
            std::cerr << "Read error in " << filename << std::endl;
            return false;
        } 
        else{
            mediaTable[obj->getName()] = obj;
        }
    }
    return true; 
}



