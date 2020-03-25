#include "listeCommandes.h"


ListeCommandes::ListeCommandes()
{
	cout << "Nouvelle liste Commandes" << endl;
}


ListeCommandes::~ListeCommandes()
{
	cout << "Supression liste commandes" << endl;
}

void ListeCommandes::ChargerCommandes(string nomFichierCommandes)
{
	fstream fichierCommandes;
	if (ouvreFichierE(fichierCommandes, "Fichiers/" + nomFichierCommandes))
	{
		int index = 0;
		string token, ligne, nom_client;
		string delimiter = " ";

		size_t pos = 0;
		Commande commandeTemp;
		LotDeBiscuits lotTemp;

		while (getline(fichierCommandes, ligne))
		{
			if (ligne == "&") {
				
				listeCommandes.push_back(commandeTemp);
				commandeTemp.lots.clear();
				index = -1;
			}
			else {
				if (index == 0) {
					try {
						commandeTemp.SetNumCommande(std::stoi(ligne));
					}
					catch (std::invalid_argument const& e) {
						cout << "Impossible de convertir un string en int.";
					}
				}
				else {
					while ((pos = ligne.find(delimiter)) != std::string::npos) {
						token = ligne.substr(0, pos);
						ligne.erase(0, pos + delimiter.length());
					}
					try {
						lotTemp = LotDeBiscuits(token, std::stoi(ligne));
					}
					catch (std::invalid_argument const& e) {
						cout << "Impossible de convertir un string en int.";
					}
					commandeTemp.lots.push_back(lotTemp);

				}
			}
			index++;
		}
	}
	fichierCommandes.close();
}

bool ListeCommandes::ouvreFichierE(fstream& fichier, string nomFichier)
{
	fichier.open(nomFichier, fstream::in);
	if (!fichier)
	{
		cout << "Le fichier n'existe pas" << endl;
		return false;
	}
	return true;
}


