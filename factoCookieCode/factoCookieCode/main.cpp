#include "listeCommandes.h"
using namespace std;

void main(){

	ListeCommandes listeCo;
	listeCo.chargerCommandes("COMMANDES.txt");
	listeCo.chargerRecettes("RECETTES.txt");
	listeCo.simulation();

}

