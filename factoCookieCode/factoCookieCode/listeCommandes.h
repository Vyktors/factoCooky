#pragma once
#include "uniteDeProduction.h"
#include "commande.h"
#include "lotDeBiscuits.h"
#include "recette.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list> 

class ListeCommandes {
public:
	ListeCommandes();
	~ListeCommandes();
	void chargerCommandes(string);
	bool ouvreFichierE(fstream& fichier, string nomFichier);
	void simulation();
	void chargerRecettes(string);
	void uniteSuivante(string, LotDeBiscuits);
	

private:
	std::list<Commande> listeCommandes;
	std::list<Commande>::iterator itC;
	std::list<LotDeBiscuits>::iterator itLDB;
	std::list<string>::iterator itS;
	UniteDeProduction preparation = UniteDeProduction("Préparation");
	UniteDeProduction melange = UniteDeProduction("Mélange");
	UniteDeProduction cuisson = UniteDeProduction("Cuisson");
	UniteDeProduction emballage = UniteDeProduction("Emballage");
};
