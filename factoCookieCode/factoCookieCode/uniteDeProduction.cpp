#include "uniteDeProduction.h"

using namespace std;

//Constructeurs
UniteDeProduction::UniteDeProduction()
{
	nom = "";
}

UniteDeProduction::UniteDeProduction(string _nom)
{
	nom = _nom;
}

//Destructeur
UniteDeProduction::~UniteDeProduction()
{

}

//Accesseurs
string UniteDeProduction::GetNom()
{
	return nom;
}

void UniteDeProduction::SetNom(string _nom)
{
	nom = _nom;
}