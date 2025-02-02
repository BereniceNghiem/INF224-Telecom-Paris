/**
 * @file database.h
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */


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


/**
 * @class Database
 * @brief Classe pour les objets multimédias
 * 
 * Classe qui sert à fabriquer et manipuler tous les objets de manière cohérente
 * Fournit les méthodes pour créer un objet multimédia, afficher ses attributs ou encore le jouer
 */

class Database {

private:
    std::map<std::string, std::shared_ptr<Multimedia>> mediaTable; // Tableau associatif contenant les objets multimédias
    std::map<std::string, std::shared_ptr<Group>> groupTable; // Tableau associatif contenant les groupes

public:
    /**
     * @brief Méthode qui crée une photo
     *
     * @param name Le nom de l'objet photo
     * @param filename Le nom du fichier contenant l'objet photo
     * @return std::shared_ptr<Photo> Pointeur intelligent vers l'objet photo créé
     */
    std::shared_ptr<Photo> createPhoto(const std::string& name, const std::string& filename);
    /**
     * @brief Méthode qui crée une vidéo
     *
     * @param name Le nom de l'objet vidéo
     * @param filename Le nom du fichier contenant l'objet vidéo
     * @param duration La durée de la vidéo
     * @return std::shared_ptr<Video> Pointeur intelligent vers l'objet vidéo créé
     */
    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& filename, int duration);
    /**
     * @brief Méthode qui crée un film
     *
     * @param name Le nom de l'objet film
     * @param filename Le nom du fichier contenant l'objet film
     * @param duration La durée de la vidéo
     * @param durationChapters Tableau d'entiers contenant la durée de chaque chapitre
     * @param count Nombre de chapitres
     * @return std::shared_ptr<Film> Pointeur intelligent vers l'objet film créé
     */
    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& filename, int duration, const int* durationChapters, size_t count);
    /**
     * @brief Méthode qui crée un groupe
     *
     * @param name Le nom du groupe
     * @return std::shared_ptr<Group> Pointeur intelligent vers le groupe créé
     */
    std::shared_ptr<Group> createGroup(const std::string& name);

    /**
     * @brief Méthode qui trouve et affiche les valeurs d'un multimédia
     *
     * @param name Le nom l'objet multimédia
     */
    void findMedia(const std::string& name, std::ostream& out) const;
    /**
     * @brief Méthode qui trouve et affiche les valeurs d'un groupe
     *
     * @param name Le nom du groupe
     */
    void findGroup(const std::string& name, std::ostream& out) const;


    /**
     * @brief Méthode qui joue un multimédia
     *
     * @param name Le nom l'objet multimédia
     */
    void playMedia(const std::string& name) const;

    /**
     * @brief Méthode qui supprime un objet multimédia
     *
     * @param name Le nom de l'objet multimédia
     */
    void deleteMedia(const std::string& name);
    /**
     * @brief Méthode qui supprime un groupe
     *
     * @param name Le nom du groupe
     */
    void deleteGroup(const std::string& name);
};

#endif // DATABASE_H