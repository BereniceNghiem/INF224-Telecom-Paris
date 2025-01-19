#include <iostream>

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "database.h"
#include <vector>


void test_multimedia() {
    Multimedia *m = new Video("nom", "chemin");
    std::cout << m->getName() << std::endl;
    delete m;
}

void play_photo() {
    Photo *p = new Photo("pomme", "pomme.jpg", 0, 0);
    p->display();
    delete p;
}

void play_video() {
    Video *v = new Video("cheval", "cheval.mp4");
    v->display();
    delete v;
}

void play_table() {
    std::vector<Multimedia*> multimediaList;
    multimediaList.push_back(new Photo("pomme", "pomme.jpg"));
    multimediaList.push_back(new Video("cheval", "cheval.mp4"));
    multimediaList.push_back(new Photo("pomme", "pomme.jpg"));
    for (const auto& multimedia : multimediaList) {
        std::cout << "=== Affichage des informations ===" << std::endl;
        multimedia->display(); 
        std::cout << std::endl;
    }

    for (const auto& multimedia : multimediaList) {
        delete multimedia;
    }
}

void test_chapters() {
    int durations[3] = {10, 6, 10};
    Film f("cheval", "cheval.mp4", 26, durations, 3);
    f.display();
}

void groups()
{
    Group group1("groupe 1");
    Group group2("groupe 2");

    group1.push_back(std::make_shared<Photo>("pomme", "pomme.jpg"));
    group1.push_back(std::make_shared<Photo>("rio", "rio.jpg"));
    group1.push_back(std::make_shared<Photo>("telecom", "telecom.jpg"));

    group2.push_back(std::make_shared<Photo>("pomme", "pomme.jpg"));
    group2.push_back(std::make_shared<Video>("cheval", "cheval.mp4"));
    int durations[3] = {10, 6, 10};
    group2.push_back(std::make_shared<Film>("cheval", "cheval.mp4", 26, durations, 3));

    group1.display();
    group2.display();

}

void database() {
    Database db;

    db.createPhoto("pomme", "pomme.jpg");
    db.createVideo("cheval", "cheval.mp4", 26);
    int durations[] = {10, 15};
    db.createFilm("cheval", "cheval.mp4", 120, durations, 2);

    auto group1 = db.createGroup("groupe1");

    db.displayMedia("pomme");

    db.playMedia("cheval");

    db.deleteMedia("pomme");

    db.deleteGroup("groupe1");
}


int main(int argc, const char* argv[])
{
    database();
}

