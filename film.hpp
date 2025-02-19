/**
 * @file film.hpp
 * @author Bérénice Nghiêm (berenice.nghiem@telecom-paris.fr)
 */

#ifndef FILM_H
#define FILM_H
#include "video.hpp"


/**
 * @class Film
 * @brief Classe pour les objets de type film
 * 
 * Classe Film dérivant de la classe Video
 * Les films comportent des chapitres permettant d'accéder rapidement à une partie du film
 * Fournit les méthodes pour définir les chapitre, retourner les durées et le nombre de chapitres, afficher la durée des chapitres
 */
class Film : public Video
{
private:
    int* chapterDurations{}; // tableau d'entiers contenant la durée de chaque chapitre
    int chapters{}; // nombre de chapitres

public:
    /**
     * @brief Constructeur par défaut de la classe Film
     * Initialise l'objet film avec un nom vide et un nom de fichier vide
     */
    Film() : Video() {}
    /**
     * @brief Constructeur de la classe Film
     *
     * @param name Le nom de l'objet film
     * @param filename Le nom du fichier contenant l'objet film
     */
    Film(std::string name, std::string filename) : Video(name, filename, duration) {}
    /**
     * @brief Constructeur de la classe Film avec paramètres
     *
     * @param name Le nom de l'objet film
     * @param filename Le nom du fichier contenant l'objet film
     * @param duration La durée de la vidéo
     * @param durationsTab Tableau d'entiers contenant la durée de chaque chapitre
     * @param n Nombre de chapitres
     */
    Film(std::string name, std::string filename, int duration, const int* chapDurations, int n) : Video(name, filename, duration) {
        setChapters(chapDurations, n);
    }
    /**
     * @brief Destructeur pour la classe Film
     */ 
    ~Film() override {
        delete[] chapterDurations;
    }

    /**
    * @brief Méthode pour définir les chapitres du film
    *
    * @param durations Tableau d'entiers contenant la durée de chaque chapitre
    * @param n Nombre de chapitres
    */
    void setChapters(const int* durations, int n) {
        delete[] chapterDurations;
        chapters = n;

        // exceptions : pointeur nul, n = 0, n < 0
        if (durations == nullptr) {
            chapters = 0;
            return;
        }

        else if (n==0) {
            chapterDurations = nullptr;
            return;
        }

        else if (n<0) {
            throw std::invalid_argument("Nombre de chapitres négatif");
        }

        chapterDurations = new int[chapters];
        for (int i = 0; i < chapters; i++) {
            chapterDurations[i] = durations[i];
        }
    }

    /**
     * @brief Méthode pour obtenir les durées des chapitres du film
     *
     * @return const int* Tableau d'entiers contenant la durée de chaque chapitre
     */
    const int* getChapterDurations() const {
        return chapterDurations;
    }

    /**
     * @brief Méthode pour obtenir le nombre de chapitres du film
     *
     * @return int Nombre de chapitres
     */
    int getChapters() const {
        return chapters;
    }

    /**
     * @brief Méthode pour obtenir le type de l'objet film
     *
     * @return std::string Type de l'objet film
     */
    std::string getType() const override {
        return "Film";
    }

    /**
     * @brief Méthode pour écrire les valeurs de l'objet film dans un fichier
     *
     * @param f Flux de sortie
     */
   void write(std::ostream& f) const override {
        Video::write(f);
        f << chapters << '\n';
        for (int i = 0; i < chapters; ++i) {
            f << chapterDurations[i] << "\n";
        }
    }
    
    /**
     * @brief Méthode pour lire les valeurs de l'objet film depuis un fichier, puis on les met dans la mémoire volatile
     *
     * @param f Flux d'entrée
     */
    void read(std::istream& f) override {
        Video::read(f);
        f >> chapters;
        delete[] chapterDurations;
        chapterDurations = new int[chapters];
        for (int i = 0; i < chapters; ++i) {
            f >> chapterDurations[i];
        }
        std::string endline;
        getline(f, endline);
    }

    /**
     * @brief Méthode pour afficher les valeurs de l'objet film
     *
     * @param out Flux de sortie
     */
    void printValues(std::ostream& out) const override {
        Video::printValues(out);
        out << "Chapters (" << chapters << "): ";
        if (chapterDurations) {
            for (int i = 0; i < chapters; ++i) {
                out << chapterDurations[i] << " ";
            }
        } else {
            out << "No chapters.";
        }
    }

};

#endif // FILM_H
