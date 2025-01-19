#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia
{
private:
    std::string name;
    std::string filename;

public:
    Multimedia(std::string name, std::string filename);
    Multimedia();
    virtual ~Multimedia();

    void setName(std::string name);
    void setFilename(std::string filename);

    std::string getName() const;
    std::string getFilename() const;

    void printValues(std::ostream &out) const;

    virtual void display() const = 0;

};

#endif // MULTIMEDIA_H
