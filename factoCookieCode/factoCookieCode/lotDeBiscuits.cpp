#include "lotDeBiscuits.h"

using namespace std;

//Constructeurs
LotDeBiscuits::LotDeBiscuits()
{
	type = "";
	quantite = 0;
}

LotDeBiscuits::LotDeBiscuits(string _type, int _quantite)
{
	type = _type;
	quantite = _quantite;
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

void LotDeBiscuits::SetType(string _type)
{
	type = _type;
}

void LotDeBiscuits::SetQuantite(int _quantite)
{
	quantite = _quantite;
}