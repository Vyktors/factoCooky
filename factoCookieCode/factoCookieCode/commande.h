#pragma once
#include <list> 
#include "lotDeBiscuits.h"
using namespace std;

class Commande
{
private:
	int numCommande;
	int temps;
	int compteurLot;
	int size;

public:
	std::list<LotDeBiscuits> lots;

	//Constructeur
	Commande();
	Commande(int, int, int, int);

	//Destructeur
	~Commande();

	//Accesseurs
	//Getters
	int GetNumCommande();
	int GetTemps();
	int GetCompteurLot();
	int GetSize();

	//Setters
	void SetNumCommande(int);
	void SetTemps(int);
	void SetCompteurLot(int);
	void SetSize(int);
};
