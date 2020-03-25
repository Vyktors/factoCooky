#pragma once
#include <list> 
#include "lotDeBiscuits.h"
using namespace std;

class Commande
{
private:
	int numCommande;

public:
	std::list<LotDeBiscuits> lots;

	//Constructeur
	Commande();
	Commande(int);

	//Destructeur
	~Commande();

	//Accesseurs
	//Getters
	int GetNumCommande();

	//Setters
	void SetNumCommande(int);
};
