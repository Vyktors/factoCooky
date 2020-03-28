#pragma once
#include <string>
#include <list>
using namespace std;

class LotDeBiscuits
{
private:
	string type;
	int quantite;
	int nbLotParCommande;
	int commandeAssocie;

public:
	std::list <string> etapes;

	//Constructeur
	LotDeBiscuits();
	LotDeBiscuits(string, int, int, int);

	//Destructeur
	~LotDeBiscuits();

	//Accesseurs
	//Getters
	string GetType();
	int GetQuantite();
	int GetNbLotParCommande();
	int GetCommandeAssocie();

	//Setters
	void SetType(string);
	void SetQuantite(int);
	void SetNbLotParCommande(int);
	void SetCommandeAssocie(int);
};