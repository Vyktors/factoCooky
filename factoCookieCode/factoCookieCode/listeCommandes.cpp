#include "listeCommandes.h"


ListeCommandes::ListeCommandes()
{
	cout << "Nouvelle liste Commandes" << endl;
}


ListeCommandes::~ListeCommandes()
{
	cout << "Supression liste commandes" << endl;
}

void ListeCommandes::chargerCommandes(string nomFichierCommandes)
{
	fstream fichierCommandes;
	if (ouvreFichierE(fichierCommandes, "Fichiers/" + nomFichierCommandes))
	{
		int index = 0;
		string token, ligne;
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

void ListeCommandes::chargerRecettes(string nomFichierCommandes)
{
	fstream fichierCommandes;
	if (ouvreFichierE(fichierCommandes, "Fichiers/" + nomFichierCommandes))
	{
		int index = 0;
		string ligne;
		string typeTemp;
		Recette recetteTemp;

		while (getline(fichierCommandes, ligne))
		{
			if (ligne == "&") {

				
				for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++) {
					for (itLDB = (*itC).lots.begin(); itLDB != (*itC).lots.end(); itLDB++) {
						if ((*itLDB).GetType() == typeTemp) {
							for (itS = recetteTemp.etapesFabric.begin(); itS != recetteTemp.etapesFabric.end(); itS++) {
								(*itLDB).etapes.push_back(*itS);
							}
						}
					}
				}
				recetteTemp.etapesFabric.clear();
				index = -1;
			}
			else {
				if (index == 0) {
					typeTemp = ligne;
				}
				else {
					recetteTemp.etapesFabric.push_back(ligne);
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

void ListeCommandes::simulation() {
	bool fin = false;
	int min = 0;
	string uniteTemp;


	while (!fin) {

		fin = true;
		for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++){
			if (!(*itC).lots.empty())
			{
				uniteTemp = (*itC).lots.front().etapes.front();
				(*itC).lots.front().etapes.pop_front();
				uniteSuivante(uniteTemp, (*itC).lots.front());
				(*itC).lots.pop_front();
			}
		}
		if (!emballage.file.empty())
		{
			if (!emballage.file.front().etapes.empty())
			{
				uniteTemp = emballage.file.front().etapes.front();
				emballage.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp,emballage.file.front());
			}
			emballage.file.pop();
			fin = false;
		}
		if (!cuisson.file.empty())
		{
			if (!cuisson.file.front().etapes.empty())
			{
				uniteTemp = cuisson.file.front().etapes.front();
				cuisson.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp, cuisson.file.front());
			}
			cuisson.file.pop();
			fin = false;
		}
		if (!melange.file.empty())
		{
			if (!melange.file.front().etapes.empty())
			{
				uniteTemp = melange.file.front().etapes.front();
				melange.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp, melange.file.front());
			}
			melange.file.pop();
			fin = false;
		}
		if (!preparation.file.empty())
		{
			if (!preparation.file.front().etapes.empty())
			{
				uniteTemp = preparation.file.front().etapes.front();
				preparation.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp, preparation.file.front());
			}
			preparation.file.pop();
			fin = false;
		}
		if (fin == false)
		{
			min += 15;
		}
	}
}

void ListeCommandes::uniteSuivante(string suivant, LotDeBiscuits lot) {
	if (suivant == "Preparation") {
		preparation.file.push(lot);
	}
	else {
		if (suivant == "Melange") {
			melange.file.push(lot);
		}
		else {
			if (suivant == "Cuisson") {
				cuisson.file.push(lot);
			}
			else {
				emballage.file.push(lot);
			}
		}
	}
}

