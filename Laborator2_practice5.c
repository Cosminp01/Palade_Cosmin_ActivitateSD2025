//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct InfoTelevizor {
//	int id;
//	float pretTV;
//	double diagonalaTV;
//	char* producator;
//	char* tehnologie;
//	unsigned char clasaEnergetica;
//};
//
//typedef struct InfoTelevizor Televizor;
//
//void afisareTelevizoare(Televizor t) {
//
//	printf("Televizorul cu id-ul %d, are urmatoarele specificatii:\n", t.id);
//	printf("Pret este de: %5.2f RON\n", t.pretTV);
//	printf("Diagonala:%.2f inch\n", t.diagonalaTV);
//	printf("Producator:%s\n", t.producator);
//	printf("Tehnologie:%s\n", t.tehnologie);
//	printf("Clasa Energetica:%c\n\n", t.clasaEnergetica);
//}
//
//Televizor citireTelevizoareFisier(FILE* file) {
//	Televizor t;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	t.id = atoi(strtok(buffer, sep));
//	t.pretTV = atof(strtok(NULL, sep));
//	t.diagonalaTV = strtod(strtok(NULL, sep), NULL);
//	char* aux;
//	aux = strtok(NULL, sep);
//	t.producator = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.producator, aux);
//	aux = strtok(NULL, sep);
//	t.tehnologie = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.tehnologie, aux);
//	t.clasaEnergetica = strtok(NULL, sep)[0];
//	return t;
//}
//
//void afisareTelevizoareVector(Televizor* televizor, int nrTelevizoare) {
//	for (int i = 0; i < nrTelevizoare; i++) {
//		afisareTelevizoare(televizor[i]);
//	}
//}
//
//void adaugareTelevizorInVector(Televizor** televizor, int* nrTelevizoare, Televizor televizorNou) {
//
//	Televizor* tvNou = (Televizor*)malloc(sizeof(Televizor) * ((*nrTelevizoare) + 1));
//	for (int i = 0; i < *nrTelevizoare; i++) {
//		tvNou[i] = (*televizor)[i];
//	}
//
//	tvNou[(*nrTelevizoare)] = televizorNou;
//	free(*televizor);
//	(*televizor) = tvNou;
//	(*nrTelevizoare)++;
//}
//
//Televizor* citireTelevizoareVectorFisier(const char* numeFisier, int* nrTelevizoare) {
//	Televizor* nou = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareTelevizorInVector(&nou, nrTelevizoare, citireTelevizoareFisier(file));
//		}
//	}
//	fclose(file);
//	return nou;
//}
//
//void dezalocareVector(Televizor** tv, int* nrTV) {
//	for (int i = 0; i < *nrTV; i++) {
//		if (tv[i]->producator != NULL) {
//			free(tv[i]->producator);
//		}
//		if (tv[i]->tehnologie != NULL) {
//			free(tv[i]->tehnologie);
//		}
//	}
//	free(*tv);
//	*tv = NULL;
//	(*nrTV) = 0;
//}
//
//int main()
//{
//	int nrTV = 0;
//	Televizor* tv = citireTelevizoareVectorFisier("televizoare.txt", &nrTV);
//	afisareTelevizoareVector(tv, nrTV);
//
//	return 0;
//}