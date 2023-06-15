#pragma once
class Combat {
private:
    std::string niveau;
    std::string adr;
    Boxeur* coinBleu;
    Boxeur* coinRouge;
    Boxeur* vainqueur;

public:
    Combat(const std::string& niveau, const std::string& adr) : niveau(niveau), adr(adr), coinBleu(nullptr), coinRouge(nullptr), vainqueur(nullptr) {}

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

    Boxeur* getVainqueur() const {
        return vainqueur;
    }

    Boxeur* designerVainqueur(const std::string& couleurCoin) {
        if (couleurCoin == "bleu") {
            vainqueur = coinBleu;
        }
        else if (couleurCoin == "rouge") {
            vainqueur = coinRouge;
        }
        else {
            vainqueur = nullptr;
        }

        return vainqueur;
    }
};

