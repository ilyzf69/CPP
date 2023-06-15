#include <iostream>
#include <string>




int main() {
    // Instanciation d'un objet boxeur_1 de classe Boxeur (automatique)
    Boxeur boxeur_1("Marc", "26 Avenue Tony Garnier 69007", 75.0, 0.0);
    Boxeur boxeur_3("Jean", "48 rue Paul Bert 69960", 83.0, 0.0);
    Boxeur boxeur_4("Mowgli", "23 Avenue Voltaire 69200", 95.0, 0.0);


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
    Combat combat_1("1/2 de finale", "Adresse du combat");

    // Association entre combat_1 et boxeur_1
    combat_1.setCoinBleu(&boxeur_1);

    // Association entre combat_1 et boxeur_2
    combat_1.setCoinRouge(boxeur_2);

    // Affichage des informations de combat_1
    std::cout << "\nLes combats de boxe vont bientot commencer, nous allons assister a " << combat_1.getCoinBleu()->getNom() << " vs " << combat_1.getCoinRouge()->getNom() << " dans la salle : " << combat_1.getAdr() << std::endl;
    std::cout << "\nLe boxeur qui prend le coin bleu est : " << combat_1.getCoinBleu()->getNom() << std::endl;
    std::cout << "Le boxeur qui prend le coin rouge est : " << combat_1.getCoinRouge()->getNom() << std::endl;

    // Définition du vainqueur du combat
    combat_1.DesignerVainqueur("bleu");

    // Affichage du vainqueur du combat
    if (combat_1.getVainqueur() != nullptr) {
        std::cout << "Le vainqueur du combat est : " << combat_1.getVainqueur()->getNom() << std::endl;
    }
    else {
        std::cout << "Aucun vainqueur pour le moment." << std::endl;
    }

    // Libération de la mémoire allouée dynamiquement
    delete boxeur_2;

    return 0;
}
