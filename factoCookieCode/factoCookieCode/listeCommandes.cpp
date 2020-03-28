#include "listeCommandes.h"


ListeCommandes::ListeCommandes()
{
	
}


ListeCommandes::~ListeCommandes()
{
	
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
						lotTemp = LotDeBiscuits(token, std::stoi(ligne), false, numCommandeTemp);
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
			(*itC).lots.back().SetDernier(true);
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
				cout << "Le lot de biscuit " << (*itC).lots.front().GetType() << " de la commande " << (*itC).GetNumCommande() <<
					" a ete envoye a l'unite de production : " << (*itC).lots.front().etapes.front()<<endl;
				uniteTemp = (*itC).lots.front().etapes.front();
				(*itC).lots.front().etapes.pop_front();
				uniteSuivante(uniteTemp, (*itC).lots.front());
				(*itC).lots.pop_front();
			}
		}
		if (!emballage.file.empty())
		{
			if (emballage.file.front().GetDernier() == true && emballage.file.front().etapes.size() == 0) {
				ajouterTempsCommande(min + 15, emballage.file.front().GetCommandeAssocie());
				cout << "La commande " << emballage.file.front().GetCommandeAssocie() << " est completee." << endl;
			}
			
			if (!emballage.file.front().etapes.empty())
			{
				cout << "Le lot de biscuit " << emballage.file.front().GetType() << " de la commande " << emballage.file.front().GetCommandeAssocie() <<
				" a ete envoye a l'unite de production : " << emballage.file.front().etapes.front() << endl;
				uniteTemp = emballage.file.front().etapes.front();
				if ((uniteTemp == "Cuisson" && cuisson.file.size() == 0) || (uniteTemp == "Melange" && melange.file.size() == 0) || (uniteTemp == "Preparation" && preparation.file.size() == 0)) {
					excepetion = true;
				}
				emballage.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp,emballage.file.front());
			}
			emballage.file.pop();
			fin = false;
			emballageUtilisation++;
		}
		if (!cuisson.file.empty() && excepetion == false)
		{
			if (cuisson.file.front().GetDernier() == true && cuisson.file.front().etapes.size() == 0) {
				ajouterTempsCommande(min + 15, cuisson.file.front().GetCommandeAssocie());
				cout << "La commande " << cuisson.file.front().GetCommandeAssocie() << " est completee." << endl;
			}
			if (!cuisson.file.front().etapes.empty())
			{
				cout << "Le lot de biscuit " << cuisson.file.front().GetType() << " de la commande " << cuisson.file.front().GetCommandeAssocie() <<
					" a ete envoye a l'unite de production : " << cuisson.file.front().etapes.front() << endl; 
				uniteTemp = cuisson.file.front().etapes.front();
				if ((uniteTemp == "Melange" && melange.file.size()==0) || (uniteTemp == "Preparation" && preparation.file.size() == 0)) {
					excepetion = true;
				}
				cuisson.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp, cuisson.file.front());
			}
			cuisson.file.pop();
			fin = false;
			cuissonUtilisation++;
		}
		if (!melange.file.empty() && excepetion == false)
		{
			if (melange.file.front().GetDernier() == true && melange.file.front().etapes.size() == 0) {
				ajouterTempsCommande(min + 15, melange.file.front().GetCommandeAssocie());
				cout << "La commande " << melange.file.front().GetCommandeAssocie() << " est completee." << endl;
			}
			if (!melange.file.front().etapes.empty())
			{
				cout << "Le lot de biscuit " << melange.file.front().GetType() << " de la commande " << melange.file.front().GetCommandeAssocie() <<
					" a ete envoye a l'unite de production : " << melange.file.front().etapes.front() << endl; 
				uniteTemp = melange.file.front().etapes.front();
				if (uniteTemp == "Preparation" && preparation.file.size() == 0) {
					excepetion = true;
				}
				melange.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp, melange.file.front());
			}
			melange.file.pop();
			fin = false;
			melangeUtilisation++;
		}
		if (!preparation.file.empty() && excepetion == false)
		{
			if (preparation.file.front().GetDernier() == true && preparation.file.front().etapes.size() == 0) {
				ajouterTempsCommande(min + 15, preparation.file.front().GetCommandeAssocie());
				cout << "La commande " << preparation.file.front().GetCommandeAssocie() << " est completee." << endl;
			}
			if (!preparation.file.front().etapes.empty())
			{
				cout << "Le lot de biscuit " << preparation.file.front().GetType() << " de la commande " << preparation.file.front().GetCommandeAssocie() <<
					" a ete envoye a l'unite de production : " << preparation.file.front().etapes.front() << endl; 
				uniteTemp = preparation.file.front().etapes.front();
				preparation.file.front().etapes.pop_front();
				uniteSuivante(uniteTemp, preparation.file.front());
			}
			preparation.file.pop();
			fin = false;
			preparationUtilisation++;
		}
		if (fin == false)
		{
			min += 15;
			cout << "15 minutes s'est ecoulee." << endl;
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
	int temps = listeCommandes.front().GetTemps();
	int commande = listeCommandes.front().GetNumCommande();
	int size = listeCommandes.front().lots.size();
	for (itC = listeCommandes.begin(); itC != listeCommandes.end(); itC++) {
		if (size < (*itC).lots.size()) {
			size = (*itC).lots.size();
			temps = (*itC).GetTemps();
			commande = (*itC).GetNumCommande();
		}
	}
	cout << "La commande la plus longue est la commande "<<commande<<" et a ete effectuee en " << temps << " minutes." << endl;
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
	int plus = preparationUtilisation;
	string unite = "Preparation";
	if (plus < melangeUtilisation) {
		plus = melangeUtilisation;
		unite = "Melange";
	}
	if (plus < cuissonUtilisation) {
		plus = cuissonUtilisation;
		unite = "Cuisson";
	}
	if (plus < emballageUtilisation) {
		plus = emballageUtilisation;
		unite = "Emballage";
	}
	cout << "L'unite de production la plus utilisee est : " << unite << endl;
}

void ListeCommandes::uniteMoinsUtilisee() {
	int moins = preparationUtilisation;
	string unite = "Preparation";
	if (moins > melangeUtilisation) {
		moins = melangeUtilisation;
		unite = "Melange";
	}
	if (moins > cuissonUtilisation) {
		moins = cuissonUtilisation;
		unite = "Cuisson";
	}
	if (moins > emballageUtilisation) {
		moins = emballageUtilisation;
		unite = "Emballage";
	}
	cout << "L'unite de production la moins utilisee est : " << unite << endl;
}

