#include "commande.h"

using namespace std;

//Constructeurs
Commande::Commande()
{
	numCommande = 0;
	temps = 0;
}

Commande::Commande(int _numCommande, int _temps)
{
	numCommande = _numCommande;
	temps = _temps;
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

void Commande::SetNumCommande(int _numCommande)
{
	numCommande = _numCommande;
}
void Commande::SetTemps(int _temps)
{
	temps = _temps;
}