#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


void AfficheResultats(Combat* combats, int taille) {
    std::cout << "\nResultats des combats :" << std::endl;
    for (int i = 0; i < taille; ++i) {
        std::cout << "Combat " << combats[i].getNiveau() << std::endl;
        std::cout << "  Boxeur bleu : " << combats[i].getCoinBleu()->getNom() << std::endl;
        std::cout << "  Boxeur rouge : " << combats[i].getCoinRouge()->getNom() << std::endl;
        std::cout << "  Le vainqueur est : ";
        if (combats[i].getVainqueur() != nullptr) {
            std::cout << combats[i].getVainqueur()->getNom() << std::endl;
        }
        else {
            std::cout << "Aucun vainqueur pour le moment." << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    // Initialisation du generateur de nombres aleatoires
    std::srand(std::time(0));

    // Instanciation des boxeurs
    Boxeur boxeur_1("Marc", "26 Avenue Tony Garnier 69007", 75.0, 0.0);
    Boxeur boxeur_2("Sam", "69 Boulevard Lenine 69220", 78.0, 0.0);
    Boxeur boxeur_3("John", "123 Rue de la Victoire 75001", 80.0, 0.0);
    Boxeur boxeur_4("Alex", "42 Rue du Paradis 75010", 77.0, 0.0);

    // Instanciation des combats
    Combat demiFinale1("1ere demi-finale", "Adresse de la demi-finale 1\n");
    Combat demiFinale2("2eme demi-finale", "Adresse de la demi-finale 2");
    Combat finale("Finale", "Adresse de la finale");

    // Association des boxeurs aux combats de demi-finales
    demiFinale1.setCoinBleu(&boxeur_1);
    demiFinale1.setCoinRouge(&boxeur_2);

    demiFinale2.setCoinBleu(&boxeur_3);
    demiFinale2.setCoinRouge(&boxeur_4);

    // Affichage des informations des demi-finales
    std::cout << "Demi-finale 1 : " << demiFinale1.getCoinBleu()->getNom() << " vs " << demiFinale1.getCoinRouge()->getNom() << std::endl;
    std::cout << "Adresse de la demi-finale 1 : " << demiFinale1.getAdr() << std::endl;

    std::cout << "Demi-finale 2 : " << demiFinale2.getCoinBleu()->getNom() << " vs " << demiFinale2.getCoinRouge()->getNom() << std::endl;
    std::cout << "Adresse de la demi-finale 2 : " << demiFinale2.getAdr() << std::endl;

    // Selection aleatoire des vainqueurs des demi-finales
    int random1 = std::rand() % 2; // 0 ou 1
    int random2 = std::rand() % 2; // 0 ou 1

    if (random1 == 0) {
        demiFinale1.designerVainqueur("bleu");
    }
    else {
        demiFinale1.designerVainqueur("rouge");
    }

    if (random2 == 0) {
        demiFinale2.designerVainqueur("bleu");
    }
    else {
        demiFinale2.designerVainqueur("rouge");
    }

    // Affectation des vainqueurs aux coins de la finale
    finale.setCoinBleu(demiFinale1.getVainqueur());
    finale.setCoinRouge(demiFinale2.getVainqueur());

    // Selection aleatoire du vainqueur de la finale
    int random3 = std::rand() % 2; // 0 ou 1

    if (random3 == 0) {
        finale.designerVainqueur("bleu");
    }
    else {
        finale.designerVainqueur("rouge");
    }

    // Tableau des combats
    Combat combats[3] = { demiFinale1, demiFinale2, finale };

    // Affichage des resultats des combats
    AfficheResultats(combats, 3);

    // Affichage du vainqueur de la finale
    if (finale.getVainqueur() != nullptr) {
        std::cout << "\n\nLe grand vainqueur de la finale est : " << finale.getVainqueur()->getNom() << "\n\n" << std::endl;
    }
    else {
        std::cout << "Aucun vainqueur pour le moment." << std::endl;
    }

    return 0;
}
