#pragma once
#include <string>
#include <queue> 
#include "lotDeBiscuits.h"
using namespace std;

class UniteDeProduction
{
private:
	string nom;
	int temps;

public:
	std::queue <LotDeBiscuits> file;

	//Constructeur
	UniteDeProduction();
	UniteDeProduction(string, int);

	//Destructeur
	~UniteDeProduction();

	//Accesseurs
	//Getters
	string GetNom();
	int GetTemps();

	//Setters
	void SetNom(string);
	void SetTemps(int);
};
