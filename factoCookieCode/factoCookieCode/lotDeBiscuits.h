#pragma once
#include <string>
#include <list>
using namespace std;

class LotDeBiscuits
{
private:
	string type;
	int quantite;
	bool dernier;
	int commandeAssocie;

public:
	std::list <string> etapes;

	//Constructeur
	LotDeBiscuits();
	LotDeBiscuits(string, int, bool, int);

	//Destructeur
	~LotDeBiscuits();

	//Accesseurs
	//Getters
	string GetType();
	int GetQuantite();
	bool GetDernier();
	int GetCommandeAssocie();

	//Setters
	void SetType(string);
	void SetQuantite(int);
	void SetDernier(bool);
	void SetCommandeAssocie(int);
};