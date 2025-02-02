/**
 * @file multimedia.h
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

/**
 * @class Multimedia
 * @brief Classe de base de l'arbre d'héritage
 * 
 * Classe abstraite qui contient ce qui est commun à tous les objets multimédia
 */
class Multimedia
{
protected:
    std::string name; // Nom de l'objet multimédia
    std::string filename; // Nom du fichier contenant l'objet multimédia

public:
    /**
     * @brief Constructeur par défaut de la classe Multimedia
     * Initialise l'objet multimédia avec un nom vide et un nom de fichier vide
     */
    Multimedia();
    /**
     * @brief Constructeur de la classe Multimedia avec paramètres
     * 
     * @param name Le nom de l'objet multimédia
     * @param filename Le nom du fichier contenant l'objet multimédia
     */
    Multimedia(std::string name, std::string filename);
    /**
     * @brief Destructeur pour la classe Multimedia
     */
    virtual ~Multimedia();  

    /**
     * @brief Méthode pour définir le nom de l'objet multimédia
     * 
     * @param name Nouveau nom de l'objet multimédia
     */
    void setName(std::string name);
    /**
     * @brief Méthode pour définir le nom du fichier de l'objet multimédia
     * 
     * @param filename Nouveau nom de fichier de l'objet multimédia
     */
    void setFilename(std::string filename);

    /**
     * @brief Méthode pour obtenir le nom de l'objet multimédia
     *
     * @return std::string Nom de l'objet multimédia
     */
    std::string getName() const;
    /**
     * @brief Méthode pour obtenir le nom du fichier de l'objet multimédia
     *
     * @return std::string Nom du fichier de l'objet multimédia
     */
    std::string getFilename() const;

    /**
     * @brief Méthode virtuelle pour obtenir le type de l'objet multimédia
     *
     * @return std::string Type de l'objet multimédia
     */
    virtual std::string getType() const = 0; //méthode abstraite
    /**
     * @brief Méthode virtuelle pour écrire les valeurs de l'objet multimédia dans un fichier
     */
    virtual void write(std::ostream& f) const;
    /**
     * @brief Méthode virtuelle pour lire les valeurs de l'objet multimédia depuis un fichier
     */
    virtual void read(std::istream& f);
    /**
     * @brief Méthode virtuelle pour afficher les valeurs de l'objet multimédia
     */
    virtual void printValues(std::ostream& out) const;         
    /**
     * @brief Méthode virtuelle pure pour jouer l'objet multimédia
     */
    virtual void play() const = 0;   //méthode abstraite

};

#endif // MULTIMEDIA_H
