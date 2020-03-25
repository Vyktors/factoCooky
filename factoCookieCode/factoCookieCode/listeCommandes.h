#pragma once
#include "uniteDeProduction.h"
#include "commande.h"
#include "lotDeBiscuits.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list> 

class ListeCommandes {
public:
	ListeCommandes();
	~ListeCommandes();
	void ChargerCommandes(string);
	bool ouvreFichierE(fstream& fichier, string nomFichier);
	

private:
	std::list<Commande> listeCommandes;
};
