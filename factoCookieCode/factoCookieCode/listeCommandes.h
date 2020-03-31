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
#include <map> 

class ListeCommandes {
public:
	ListeCommandes();
	~ListeCommandes();
	bool chargerCommandes(string);
	bool ouvreFichierE(fstream& fichier, string nomFichier);
	bool chargerProduction(string);
	bool chargerRecettes(string);
	void simulation();
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
	std::map<string, int> listeProduction;
	std::list<LotDeBiscuits>::iterator itLDB;
	std::list<string>::iterator itS;
	std::map<string, int>::iterator itP;
	UniteDeProduction* ptr = NULL;
	int* utilisation = NULL;
	int compteurTemp = 0;
	int compteurCommande = 0;
	int* cptUnite = NULL;
	bool* exception = NULL;

};
