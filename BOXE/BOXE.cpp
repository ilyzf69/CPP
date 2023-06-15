#include <iostream>
#include <string>

class Boxeur {
private:
    std::string nom;
    std::string adr;
    double poids;
    double poid;

public:
    Boxeur(const std::string& nom, const std::string& adr, double poids, double poid) : nom(nom), adr(adr), poids(poids), poid(poid) {}

    std::string getNom() const {
        return nom;
    }

    std::string getAdr() const {
        return adr;
    }

    double getPoids() const {
        return poids;
    }

    double getPoid() const {
        return poid;
    }
};

class Combat {
private:
    std::string niveau;
    std::string adr;
    Boxeur* coinBleu;
    Boxeur* coinRouge;

public:
    Combat(const std::string& niveau, const std::string& adr) : niveau(niveau), adr(adr), coinBleu(nullptr), coinRouge(nullptr) {}

    std::string getNiveau() const {
        return niveau;
    }

    std::string getAdr() const {
        return adr;
    }

    Boxeur* getCoinBleu() const {
        return coinBleu;
    }

    Boxeur* getCoinRouge() const {
        return coinRouge;
    }

    void setCoinBleu(Boxeur* boxeur) {
        if (boxeur != coinRouge) {
            coinBleu = boxeur;
        }
        else {
            std::cout << "Erreur : Le même boxeur ne peut pas être dans les deux coins !" << std::endl;
        }
    }

    void setCoinRouge(Boxeur* boxeur) {
        if (boxeur != coinBleu) {
            coinRouge = boxeur;
        }
        else {
            std::cout << "Erreur : Le même boxeur ne peut pas être dans les deux coins !" << std::endl;
        }
    }
};

int main() {
    // Instanciation d'un objet boxeur_1 de classe Boxeur (automatique)
    Boxeur boxeur_1("Marc", "26 Avenue Tony Garnier 69007", 75.0, 0.0);

    // Affichage des informations de boxeur_1
    std::cout << "Nom du boxeur 1 : " << boxeur_1.getNom() << std::endl;
    std::cout << "Poids du boxeur 1 : " << boxeur_1.getPoids() << " kg" << std::endl;
    std::cout << "Adresse du boxeur 1 : " << boxeur_1.getAdr() << std::endl;

    // Instanciation d'un objet boxeur_2 de classe Boxeur (dynamique)
    Boxeur* boxeur_2 = new Boxeur("Sam", "69 Boulevard Lenine 69220", 78.0, 0.0);

    // Affichage des informations de boxeur_2
    std::cout << "\nNom du boxeur 2 : " << boxeur_2->getNom() << std::endl;
    std::cout << "Poids du boxeur 2 : " << boxeur_2->getPoids() << " kg" << std::endl;
    std::cout << "Adresse du boxeur 2 : " << boxeur_2->getAdr() << std::endl;

    // Instanciation d'un objet combat_1 de classe Combat (automatique)
    Combat combat_1("1/8 de finale", "Adresse du combat");

    // Association entre combat_1 et boxeur_1
    combat_1.setCoinBleu(&boxeur_1);

    // Association entre combat_1 et boxeur_2
    combat_1.setCoinRouge(boxeur_2);

    // Affichage des informations de combat_1
    std::cout << "\nLes combats de boxes vont bientot commencer, nous allons assister a " << combat_1.getCoinBleu()->getNom() << " vs " << combat_1.getCoinRouge()->getNom() << " dans la salle : " << combat_1.getAdr() << std::endl;
    std::cout << "\nLe boxeur qui prend le coin bleu est : " << combat_1.getCoinBleu()->getNom() << std::endl;
    std::cout << "Le boxeur qui prend le coin rouge est : " << combat_1.getCoinRouge()->getNom() << std::endl;

    // Liberation de la memoire allouee dynamiquement
    delete boxeur_2;

    return 0;
}
