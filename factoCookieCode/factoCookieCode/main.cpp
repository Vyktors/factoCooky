#include "listeCommandes.h"
using namespace std;

void main(){

	ListeCommandes listeCo;
	string fichierCommande, fichierRecette, fichierProduction;
	bool fin = false;
	int choix;

	cout << "Quel est le nom du fichier des commandes?" << endl;
	cin >> fichierCommande;
	listeCo.chargerCommandes(fichierCommande);
	cout << "Quel est le nom du fichier des recettes?" << endl;
	cin >> fichierRecette;
	listeCo.chargerRecettes(fichierRecette);
	cout << "Quel est le nom du fichier de production?" << endl;
	cin >> fichierProduction;
	listeCo.chargerProduction(fichierProduction);

	cout << "Simulation : " << endl;
	listeCo.simulation();
	while (!fin)
	{
		cout << "Que souhaitez-vous faire?\n" <<
			"1. Savoir le temps moyen pour completer une commande.\n" <<
			"2. Savoir combien de temps la commande la plus longue a-t-elle ete effectuee.\n" <<
			"3. Savoir quelle a ete la commande la plus rapide.\n" <<
			"4. Savoir quelle unite de production est la plus utilisee.\n" <<
			"5. Savoir quelle unite de production est la moins utilisee.\n" <<
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

