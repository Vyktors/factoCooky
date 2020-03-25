#pragma once
#include <string>
using namespace std;

class LotDeBiscuits
{
private:
	string type;
	int quantite;
public:
	
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