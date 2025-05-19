//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
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
//void afisareBileteFilmVector(Bilet* bilet, int nrBilete) {
//	for (int i = 0; i < nrBilete; i++) {
//		afisareBileteFilm(bilet[i]);
//	}
//}
//
//void adaugareBiletFilmVector(Bilet** bilet, int* nrBilete, Bilet biletNou) {
//
//	Bilet* nou = (Bilet*)malloc(sizeof(Bilet) * ((*nrBilete) + 1)); //alocam o noua zona de memorie + 1(vectorul trebuie sa stie ca elemente are)
//	for (int i = 0; i < (*nrBilete); i++) {//parcurgem acel vector
//		nou[i] = (*bilet)[i];//la vectorul nostru initial, asociem noul vector
//	}
//	nou[(*nrBilete)] = biletNou;//stabilim legatura dintre elementul nou adaugat si ultimul elemenet din vectorul initial
//	free(*bilet);//dezalocam vectorul initial
//	*bilet = nou;//vectorul initial devine vectorul nou
//	(*nrBilete)++;//increment nr de elemente
//}
//
//Bilet* citireBileteFilmVectorFisier(const char* numeFisier, int* nrBilete) {
//
//	Bilet* biletNou = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareBiletFilmVector(&biletNou, nrBilete, citireBileteFisier(file));
//		}
//	}
//	fclose(file);
//	return biletNou;
//}
//
//void dezalocareVector(Bilet** bilet, int* nrBilete) {
//
//	for (int i = 0; i < (*nrBilete); i++) {
//		if (bilet[i]->numeFilm != NULL) {
//			free(bilet[i]->numeFilm);
//		}
//		if (bilet[i]->dataDifuzare != NULL) {
//			free(bilet[i]->dataDifuzare);
//		}
//	}
//	free(*bilet);
//	*bilet = NULL;
//	*nrBilete = 0;
//}
//
//int main() {
//
//	int nrBilete = 0;
//	Bilet* biletNou = citireBileteFilmVectorFisier("bilete_film.txt", &nrBilete);
//	afisareBileteFilmVector(biletNou, nrBilete);
//
//	return 0;
//}