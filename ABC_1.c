//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct informatiiVacanta {
//	int idVacanta;
//	char* destinatie;
//	unsigned char pachetTuristic;
//	float pretVacanta;
//	int nrZile;
//	double distantaKm;
//};
//typedef struct informatiiVacanta Vacanta;
//
//struct Nod {
//	Vacanta infoUtil;
//	struct Nod* fiuStanga;
//	struct Nod* fiuDreapta;
//};
//typedef struct Nod Nod;
//
//void afisareVacante(Vacanta v) {
//	printf("Informatii pentru vacanta cu nr. %d: \n", v.idVacanta);
//	printf("Destinatie: %s \n", v.destinatie);
//	printf("Pachet turistic: %c \n", v.pachetTuristic);
//	printf("Pret vacanta: %5.2f RON\n", v.pretVacanta);
//	printf("Zile: %d zile\n", v.nrZile);
//	printf("Distanta destinatie: %.2f km\n\n", v.distantaKm);
//}
//
//Vacanta citireVacanteFisier(FILE* file){
//
//	Vacanta v;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	v.idVacanta = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	v.destinatie = (char*)malloc(strlen(aux) + 1);
//	strcpy(v.destinatie, aux);
//	v.pachetTuristic = strtok(NULL, sep)[0];
//	v.pretVacanta = atof(strtok(NULL, sep));
//	v.nrZile = atoi(strtok(NULL, sep));
//	v.distantaKm = strtod(strtok(NULL, sep), NULL);
//
//	return v;
//}
//
//void adaugareVacantaInABC(Nod** radacina, Vacanta vacantaNoua) {
//
//	if (*radacina != NULL) {
//		if (vacantaNoua.idVacanta < (*radacina)->infoUtil.idVacanta) {
//			adaugareVacantaInABC(&(*radacina)->fiuStanga, vacantaNoua);
//		}
//		else {
//			adaugareVacantaInABC(&(*radacina)->fiuDreapta, vacantaNoua);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->fiuDreapta = NULL;
//		nou->fiuStanga = NULL;
//		nou->infoUtil = vacantaNoua;
//
//		nou->infoUtil.destinatie = (char*)malloc(sizeof(char) * (strlen(vacantaNoua.destinatie) + 1));
//		strcpy(nou->infoUtil.destinatie, vacantaNoua.destinatie);
//
//		*radacina = nou;
//	}
//}
//
//Nod* citireVacanteABCFisier(const char* numeFisier) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//
//	while (!feof(file)) {
//		Vacanta vacantaNoua = citireVacanteFisier(file);
//		adaugareVacantaInABC(&nou, vacantaNoua);
//
//		free(vacantaNoua.destinatie);
//	}
//	fclose(file);
//	return nou;
//}
//
//void afisareABCPreordine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareVacante(radacina->infoUtil);
//		afisareABCPreordine(radacina->fiuStanga);
//		afisareABCPreordine(radacina->fiuDreapta);
//	}
//}
//
//void afisareABCInordine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareABCInordine(radacina->fiuStanga);
//		afisareVacante(radacina->infoUtil);
//		afisareABCInordine(radacina->fiuDreapta);
//	}
//}
//
//void dezalocareABCPostordine(Nod** radacina) {
//
//	if (radacina != NULL) {
//		dezalocareABCPostordine((*radacina)->fiuStanga);
//		dezalocareABCPostordine((*radacina)->fiuDreapta);
//		free((*radacina)->infoUtil.destinatie);
//		free(*radacina);
//
//		*radacina = NULL;
//	}
//}
//
//int inaltimeArbore(Nod* radacina) {
//
//	if (radacina != NULL) {
//		int inaltimeSt = inaltimeArbore(radacina->fiuStanga);
//		int inaltimeDr = inaltimeArbore(radacina->fiuDreapta);
//
//		return 1 + (inaltimeSt > inaltimeDr ? inaltimeSt : inaltimeDr);
//	}
//}
//
//int nrNoduriABC(Nod* radacina) {
//
//	if (radacina != NULL) {
//		int nrNodSt = nrNoduriABC(radacina->fiuStanga);
//		int nrNodDr = nrNoduriABC(radacina->fiuDreapta);
//
//		return 1 + nrNodSt + nrNodDr;
//	}
//	else {
//		return 0;
//	}
//}
//
//float sumaTotalaVacante(Nod* radacina) {
//
//	if (radacina != NULL) {
//		float sumaSt = sumaTotalaVacante(radacina->fiuStanga);
//		float sumaDr = sumaTotalaVacante(radacina->fiuDreapta);
//
//		return radacina->infoUtil.pretVacanta + sumaSt + sumaDr;
//	}
//	else {
//		return 0;
//	}
//}
//
//int main() {
//
//	Nod* radacina = citireVacanteABCFisier("vacante_arbore.txt");
//	printf("\n------Afisare ABC INORDINE!-----\n");
//	afisareABCInordine(radacina);
//	printf("\n------Afisare ABC PREORDINE!-------\n");
//	afisareABCPreordine(radacina);
//
//	printf("\n------Inaltimea ABC este: %d------\n", inaltimeArbore(radacina));
//
//	printf("\n------Nr de noduri ABC este: %d------\n", nrNoduriABC(radacina));
//
//	printf("\n------Costul pentru toate vacantele este de: %5.2f RON-------\n", sumaTotalaVacante(radacina));
//
//	printf("\n------Afisare ABC DEZALOCAT!------\n");
//	dezalocareABCPostordine(&radacina);
//	afisareABCInordine(radacina);
//
//	return 0;
//}