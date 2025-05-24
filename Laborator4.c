//#define _CRT_SECURE_NO_WARNINGS	
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//	printf("ID:%d\n", masina.id);
//	printf("Numar usi:%d\n", masina.nrUsi);
//	printf("Pret:%.2f\n", masina.pret);
//	printf("Model:%s\n", masina.model);
//	printf("Nume sofer:%s\n", masina.numeSofer);
//	printf("Serie:%c\n\n", masina.serie);
//	}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++) {
//		afisareMasina(masini[i]);
//	}
//
//}
//
//void adaugareMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
//	Masina* vectorAux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i < (*nrMasini); i++) {
//		vectorAux[i] = (*masini)[i];
//	}
//	vectorAux[(*nrMasini)] = masinaNoua;
//	free(*masini);
//	(*masini) = vectorAux;
//	(*nrMasini)++;
//}
//
//Masina citireMasiniFisier(FILE* file) {
//	Masina m;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//
//	m.id = atoi(strtok(buffer, sep));
//	m.nrUsi = atoi(strtok(NULL, sep));
//	m.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	m.model = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.model, aux);
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//	m.serie = strtok(NULL, sep)[0];
//	return m;
//}
//
//Masina* citireMasiniFisierVector(const char* numeFisier, int* nrMasini) {
//	FILE* file = fopen(numeFisier, "r");
//
//	Masina* masini = NULL;
//	(*nrMasini) = 0;
//
//	while (!feof(file)) {
//		adaugareMasinaInVector(&masini, &nrMasini, citireMasiniFisier(file));
//	}
//	fclose(file);
//	return masini;
//}
//
//
////structura pentru un nod din lista simpla inlantuita
//struct Nod {
//	Masina infoUtila; //prima componenta din nod care stocheaza inforamtia utila
//	struct Nod* next; //prin acest next retinem adresa urmatorului nod din lista
//};
//
//typedef struct Nod Nod;
//
//void afisareListaMasini(Nod* cap) {//cap este un pointer la nod, adica retine adresa primului nod
//	while (cap != NULL) {//daca este null este finalul listei
//		afisareMasina(cap->infoUtila);//aici se afla pe prima casuta(facem dereferentiere)
//		cap = cap->next;//prin aceasta linie, ne deplasam la nodul urmator, adica cap-ul se va duce catre a "doua casuta"(ffacem dereferentiere)
//	}
//}
//
//void adaugaMasinaInLista(Nod* *cap, Masina masinaNoua) {
//	//avem dublu pointer deoarece in momentul in care cap=null, si adaugam un elemente, adresa cap trebuie modificata cu adresa noului nod adaugat
//	//la finalul listei
//	//masinaNoua este noul nod ce va fi adaugat
//	
//	//pentru inceput trebuie sa cream un nod NOU si sa alocam memorie
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtila = masinaNoua;//adica nodul nou adaugata va fi infoutila
//	nou->next = NULL;//aceasta linie se refera la faptul ca indiferent de pozitie final/inceput listei urmatotul NEXT-ul trebuie sa fie null, adica nu mai exista nimic dupa el
//
//	if (*cap != NULL) {//cazul in care avem un nr de n noduri/elemente in lista
//		Nod* capAux = (*cap);//creez un nou CAP caruia ii asociez adresa CAPULUI initial, adresa primului nod
//		//fac acest lucru pentru a ma putea deplasa pe orice nod din lista in continuare.
//
//		while (capAux != NULL) {//atata timp cat exita nodul urmatoru eu ma deplasez
//			capAux = capAux->next;
//		}
//		capAux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
//void adaugareMasinaInListaSfarsit(Nod* *cap, Masina nouaMasina) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtila = nouaMasina;
//	nou->next = NULL;
//
//	if (*cap != NULL) {
//		Nod* capAux = (*cap);
//		while (capAux->next != NULL) {
//			capAux = capAux->next;
//		}
//		capAux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
//void adaugareMasinaInListaInceput(Nod** cap, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtila = masinaNoua;
//	nou->next = *cap;//crearea primului nod
//	*cap = nou;//modificam adresa Capului initial cu adresa noului nod creat deoarece avem un nou nod
//}
//
//Nod* citireListaDinFisier(const char* numeFisier) {
//	Nod* cap = NULL;//definim o lista noua
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareMasinaInListaSfarsit(&cap,citireMasiniFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void stergereMainiDinLista(Nod** cap, char serieCautata) {
//	while ((*cap) != NULL & (*cap)->infoUtila.serie == serieCautata) {
//		Nod* capAux = (*cap);
//		(*cap) = capAux->next;
//		if (capAux->infoUtila.model != NULL) {
//			free(capAux->infoUtila.model);
//		}
//		if (capAux->infoUtila.numeSofer != NULL) {
//			free(capAux->infoUtila.numeSofer);
//		}
//		free(capAux);
//	}
//	if (*cap != NULL) {
//		Nod* capAux = (*cap);
//		if (capAux != NULL) {
//			while (capAux != NULL && capAux->next != NULL && capAux->next->infoUtila.serie != serieCautata) {
//				capAux = capAux->next;
//			}
//		}
//		if (capAux->next != NULL) {
//			Nod* nodAux = capAux->next;
//			capAux->next = nodAux->next;
//			if (nodAux->infoUtila.model != NULL) {
//				free(nodAux->infoUtila.model);
//			}
//			if (nodAux->infoUtila.numeSofer != NULL) {
//				free(nodAux->infoUtila.numeSofer);
//			}
//			free(nodAux);
//		}
//		else {
//			capAux = NULL;
//		}
//	}
//}
//
//int main()
//{
//	Nod* cap = citireListaDinFisier("masini.txt");
//	afisareListaMasini(cap);
//
//	printf("\nAfisare lista masini fara seria A:\n");
//	stergereMainiDinLista(&cap, 'A');
//	afisareListaMasini(cap);
//
//	return 0;
//}