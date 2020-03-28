#include "lotDeBiscuits.h"

using namespace std;

//Constructeurs
LotDeBiscuits::LotDeBiscuits()
{
	type = "";
	quantite = 0;
	dernier = false;
	commandeAssocie = 0;
}

LotDeBiscuits::LotDeBiscuits(string _type, int _quantite, bool _dernier, int _commandeAssocie)
{
	type = _type;
	quantite = _quantite;
	dernier = _dernier;
	commandeAssocie = _commandeAssocie;
}

//Destructeur
LotDeBiscuits::~LotDeBiscuits()
{

}

//Accesseurs
string LotDeBiscuits::GetType()
{
	return type;
}

int LotDeBiscuits::GetQuantite()
{
	return quantite;
}

bool LotDeBiscuits::GetDernier()
{
	return dernier;
}

int LotDeBiscuits::GetCommandeAssocie()
{
	return commandeAssocie;
}

void LotDeBiscuits::SetType(string _type)
{
	type = _type;
}

void LotDeBiscuits::SetQuantite(int _quantite)
{
	quantite = _quantite;
}

void LotDeBiscuits::SetDernier(bool _dernier)
{
	dernier = _dernier;
}

void LotDeBiscuits::SetCommandeAssocie(int _commandeAssocie)
{
	commandeAssocie = _commandeAssocie;
}
