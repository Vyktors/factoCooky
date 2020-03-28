#include "lotDeBiscuits.h"

using namespace std;

//Constructeurs
LotDeBiscuits::LotDeBiscuits()
{
	type = "";
	quantite = 0;
	nbLotParCommande = 0;
	commandeAssocie = 0;
}

LotDeBiscuits::LotDeBiscuits(string _type, int _quantite, int _nbLotParCommande, int _commandeAssocie)
{
	type = _type;
	quantite = _quantite;
	nbLotParCommande = _nbLotParCommande;
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

int LotDeBiscuits::GetNbLotParCommande()
{
	return nbLotParCommande;
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

void LotDeBiscuits::SetNbLotParCommande(int _nbLotParCommande)
{
	nbLotParCommande = _nbLotParCommande;
}

void LotDeBiscuits::SetCommandeAssocie(int _commandeAssocie)
{
	commandeAssocie = _commandeAssocie;
}
