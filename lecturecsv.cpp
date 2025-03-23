#include <iostream> 
#include <sstream>
#include <fstream> 
#include <iterator>
#include <algorithm>
#include <list>
#include <map>
#include <cstdlib>

using namespace std;

class CSV {
private:
    map<int, list<string> > events;  // Une map pour stocker les événements par année
public:
    void ecrireCSV(string nomfichier);  // Méthode pour écrire les données dans un fichier CSV
    void affichage();  // Méthode pour afficher les événements
    void ajoute_evenement(int annee, string titre);  // Méthode pour ajouter un événement
    CSV(string filename);  // Constructeur qui lit un fichier CSV et initialise les événements
    map<int, list<string> > getEvents() const;  // Getter pour obtenir la map des événements
};


void CSV::ecrireCSV(string nomfichier){
    ofstream inf(nomfichier);  // Ouvre le fichier en mode écriture

    if(!inf.is_open()) {  // Vérifie si le fichier a été ouvert avec succès
        cout << "Failed to open the file" << endl;
        return;
    }

    
    for (pair<int, list<string> > p : events)
    {
        inf << p.first << ';';  // Écrit l'année suivie d'un point-virgule
        for(string titre : p.second) {  // Parcourt la liste des événements de l'année
            inf << titre <<";";  // Écrit chaque événement suivi d'un point-virgule
        }
        inf << endl; 
    }
};


void CSV::affichage()
{
    
    for (pair<int, list<string> > p : events)
    {
        cout << "Annee " << p.first << ": " << endl;  // Affiche l'année
        for(string titre : p.second) {  // Parcourt la liste des événements de l'année
            cout << "  - " << titre << endl;  // Affiche chaque événement
        }
    }
}


void CSV::ajoute_evenement(int annee, string titre) {
    if(events.count(annee)) {  // Vérifie si l'année existe déjà dans la map
        // Si oui, ajoute l'événement à la liste existante
        events[annee].push_back(titre);
    } else {
        // Si non, crée une nouvelle liste pour cette année et ajoute l'événement
        events[annee] = list<string>();
        events[annee].push_back(titre);
    }
}
    

CSV::CSV(string filename) {
    ifstream inf(filename);  // Ouvre le fichier en mode lecture

    if(!inf.is_open()) {  // Vérifie si le fichier a été ouvert avec succès
        cout << "Failed to open the file" << endl;
        return;
    }

    string line;
    getline(inf, line);  // Lit la première ligne du fichier
    while(!inf.bad() && !inf.eof()) {  // Continue à lire tant que le fichier n'est pas terminé

        istringstream l(line);  // Utilise un flux de chaîne pour traiter la ligne

        char semi;
        int annee;
        string title;

        l >> annee >> semi;  // Lit l'année et le point-virgule
        getline(l, title, ';');  // Lit le premier événement
        while(!l.bad() && !l.eof()) {  // Continue à lire tant que la ligne n'est pas terminée
            ajoute_evenement(annee, title);  // Ajoute l'événement à la map
            getline(l, title, ';');  // Lit le prochain événement
        }

        getline(inf, line);  // Lit la prochaine ligne du fichier
    }
}


int main()
{
    map<int, list<string> > events;  // Déclare une map pour stocker les événements (non utilisée ici)

    CSV c("dates.csv");  // Crée un objet CSV en lisant le fichier "dates.csv"
    c.affichage();  // Affiche les événements
    c.ecrireCSV("datesmodif.csv");  // Écrit les événements dans un nouveau fichier "datesmodif.csv"
}