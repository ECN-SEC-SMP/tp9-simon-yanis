#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

void ajoute_evenement(map<int, list<string>> &events, int annee, string titre)
{
    if(events.count(annee)) {
        //Liste déjà créée
        events[annee].push_back(titre);
    } else {
        //Liste non créée
        events[annee] = list<string>();
        events[annee].push_back(titre);
    }
}

void affichage(map<int, list<string>> &events) {
    for (pair<int, list<string>> p : events)
    {
        cout << "Annee " << p.first << ": " << endl;
        for(string titre : p.second) {
            cout << "  - " << titre << endl;
        }
    }
    
}

int main()
{
    map<int, list<string>> events;

    ajoute_evenement(events, 2025, "Trump mange un rat");
    ajoute_evenement(events, 2025, "Simon passe le permis");
    ajoute_evenement(events, 1789, "Révolution");

    affichage(events);
}