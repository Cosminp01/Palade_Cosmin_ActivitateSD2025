//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//	printf("ID:%d\n", masina.id);
//	printf("Numar usi:%d\n", masina.nrUsi);
//	printf("Pret:%.2f\n", masina.pret);
//	printf("Model:%s\n", masina.model);
//	printf("Nume sofer:%s\n", masina.numeSofer);
//	printf("Serie:%c\n\n", masina.serie);
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	Masina m;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
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
//void afisareMasiniVector(Masina* m, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++) {
//		afisareMasina(m[i]);
//	}
//}
//
//void adaugareMasiniInVector(Masina** m, int* nrMasini, Masina masinaNoua) {
//
//	Masina* nou = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i < (*nrMasini); i++) {
//		nou[i] = (*m)[i];
//	}
//
//	nou[(*nrMasini)] = masinaNoua;
//	free(*m);
//	*m = nou;
//	(*nrMasini)++;
//}
//
//Masina* citireMasiniVectorFisier(const char* numeFisier, int* nrmasiniCitite) {
//	Masina* nou = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareMasiniInVector(&nou, nrmasiniCitite, citireMasinaFisier(file));
//		}
//	}
//	fclose(file);
//	return nou;
//}
//
//void dezalocare(Masina** m, int* nrMasini) {
//	for (int i = 0; i < *nrMasini; i++) {
//		if (m[i]->model != NULL) {
//			free(m[i]->model);
//		}
//		if (m[i]->numeSofer != NULL) {
//			free(m[i]->numeSofer);
//		}
//	}
//	free(*m);
//	(*m) = NULL;
//	(*nrMasini) = 0;
//}
//
//int main() {
//
//	int nrMasini = 0;
//	Masina* masina = citireMasiniVectorFisier("masini.txt",&nrMasini);
//	afisareMasiniVector(masina, nrMasini);
//
//	return 0;
//}