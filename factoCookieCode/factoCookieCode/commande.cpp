#include "commande.h"

using namespace std;

//Constructeurs
Commande::Commande()
{
	numCommande = 0;
}

Commande::Commande(int _numCommande)
{
	numCommande = _numCommande;
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


void Commande::SetNumCommande(int _numCommande)
{
	numCommande = _numCommande;
}
