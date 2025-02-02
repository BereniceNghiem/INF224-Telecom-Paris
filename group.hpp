/**
 * @file group.hpp
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */

#ifndef GROUP_H
#define GROUP_H
#include "multimedia.h"

#include <iostream>
#include <list>
#include <string>
#include <memory>

using MultimediaPtr = std::shared_ptr<Multimedia>;  // Alias pour std::shared_ptr<Multimedia>

/**
 * @class Group
 * @brief Classe pour les objets de type groupe
 * 
 * Classe dérivant d'une liste d'objets multimedia
 * Fournit les méthodes qui renvoie le nom du groupe et qui affiche les attributs de tous les objets de la liste
 */
class Group : public std::list<MultimediaPtr> {
private:
    std::string name; // Nom du groupe

public:
    /**
     * @brief Constructeur de la classe Group
     */
    Group() : name("") {}
    /**
     * @brief Constructeur de la classe Group avec paramètres
     * 
     * @param groupName Le nom du groupe
     */
    Group(std::string groupName) : name(groupName) {}                  

    /**
     * @brief Méthode pour obtenir le nom du groupe
     * 
     * @param groupName Nom du groupe
     */
    std::string getName() const {
        return name;
    }
 
    /**
     * @brief Méthode pour afficher le nom du groupe et les objets de la liste
     */
    void printValues(std::ostream& out) const {
        out << "Groupe: " << name;
        for (const auto& multimedia : *this) {
            multimedia->printValues(out);
        }
    }
};

#endif // GROUP_H

