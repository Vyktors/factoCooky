#include "listeCommandes.h"
using namespace std;

void main(){

	ListeCommandes listeCo;
	string fichierCommande, fichierRecette, fichierProduction;
	bool fin = false;
	int choix;

	do {
		cout << "Quel est le nom du fichier des commandes?" << endl;
		cin >> fichierCommande;
	} while (!listeCo.chargerCommandes(fichierCommande));
	
	do {
		cout << "Quel est le nom du fichier des recettes?" << endl;
		cin >> fichierRecette;
	} while (!listeCo.chargerRecettes(fichierRecette));
	
	do {
		cout << "Quel est le nom du fichier de production?" << endl;
		cin >> fichierProduction;
	} while (!listeCo.chargerProduction(fichierProduction));
	
	cout << "Simulation : " << endl;
	listeCo.simulation();
	while (!fin)
	{
		cout << "Que souhaitez-vous faire?" << endl << 
			"1. Savoir le temps moyen pour completer une commande." << endl <<
			"2. Savoir combien de temps la commande la plus longue a-t-elle ete effectuee.\n" << endl <<
			"3. Savoir quelle a ete la commande la plus rapide." << endl <<
			"4. Savoir quelle unite de production est la plus utilisee." << endl <<
			"5. Savoir quelle unite de production est la moins utilisee." << endl <<
			"6. Quitter." << endl;;
		cin >> choix;
		switch (choix){
		case 1:
			listeCo.tempsMoyen();
			break;
		case 2:
			listeCo.tempsCommandePlusLongue();
			break;
		case 3:
			listeCo.commandeRapide();
			break;
		case 4:
			listeCo.unitePlusUtilisee();
			break;
		case 5:
			listeCo.uniteMoinsUtilisee();
			break;
		default:
			fin = true;
			break;
		}
	}
}

