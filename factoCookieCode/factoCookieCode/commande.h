#pragma once
#include <list> 
#include "lotDeBiscuits.h"
using namespace std;

class Commande
{
private:
	int numCommande;
	int temps;

public:
	std::list<LotDeBiscuits> lots;

	//Constructeur
	Commande();
	Commande(int, int);

	//Destructeur
	~Commande();

	//Accesseurs
	//Getters
	int GetNumCommande();
	int GetTemps();

	//Setters
	void SetNumCommande(int);
	void SetTemps(int);
};
