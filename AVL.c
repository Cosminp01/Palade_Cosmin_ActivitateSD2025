//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//typedef struct Nod {
//	Masina infoUtil;
//	struct Nod* fiuStanga;
//	struct Nod* fiuDreapta;
//};
//typedef struct Nod Nod;
//
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//
//void adaugaMasinaInArbore(Nod** radacina, Masina masinaNoua) {
//
//	if ((*radacina) != NULL) {
//		if (masinaNoua.id < (*radacina)->infoUtil.id) {
//			adaugaMasinaInArbore(&(*radacina)->fiuStanga, masinaNoua);
//		}
//		else {
//			adaugaMasinaInArbore(&(*radacina)->fiuDreapta, masinaNoua);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->fiuStanga = NULL;
//		nou->fiuDreapta = NULL;
//		nou->infoUtil = masinaNoua;
//		nou->infoUtil.model = (char*)malloc(sizeof(char) * (strlen(masinaNoua.model) + 1));
//		strcpy(nou->infoUtil.model, masinaNoua.model);
//		nou->infoUtil.numeSofer = (char*)malloc(sizeof(char) * (strlen(masinaNoua.numeSofer)));
//		strcpy(nou->infoUtil.numeSofer, masinaNoua.numeSofer);
//
//		(*radacina) = nou;
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//	if (file != NULL) {
//		while (!feof(file)) {
//			Masina masinaNoua = citireMasinaDinFisier(file);
//			adaugaMasinaInArbore(&nou, masinaNoua);
//			free(masinaNoua.model);
//			free(masinaNoua.numeSofer);
//		}
//	}
//	fclose(file);
//	return nou;
//}
//
//void afisareMasiniDinArbore(Nod* radacina) {//RSD
//
//	if (radacina != NULL) {
//		afisareMasina(radacina->infoUtil);
//		afisareMasiniDinArbore(radacina->fiuStanga);
//		afisareMasiniDinArbore(radacina->fiuDreapta);
//	}
//}
//
//void afisareArboreInOrdine(Nod* radacina) {//SRD
//
//	if (radacina != NULL) {
//		afisareArboreInOrdine(radacina->fiuStanga);
//		afisareMasina(radacina->infoUtil);
//		afisareArboreInOrdine(radacina->fiuDreapta);
//	}
//}
//
//void dezalocareArboreDeMasini(Nod** radacina) {  //postordine
//
//	if ((*radacina) != NULL){
//		dezalocareArboreDeMasini((&(*radacina)->fiuStanga));
//		dezalocareArboreDeMasini((&(*radacina)->fiuDreapta));
//		free((*radacina)->infoUtil.model);
//		free((*radacina)->infoUtil.numeSofer);
//		free(*radacina);
//
//		(*radacina) = NULL;
//	}
//}
//
//Masina getMasinaByID(Nod* rad, int id) {
//	Masina m;
//	m.id = -1;
//
//	if (rad != NULL) {
//		if (id < rad->infoUtil.id) {
//			return getMasinaByID(rad->fiuStanga, id);
//		}
//		else if (id > rad->infoUtil.id) {
//			return getMasinaByID(rad->fiuDreapta, id);
//		}
//		else {
//			return rad->infoUtil;
//		}
//	}
//	return m;
//}
//
//int determinaNumarNoduri(/*arborele de masini*/) {
//	//calculeaza numarul total de noduri din arborele binar de cautare
//	return 0;
//}
//
//int calculeazaInaltimeArbore(/*arbore de masini*/) {
//	//calculeaza inaltimea arborelui care este data de 
//	//lungimea maxima de la radacina pana la cel mai indepartat nod frunza
//	return 0;
//}
//
//float calculeazaPretTotal(/*arbore de masini*/) {
//	//calculeaza pretul tuturor masinilor din arbore.
//	return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*arbore de masini*/ const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	return 0;
//}
//
//int main() {
//
//	Nod* radacina = citireArboreDeMasiniDinFisier("masini.txt");
//	afisareArboreInOrdine(radacina);
//
//	afisareMasina(getMasinaByID(radacina, 7));
//
//	return 0;
//}