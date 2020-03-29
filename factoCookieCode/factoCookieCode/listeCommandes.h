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
	void chargerProduction(string);
	

private:
	std::list<Commande> listeCommandes;
	std::list<Commande>::iterator itC;
	std::map<string, int> listeTempsProduction;
	std::list<LotDeBiscuits>::iterator itLDB;
	std::list<string>::iterator itS;
	std::map<string, int>::iterator itP;
	UniteDeProduction preparation = UniteDeProduction("Préparation", 0);
	UniteDeProduction melange = UniteDeProduction("Mélange", 0);
	UniteDeProduction cuisson = UniteDeProduction("Cuisson", 0);
	UniteDeProduction emballage = UniteDeProduction("Emballage", 0);
	int preparationUtilisation = 0;
	int melangeUtilisation = 0;
	int cuissonUtilisation = 0;
	int emballageUtilisation = 0;
	bool excepetion = false;
	int compteurTemp = 0;
	int compteurCommande = 0;
	int compteurPreparation = 0;
	int compteurMelange = 0;
	int compteurCuisson = 0;
	int compteurEmballage = 0;

};
