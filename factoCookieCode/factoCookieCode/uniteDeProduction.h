#pragma once
#include <string>
#include <queue> 
#include "lotDeBiscuits.h"
using namespace std;

class UniteDeProduction
{
private:
	string nom;
public:
	std::queue <LotDeBiscuits> file;

	//Constructeur
	UniteDeProduction();
	UniteDeProduction(string);

	//Destructeur
	~UniteDeProduction();

	//Accesseurs
	//Getters
	string GetNom();

	//Setters
	void SetNom(string);
};
