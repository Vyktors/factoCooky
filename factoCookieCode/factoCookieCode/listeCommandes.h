#pragma once
#include "uniteDeProduction.h"
#include "commande.h"
#include "lotDeBiscuits.h"
#include "recette.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list> 
#include <iomanip>

class ListeCommandes {
public:
	ListeCommandes();
	~ListeCommandes();
	void chargerCommandes(string);
	bool ouvreFichierE(fstream& fichier, string nomFichier);
	void simulation();
	void chargerRecettes(string);
	void uniteSuivante(string, LotDeBiscuits);
	void ajouterTempsCommande(int, int);
	void tempsMoyen();
	void tempsCommandePlusLongue();
	void commandeRapide();
	void unitePlusUtilisee();
	void uniteMoinsUtilisee();
	int ajouterCompteurLot(int);
	

private:
	std::list<Commande> listeCommandes;
	std::list<Commande>::iterator itC;
	std::list<LotDeBiscuits>::iterator itLDB;
	std::list<string>::iterator itS;
	UniteDeProduction preparation = UniteDeProduction("Préparation");
	UniteDeProduction melange = UniteDeProduction("Mélange");
	UniteDeProduction cuisson = UniteDeProduction("Cuisson");
	UniteDeProduction emballage = UniteDeProduction("Emballage");
	int preparationUtilisation = 0;
	int melangeUtilisation = 0;
	int cuissonUtilisation = 0;
	int emballageUtilisation = 0;
	bool excepetion = false;
	int compteurTemp = 0;
	int compteurCommande = 0;
};
