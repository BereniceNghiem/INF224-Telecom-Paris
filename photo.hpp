/**
 * @file photo.hpp
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */

#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"
#include <sstream>

/**
 * @class Photo
 * @brief Classe pour les objets de type photo
 * 
 * Classe qui sert à créer et manipuler des objets de type photo
 * Fournit les méthodes pour créer un objet photo, afficher ses valeurs, ou encore l'afficher
 */

class Photo : public Multimedia
{
private:
    float latitude{}; // Latitude de la photo
    float longitude{}; // Longitude de la photo

public:
    /**
     * @brief Constructeur par défaut de la classe Photo
     * Initialise l'objet photo avec un nom vide et un nom de fichier vide
     */
    Photo() : Multimedia() {}
    /**
     * @brief Constructeur de la classe Photo
     *
     * @param name Le nom de l'objet photo
     * @param filename Le nom du fichier contenant l'objet photo
     */
    Photo(std::string name, std::string filename) : Multimedia(name, filename) {}
    /**
     * @brief Constructeur de la classe Photo avec paramètres
     *
     * @param name Le nom de l'objet photo
     * @param filename Le nom du fichier contenant l'objet photo
     * @param latitude La latitude de la photo
     * @param longitude La longitude de la photo
     */
    Photo(std::string name, std::string filename, float latitude, float longitude) : Multimedia(name, filename), latitude(latitude), longitude(longitude) {
    }

    /**
     * @brief Méthode pour définir la latitude de la photo
     * 
     * @param latitude Nouvelle latitude de la photo
     */
    void setLatitude(float latitude) {
        if(latitude>0) this->latitude = latitude;
        else std::cerr << "Negative latitude" << std::endl;
    }
    /**
     * @brief Méthode pour définir la longitude de la photo
     *
     * @param longitude Nouvelle longitude de la photo
     */
    void setLongitude(float longitude) {
        if(latitude>0) this->longitude = longitude;
        else std::cerr << "Negative longitude" << std::endl;
    }

    /**
     * @brief Méthode pour obtenir la latitude de la photo
     *
     * @return float Latitude de la photo
     */
    float getLatitude() const {
        return latitude;
    }
    /**
     * @brief Méthode pour obtenir la longitude de la photo
     *
     * @return float Longitude de la photo
     */
    float getLongitude() const {
        return longitude;
    }

    /**
     * @brief Méthode pour obtenir le type de l'objet photo
     *
     * @return std::string Type de l'objet photo
     */
    std::string getType() const override {
        return "Photo";
    }

    /**
     * @brief Méthode pour écrire les valeurs de l'objet photo dans un fichier
     *
     * @param f Flux de sortie
     */
    void write(std::ostream& f) const override {
        Multimedia::write(f);
        f << latitude << '\n' << longitude << '\n';
    }

    /**
     * @brief Méthode pour lire les valeurs de l'objet photo depuis un fichier
     *
     * @param f Flux d'entrée
     */
    void read(std::istream& f) override {
        Multimedia::read(f);
        std::string endline;
        f >> latitude >> longitude;
        getline(f, endline);
    }

    /**
     * @brief Méthode pour afficher les valeurs de l'objet photo
     *
     * @param out Flux de sortie
     */
    void printValues(std::ostream& out) const override {
        out << "Nom : " << name;
        out << "Nom du ficher : " << filename;
        out << "Latitude : " << latitude; 
        out << "Longitude : " << longitude; 
    }

    /**
     * @brief Méthode pour jouer l'objet photo
     */
    void play() const override {
        std::cout << "Ceci est une photo." << std::endl;
        std::string command = "imagej " + this->getFilename() + " &";
        system(command.data());
    }
};

#endif // PHOTO_H



