#include "multimedia.h"
#include <iostream>
#include <string>

Multimedia::Multimedia(std::string name, std::string filename) {
    this->name = name;
    this->filename = filename;
}

Multimedia::~Multimedia(){
}

Multimedia::Multimedia() {
    this->name = "";
    this->filename = "";
}


void Multimedia::setName(std::string name) {
    this->name = name;
}

void Multimedia::setFilename(std::string filename) {
    this->filename = filename;
}

std::string Multimedia::getName() const{
    return name;
}

std::string Multimedia::getFilename() const{
    return filename;
}
