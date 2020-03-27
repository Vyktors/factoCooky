#pragma once
#include <string>
#include <list>
using namespace std;

class LotDeBiscuits
{
private:
	string type;
	int quantite;
public:
	std::list <string> etapes;

	//Constructeur
	LotDeBiscuits();
	LotDeBiscuits(string, int);

	//Destructeur
	~LotDeBiscuits();

	//Accesseurs
	//Getters
	string GetType();
	int GetQuantite();

	//Setters
	void SetType(string);
	void SetQuantite(int);
};