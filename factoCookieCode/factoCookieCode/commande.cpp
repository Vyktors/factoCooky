#include "commande.h"

using namespace std;

//Constructeurs
Commande::Commande()
{
	numCommande = 0;
	temps = 0;
	compteurLot = 0;
	size = 0;
}

Commande::Commande(int _numCommande, int _temps, int _compteurLot, int _size)
{
	numCommande = _numCommande;
	temps = _temps;
	compteurLot = _compteurLot;
	size = _size;
}

//Destructeur
Commande::~Commande()
{

}


//Accesseurs
int Commande::GetNumCommande()
{
	return numCommande;
}
int Commande::GetTemps()
{
	return temps;
}

int Commande::GetCompteurLot()
{
	return compteurLot;
}

int Commande::GetSize()
{
	return size;
}

void Commande::SetNumCommande(int _numCommande)
{
	numCommande = _numCommande;
}
void Commande::SetTemps(int _temps)
{
	temps = _temps;
}

void Commande::SetCompteurLot(int _compteurLot)
{
	compteurLot = _compteurLot;
}

void Commande::SetSize(int _size)
{
	size = _size;
}