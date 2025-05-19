//#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//
//struct InfoBiletFilm {
//	int id;
//	char* numeFilm;
//	char* dataDifuzare;
//	unsigned char rand;
//	double locRand;
//	float pret;
//};
//typedef struct InfoBiletFilm Bilet;
//
//void afisareBileteFilm(Bilet b) {
//	printf("\nDetaliile pentru biletul cu nr %d , sunt:\n", b.id);
//	printf("Nume film: %s\n", b.numeFilm);
//	printf("Data difuzare la cinema: %s\n", b.dataDifuzare);
//	printf("Locul se afla pe randul: %c\n", b.rand);
//	printf("Nr loc: %.2f\n", b.locRand);
//	printf("Pret bilet: %5.2f\n", b.pret);
//}
//
//Bilet citireBileteFisier(FILE* file) {
//
//	Bilet b;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	b.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	b.numeFilm = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.numeFilm, aux);
//	aux = strtok(NULL, sep);
//	b.dataDifuzare = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.dataDifuzare, aux);
//	b.rand = strtok(NULL, sep)[0];
//	b.locRand = strtod(strtok(NULL, sep), NULL);
//	b.pret = atof(strtok(NULL, sep));
//	return b;
//}
//
//struct Nod {
//	Bilet infoUtil;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//void afisareBileteFilmLS(Nod* cap) {
//
//	while (cap != NULL) {
//		afisareBileteFilm(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareBiletFilmLSSfarsit(Nod** cap, Bilet biletNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
//	nou->next = NULL;
//
//	if (*cap != NULL) {
//		Nod* capAux = *cap;
//		while (capAux->next != NULL) {
//			capAux = capAux->next;
//		}
//		capAux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//	
//}
//
//void adaugareBiletFilmLSInceput(Nod** cap, Bilet biletNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//Bilet* citireBileteFilmLSFisier(const char* numeFisier) {
//
//	Bilet* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareBiletFilmLSSfarsit(&cap, citireBileteFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void dezalocareLS(Nod** cap) {
//	while (*cap != NULL) {
//		Nod* capAux = *cap;
//		*cap = (*cap)->next;
//		if (capAux->infoUtil.numeFilm != NULL) {
//			free(capAux->infoUtil.numeFilm);
//		}
//		if (capAux->infoUtil.dataDifuzare != NULL) {
//			free(capAux->infoUtil.dataDifuzare);
//		}
//		free(capAux);
//	}
//}
//
//float calculeazaMediePretBilet(Nod* cap) {
//
//	float sumaBilete = 0;
//	int contor = 0;
//	while (cap != NULL) {
//		sumaBilete += cap->infoUtil.pret;
//		contor++;
//		cap = cap->next;
//	}if (contor > 0) {
//		return sumaBilete / contor;
//	}
//	return 0;
//}
//
//void stergerBiletLS(Nod** cap, char randCautat) {
//
//	while ((*cap) != NULL && (*cap)->infoUtil.rand == randCautat) {
//		Nod* capAux = (*cap);
//		if (capAux != NULL) {
//			*cap = capAux->next;
//			if (capAux->infoUtil.numeFilm != NULL) {
//				free(capAux->infoUtil.numeFilm);
//			}
//			if (capAux->infoUtil.dataDifuzare != NULL) {
//				free(capAux->infoUtil.dataDifuzare);
//			}
//			free(capAux);
//		}
//	}
//
//	if (*cap != NULL) {
//		Nod* capAux = *cap;
//		while (capAux != NULL) {
//			while (capAux != NULL && capAux->next != NULL && capAux->next->infoUtil.rand != randCautat) {
//				capAux = capAux->next;
//			}
//			if (capAux->next != NULL) {
//				Nod* nodAux = capAux->next;
//				capAux->next = nodAux->next;
//
//				if (nodAux->infoUtil.numeFilm != NULL) {
//					free(nodAux->infoUtil.numeFilm);
//				}
//				if (nodAux->infoUtil.dataDifuzare != NULL) {
//					free(nodAux->infoUtil.dataDifuzare);
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
//	Bilet* nou = citireBileteFilmLSFisier("bilete_film.txt");
//	afisareBileteFilmLS(nou);
//
//	printf("\n-----------------\n");
//	printf("\nPretul mediu al tuturor biletelor este de %5.2f RON.\n", calculeazaMediePretBilet(nou));
//	printf("\n-----------------\n");
//
//	printf("\n-----------------\n");
//	printf("\nAfisare bilete dupa stergerea randurilor A\n");
//	printf("\n-----------------\n");
//	stergerBiletLS(&nou, 'A');
//	afisareBileteFilmLS(nou);
//
//	printf("\n-----------------\n");
//	printf("\nAfisare bilete dupa stergerea randurilor \n");
//	printf("\n-----------------\n");
//	stergerBiletLS(&nou, 'I');
//	afisareBileteFilmLS(nou);
//
//	printf("\n-----------------\n");
//	printf("\nAfisare bilete film dupa dezalocare!\n");
//	dezalocareLS(&nou);
//	afisareBileteFilmLS(nou);
//
//	return 0;
//}