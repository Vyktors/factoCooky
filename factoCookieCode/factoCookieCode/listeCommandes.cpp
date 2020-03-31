#include "listeCommandes.h"


ListeCommandes::ListeCommandes()
{
	
}


ListeCommandes::~ListeCommandes()
{
	
}

bool ListeCommandes::chargerCommandes(string nomFichierCommandes)
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
		int numCommandeTemp;

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
						numCommandeTemp = std::stoi(ligne);
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
						lotTemp = LotDeBiscuits(token, std::stoi(ligne), 0, numCommandeTemp);
					}
					catch (std::invalid_argument const& e) {
						cout << "Impossible de convertir un string en int.";
					}
					commandeTemp.lots.push_back(lotTemp);

				}
			}
			index++;
		}

		for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++) {
			(*itC).SetSize((*itC).lots.size());
			for (itLDB = (*itC).lots.begin(); itLDB != (*itC).lots.end(); itLDB++) {
				(*itLDB).SetNbLotParCommande((*itC).lots.size());
			}
		}
		fichierCommandes.close();
		return true;
	}
	fichierCommandes.close();
	return false;
}

bool ListeCommandes::chargerProduction(string nomFichierProduction)
{
	fstream fichierProduction;
	if (ouvreFichierE(fichierProduction, "Fichiers/" + nomFichierProduction))
	{
		string token, ligne;
		string delimiter = " ";
		
		size_t pos = 0;
		int i = 0;

		while (getline(fichierProduction, ligne))
		{
			while ((pos = ligne.find(delimiter)) != std::string::npos) {
				token = ligne.substr(0, pos);
				ligne.erase(0, pos + delimiter.length());
			}
			try {
				listeProduction.insert(pair<string, int>(token, std::stoi(ligne)));
			}
			catch (std::invalid_argument const& e) {
				cout << "Impossible de convertir un string en int.";
			}
		}
		ptr = new UniteDeProduction[listeProduction.size()];
		for (itP = listeProduction.begin(), i = 0; itP != listeProduction.end(); itP++, i++) {
			ptr[i].SetTemps((*itP).second);
			ptr[i].SetNom((*itP).first);
		}
		fichierProduction.close();
		return true;
	}
	fichierProduction.close();
	return false;
}

bool ListeCommandes::chargerRecettes(string nomFichierRecettes)
{
	fstream fichierRecettes;
	if (ouvreFichierE(fichierRecettes, "Fichiers/" + nomFichierRecettes))
	{
		int index = 0;
		string ligne;
		string typeTemp;
		Recette recetteTemp;

		while (getline(fichierRecettes, ligne))
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
		fichierRecettes.close();
		return true;
	}
	fichierRecettes.close();
	return false;
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
	int i = 0;
	int j = 0;
	string uniteTemp;
	cptUnite = new int[listeProduction.size()];
	utilisation = new int[listeProduction.size()];
	exception = new bool[listeProduction.size()];
	for (i = 0; i < listeProduction.size(); i++) {
		cptUnite[i] = ptr[i].GetTemps();
		utilisation[i] = 0;
		exception[i] = false;
	}

	while (!fin) {

		fin = true;

		// Envoyer le premier lot de chaque commande à leur première étape toutes les 15 minutes afin de ne pas surcharger les files.
		for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++){
			if (!(*itC).lots.empty())
			{
				cout << "Le lot de biscuit " << (*itC).lots.front().GetType() << " de la commande " << (*itC).GetNumCommande() <<
					" a ete envoye a l'unite de production : " << (*itC).lots.front().etapes.front()<<endl;
				uniteTemp = (*itC).lots.front().etapes.front();
				(*itC).lots.front().etapes.pop_front();
				uniteSuivante(uniteTemp, (*itC).lots.front());
				(*itC).lots.pop_front();
			}
		}
		for (i = 0; i < listeProduction.size(); i++) {
			if (!ptr[i].file.empty() && exception[i] == false && cptUnite[i] == 15)
			{
				compteurTemp = 0;
				cptUnite[i] = ptr[i].GetTemps();
				if (ptr[i].file.front().etapes.size() == 0) {
					compteurTemp = ajouterCompteurLot(ptr[i].file.front().GetCommandeAssocie());
					cout << "Le lot de biscuit " << ptr[i].file.front().GetType() << " de la commande " << ptr[i].file.front().GetCommandeAssocie() <<
						" est terminee." << endl;
				}
				if (compteurTemp == ptr[i].file.front().GetNbLotParCommande()) {
					ajouterTempsCommande(min + 15, ptr[i].file.front().GetCommandeAssocie());
					compteurCommande++;
					cout << "La commande " << ptr[i].file.front().GetCommandeAssocie() << " est completee." << endl;
				}
				if (!ptr[i].file.front().etapes.empty())
				{
					cout << "Le lot de biscuit " << ptr[i].file.front().GetType() << " de la commande " << ptr[i].file.front().GetCommandeAssocie() <<
						" a ete envoye a l'unite de production : " << ptr[i].file.front().etapes.front() << endl;
					uniteTemp = ptr[i].file.front().etapes.front();
					for (j = i + 1; j < listeProduction.size(); j++) {
						if (uniteTemp == ptr[j].GetNom() && ptr[j].file.size() == 0) {
							exception[j] = true;
						}
					}
					ptr[i].file.front().etapes.pop_front();
					uniteSuivante(uniteTemp, ptr[i].file.front());
				}
				ptr[i].file.pop();
				fin = false;
				utilisation[i]++;
			}
			else {
				if (!ptr[i].file.empty() && exception[i] != true) {
					cptUnite[i] = cptUnite[i] - 15;
					fin = false;
				}
				if (!ptr[i].file.empty() && exception[i] == true) {
					fin = false;
					exception[i] = false;
				}
			}
		}
		if (fin == false && compteurCommande != listeCommandes.size())
		{
			min += 15;
			cout << "15 minutes s'est ecoulee." << endl;
		}
	}
}

