#include <iostream>
#include <vector>

// MEMBRE DE GROUPE
//----------------------------
//  GBOYOU CHARLES
//  SANT-ANNA MARIE-DIDIER
//  ADOUNSI DERRICK
//  DAMALA EL-ANEWAR
//  ZANOU MAYLIS
//  MOUFTAOU HANANE

using namespace std;
// ======================= Votre code ici ===============================

class Article{
protected:
    string nom_article;
    double prix_unitaire;
    bool etat;
public:
    Article(string="", double=0.0, bool etat = false);
    string getNomArticle() const;
    double getPrixUnitaire() const;
    bool getEtat() const;
    void setNomArticle(string);
    void setPrixUnitaire(double);
    void setEtat(bool);
};
Article::Article(string nom_article, double prix_unitaire, bool etat){
    this->nom_article = nom_article;
    this->prix_unitaire = prix_unitaire;
    this->etat = etat;
}

void Article::setNomArticle(string nom_article)
{
    nom_article = nom_article;
}
void Article::setPrixUnitaire(double prix_unitaire)
{
    prix_unitaire = prix_unitaire;
}
void Article::setEtat(bool etat)
{
    etat = etat;
}

string Article::getNomArticle() const
{
    return nom_article;
}
double Article::getPrixUnitaire() const
{
    return prix_unitaire;
}
bool Article::getEtat() const
{
    return etat;
}


class Achat{
private:
    int qte_achete;
    Article article;
public:
    Achat(Article const& article, int quantite = 1):article(article), qte_achete(quantite){}
    void afficher() const;
    double prix() const {
        double prix_( qte_achete * article.getPrixUnitaire() );
        if (article.getEtat()) {
            prix_ *= 0.5;
        }
        return prix_;
    }
};

void Achat::afficher() const{
    cout <<  article.getNomArticle() << " : " << article.getPrixUnitaire() << " x " << this->qte_achete << " = " << prix();
    if( article.getEtat() == true ){
        cout << " ( Gbandjo )" << endl;
    }else{
        cout << "" << endl;
    }
}

class Caddie{
private:
    vector<Achat> achats;
public:
    double total() const{
        double somme(0.0);
        for (int i(0); i < achats.size(); ++i){
            achats[i].afficher();
            somme+=achats[i].prix();
        }
        return somme;
    }
    void remplir(Article const& article, unsigned int quantite = 1) {
        achats.push_back(Achat(article, quantite));
    }

};

class Caisse{
private:
   double total;
public:
    Caisse():total(0.0){}

    void afficher() const {
        cout << total << " F";
    }
    void scanner(Caddie const& caddie) {
        double montant(caddie.total());
        total += montant;
        cout << "-----" << endl;
        cout << "Total a payer : " << montant << " F." << endl;
    }
};

// ==================== Ne pas modifier ce code =========================
int main()
{
  // Les articles vendus dans le supermarché;
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

 // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }
  return 0;
}
