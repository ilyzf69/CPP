#include <iostream>
#include <string>

class Boxeur {
private:
    std::string nom;
    std::string adr;
    double poids;

public:
    Boxeur(const std::string& nom, const std::string& adr, double poids) : nom(nom), adr(adr), poids(poids) {}

    std::string getNom() const {
        return nom;
    }

    std::string getAdr() const {
        return adr;
    }

    double getPoids() const {
        return poids;
    }
};

int main() {
    // Instanciation d'un objet boxeur_1 de classe Boxeur (automatique)
    Boxeur boxeur_1("Marc", "26 Avenue Tony Garnier 69007", 75.0);

    // Affichage des informations de boxeur_1
    std::cout << "Adresse du boxeur 1 : " << boxeur_1.getAdr() << std::endl;
    std::cout << "Nom du boxeur 1 : " << boxeur_1.getNom() << std::endl;
    std::cout << "Poids du boxeur 1 : " << boxeur_1.getPoids() << " kg" << std::endl;

    // Instanciation d'un objet boxeur_2 de classe Boxeur (dynamique)
    Boxeur* boxeur_2 = new Boxeur("Sam", "69 Boulevard Lenine 69220", 78.0);

    // Affichage des informations de boxeur_2
    std::cout << "Adresse du boxeur 2 : " << boxeur_2->getAdr() << std::endl;
    std::cout << "Nom du boxeur 2 : " << boxeur_2->getNom() << std::endl;
    std::cout << "Poids du boxeur 2 : " << boxeur_2->getPoids() << " kg" << std::endl;

    // Libération de la mémoire allouée dynamiquement
    delete boxeur_2;

    return 0;
}
