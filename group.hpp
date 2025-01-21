#ifndef GROUP_H
#define GROUP_H
#include "multimedia.h"

#include <iostream>
#include <list>
#include <string>
#include <memory>

using MultimediaPtr = std::shared_ptr<Multimedia>;  // Alias pour std::shared_ptr<Multimedia>

class Group : public std::list<MultimediaPtr> {
private:
    std::string name; 

public:
    //explicit Group(const std::string& groupName) : name(groupName) {}

    Group() : name("") {}
    Group(const std::string& groupName) : name(groupName) {}

    virtual ~Group() {}

    const std::string& getName() const {
        return name;
    }

    void display() const {
        std::cout << "Groupe: " << name << std::endl;
        for (const auto& multimedia : *this) {
            multimedia->display();
            std::cout << std::endl;
        }
    }
};

#endif // GROUP_H

