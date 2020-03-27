#pragma once
#include <list> 
#include <string>
using namespace std;

class Recette
{
private:
	string typeBiscuit;

public:
	std::list <string> etapesFabric;

	//Constructeur
	Recette();
	Recette(string);

	//Destructeur
	~Recette();

	//Accesseurs
	//Getters
	string GetTypeBiscuit();

	//Setters
	void SetTypeBiscuit(string);
};