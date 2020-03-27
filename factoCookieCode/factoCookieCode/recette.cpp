#include "recette.h"

using namespace std;

//Constructeurs
Recette::Recette()
{
	typeBiscuit = "";
}

Recette::Recette(string _typeBiscuit)
{
	typeBiscuit = _typeBiscuit;
}

//Destructeur
Recette::~Recette()
{

}


//Accesseurs
string Recette::GetTypeBiscuit()
{
	return typeBiscuit;
}


void Recette::SetTypeBiscuit(string _typeBiscuit)
{
	typeBiscuit = _typeBiscuit;
}