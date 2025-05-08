//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct InfoRezervare {
//	int id;
//	char* numePersoana;
//	char* dataRezervare;
//	unsigned char tipCamera;
//	double etaj;
//	float pretSejur;
//};
//
//typedef struct InfoRezervare Rezervare;
//
//void afisareRezervari(Rezervare rezervare) {
//	printf("Detaliile rezervarii cu id-ul %d, sunt:\n", rezervare.id);
//	printf("Nume persoana:%s\n", rezervare.numePersoana);
//	printf("Data rezervare:%s\n", rezervare.dataRezervare);
//	printf("Tipul camerei:%c\n", rezervare.tipCamera);
//	printf("Etajul camerei:%.2f\n", rezervare.etaj);
//	printf("Pret sejur:%5.2f\n\n", rezervare.pretSejur);
//}
//
//Rezervare citireRezervariFisier(FILE* file) {
//
//	Rezervare r;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//
//	r.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	r.numePersoana = (char*)malloc(strlen(aux) + 1);
//	strcpy(r.numePersoana, aux);
//	aux = strtok(NULL, sep);
//	r.dataRezervare = (char*)malloc(strlen(aux) + 1);
//	strcpy(r.dataRezervare, aux);
//	r.tipCamera = strtok(NULL, sep)[0];
//	r.etaj = strtod(strtok(NULL, sep), NULL);
//	r.pretSejur = atof(strtok(NULL, sep));
//	return r;
//}
//
//struct Nod {
//	Rezervare infoUtil;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//void afisareRezervariDeTipLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareRezervari(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareNodLaFinalDeLista(Nod** cap, Rezervare rezervareNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = rezervareNoua;
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
//void adaugareNodLaInceputDeLista(Nod** cap, Rezervare rezervareNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = rezervareNoua;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//Rezervare* citireRezervariFisierInLista(const char* numeFisier) {
//	Rezervare* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareNodLaFinalDeLista(&cap, citireRezervariFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void dezalocareListaRezervari(Nod** cap) {
//	while ((*cap) != NULL) {
//		Nod* capAux = *cap;
//		(*cap) = capAux->next;
//		if ((capAux->infoUtil.numePersoana != NULL) && (capAux->infoUtil.dataRezervare != NULL)) {
//			free(capAux->infoUtil.numePersoana);
//			free(capAux->infoUtil.dataRezervare);
//		}
//		free(capAux);
//	}
//}
//
//float mediaPreturilor(Nod* cap) {
//	float sumaPreturi = 0;
//	int contor = 0;
//	while (cap != NULL) {
//		sumaPreturi += cap->infoUtil.pretSejur;
//		contor++;
//		cap = cap->next;
//	}
//	if (contor > 0); {//facem aceasta verificare deoarece dupa while e posibil ca valorile noastre sa fie zero si noi nu vrem sa facem impartirea la zero
//		return sumaPreturi / contor;
//	}
//	return 0;
//}
//
//float calculeazaPretulRezervarilorUneiPersoane(Nod* cap, const char* persoana) {
//	float sumaRezervari = 0;
//	while (cap != NULL) {
//		if (strcmp(cap->infoUtil.numePersoana, persoana) == 0) {
//			sumaRezervari += cap->infoUtil.pretSejur;
//		}
//		cap = cap->next;
//	}
//	return sumaRezervari;
//}
//
//void stergereRezervariDinListaTipCamera(Nod** cap, char tipCameraCautat) {
//	while ((*cap) != NULL && (*cap)->infoUtil.tipCamera == tipCameraCautat) {
//		Nod* capAux = (*cap);
//		(*cap) = capAux->next;
//		if (capAux->infoUtil.numePersoana != NULL) {
//			free(capAux->infoUtil.numePersoana);
//		}
//		if (capAux->infoUtil.dataRezervare != NULL) {
//			free(capAux->infoUtil.dataRezervare);
//		}
//		free(capAux);
//	}
//	if ((*cap) != NULL) {
//		Nod* capAux = (*cap);
//		while (capAux != NULL) {
//			//capAux = capAux->next;
//			while (capAux != NULL && capAux->next != NULL && capAux->next->infoUtil.tipCamera != tipCameraCautat) {
//				capAux = capAux->next;
//			}
//			if (capAux->next != NULL) {
//				Nod* nodAux = capAux->next;
//				capAux->next = nodAux->next;
//				if (nodAux->infoUtil.numePersoana != NULL) {
//					free(nodAux->infoUtil.numePersoana);
//				}
//				if (nodAux->infoUtil.dataRezervare != NULL) {
//					free(nodAux->infoUtil.dataRezervare);
//				}
//				free(nodAux);
//			}
//			else {
//				capAux = NULL;
//			}
//		}
//	}
//}
//
//int main()
//{
//	Nod* cap = citireRezervariFisierInLista("rezervari.txt");
//	afisareRezervariDeTipLista(cap);
//
//	printf("\nAfisarea pretului mediu:%.2f\n", mediaPreturilor(cap));
//	printf("\nPretul pentru rezervarile facute de %s, este in valoare de %.2f:\n", cap->infoUtil.numePersoana, calculeazaPretulRezervarilorUneiPersoane(cap, "Popescu"));
//
//	printf("\nAfisare lista dupa stergere camere tip A:\n");
//	stergereRezervariDinListaTipCamera(&cap, 'A');
//	afisareRezervariDeTipLista(cap);
//
//	printf("\nAfisare lista dupa stergere camere tip B:\n");
//	stergereRezervariDinListaTipCamera(&cap, 'B');
//	afisareRezervariDeTipLista(cap);
//
//	printf("\nAfisare lista dupa stergere camere tip C:\n");
//	stergereRezervariDinListaTipCamera(&cap, 'C');
//	afisareRezervariDeTipLista(cap);
//
//	dezalocareListaRezervari(&cap);
//	return 0;
//}