void ListeCommandes::uniteSuivante(string suivant, LotDeBiscuits lot) {
	int i = 0;
	for (i = 0; i < listeProduction.size(); i++) {
		if (suivant == ptr[i].GetNom()) {
			ptr[i].file.push(lot);
		}
	}
}

void ListeCommandes::ajouterTempsCommande(int temps, int commande) {
	itC = listeCommandes.begin();
	bool trouver = false;
	while (!trouver){
		if ((*itC).GetNumCommande() == commande) {
			(*itC).SetTemps(temps);
			trouver = true;
		}
		else {
			itC++;
		}
	}
}

int ListeCommandes::ajouterCompteurLot(int commande) {
	itC = listeCommandes.begin();
	bool trouver = false;
	while (!trouver) {
		if ((*itC).GetNumCommande() == commande) {
			(*itC).SetCompteurLot((*itC).GetCompteurLot()+1);
			trouver = true;
			return (*itC).GetCompteurLot();
		}
		else {
			itC++;
		}
	}
}

void ListeCommandes::tempsMoyen() {
	double moyenne = 0.0;
	int total = 0;
	for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++) {
		total += (*itC).GetTemps();
	}
	moyenne = total / listeCommandes.size();
	cout << "Le temps moyen pour completer une commande est : " << fixed << setprecision(1) << moyenne << " minutes" << endl;
}

void ListeCommandes::tempsCommandePlusLongue() {
	int tempsMax = listeCommandes.front().GetTemps();
	int commande = listeCommandes.front().GetNumCommande();
	for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++) {
		if (tempsMax < (*itC).GetTemps()) {
			tempsMax = (*itC).GetTemps();
			commande = (*itC).GetNumCommande();
		}
	}
	cout << "La commande la plus longue a ete la commande " << commande << " qui a ete effectuee en " << tempsMax << " minutes." << endl;
}
	

void ListeCommandes::commandeRapide() {
	int tempsMin = listeCommandes.front().GetTemps();
	int commande = listeCommandes.front().GetNumCommande();
	for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++) {
		if (tempsMin > (*itC).GetTemps()) {
			tempsMin = (*itC).GetTemps();
			commande = (*itC).GetNumCommande();
		}
	}
	cout << "La commande la plus rapide a ete la commande " << commande << " qui a ete effectuee en " << tempsMin << " minutes." << endl;
}

void ListeCommandes::unitePlusUtilisee() {
	int i = 0;
	int plus = utilisation[0];
	string unite = ptr[0].GetNom();
	for (i = 0; i < listeProduction.size(); i++) {
		if (plus < utilisation[i]) {
			plus = utilisation[i];
			unite = ptr[i].GetNom();
		}
	}
	cout << "L'unite de production la plus utilisee est : " << unite << endl;
}

void ListeCommandes::uniteMoinsUtilisee() {
	int i = 0;
	int moins = utilisation[0];
	string unite = ptr[0].GetNom();
	for (i = 0; i < listeProduction.size(); i++) {
		if (moins > utilisation[i]) {
			moins = utilisation[i];
			unite = ptr[i].GetNom();
		}
	}
	cout << "L'unite de production la moins utilisee est : " << unite << endl;
}

