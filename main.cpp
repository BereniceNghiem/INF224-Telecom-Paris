#include <iostream>

#include "multimedia.h"
#include "photo.h"
#include "video.h"

int main(int argc, const char* argv[])
{
    Video *v = new Video("cheval", "cheval.mp4", 0);
    v->displaysVideo();
}


//Multimedia m("nom", "chemin");
//std::cout << m.getName() << std::endl;
//return 0;


//Photo *p = new Photo("pomme", "pomme.jpg", 0, 0);
//p->displaysPhoto();