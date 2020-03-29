#include "uniteDeProduction.h"

using namespace std;

//Constructeurs
UniteDeProduction::UniteDeProduction()
{
	nom = "";
	temps = 0;
}

UniteDeProduction::UniteDeProduction(string _nom, int _temps)
{
	nom = _nom;
	temps = _temps;
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

int UniteDeProduction::GetTemps()
{
	return temps;
}


void UniteDeProduction::SetNom(string _nom)
{
	nom = _nom;
}

void UniteDeProduction::SetTemps(int _temps)
{
	temps = _temps;
}