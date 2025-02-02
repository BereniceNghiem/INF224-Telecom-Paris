/**
 * @file video.hpp
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */

#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"
#include <sstream>


/**
 * @class Video
 * @brief Classe pour les objets de type vidéo
 * 
 * Classe qui sert à créer et manipuler des objets de type vidéo
 * Fournit les méthodes pour créer un objet vidéo, afficher ses valeurs, ou encore l'afficher
 */
class Video : public Multimedia
{
protected:
    int duration{}; // Durée de la vidéo

public:
    /**
     * @brief Constructeur par défaut de la classe Vidéo
     * Initialise l'objet vidéo avec un nom vide et un nom de fichier vide
     */
    Video() : Multimedia() {}
    /**
     * @brief Constructeur de la classe Vidéo
     *
     * @param name Le nom de l'objet vidéo
     * @param filename Le nom du fichier contenant l'objet vidéo
     */
    Video(std::string name, std::string filename) : Multimedia(name, filename) {}
    /**
     * @brief Constructeur de la classe Vidéo avec paramètres
     *
     * @param name Le nom de l'objet vidéo
     * @param filename Le nom du fichier contenant l'objet vidéo
     * @param duration La durée de la vidéo
     */
    Video(std::string name, std::string filename, int duration) : Multimedia(name, filename), duration(duration) {
    }

    /**
     * @brief Méthode pour définir la durée de la vidéo
     *
     * @param duration Nouvelle durée de la vidéo
     */
    void setDuration(int duration) {
        this -> duration = duration;
    }

    /**
     * @brief Méthode pour obtenir la durée de la vidéo
     *
     * @return int Durée de la vidéo
     */
    int getDuration() const {
        return duration;
    }

    /**
     * @brief Méthode pour obtenir le type de l'objet vidéo
     *
     * @return std::strig Type de l'objet vidéo
     */
    std::string getType() const override{
        return "Video";
    }

    /**
     * @brief Méthode pour écrire les valeurs de l'objet vidéo dans un fichier
     *
     * @param f Flux de sortie
     */
    void write(std::ostream& f) const override {
        f << name << '\n';
        f << filename << '\n';
        f << duration << '\n';
    }

    /**
     * @brief Méthode pour lire les valeurs de l'objet vidéo depuis un fichier
     *
     * @param f Flux d'entrée
     */
    void read(std::istream& f) override {
        f >> name >> filename >> duration;
    }

    /**
     * @brief Méthode pour afficher les valeurs de l'objet vidéo
     *
     * @param out Flux de sortie
     */
    void printValues(std::ostream& out) const override {
        out << "Nom : " << name;
        out << "Nom du ficher : " << filename;
        out << "Durée : " << duration; 
    }

    /**
     * @brief Méthode pour jouer la vidéo
     */
    void play() const override {
        std::cout << "Ceci est une vidéo." << std::endl;
        std::string command = "mpv " + this->getFilename() + " &";
        system(command.data());
    }
};

#endif // VIDEO_H
