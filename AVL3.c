//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
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
//	int inaltime;
//};
//typedef struct Nod Nod;
//
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
//int inaltimeArboreAVL(Nod* radacina) {
//
//	if (radacina != NULL) {
//		int inaltimeSt = inaltimeArboreAVL(radacina->fiuStanga);
//		int inaltimeDr = inaltimeArboreAVL(radacina->fiuDreapta);
//
//		return 1 + (inaltimeSt > inaltimeDr ? inaltimeSt : inaltimeDr);
//	}
//}
//
//int gradEchilibru(Nod* radacina) {
//
//	if (radacina != NULL) {
//		int gradSt = gradEchilibru(radacina->fiuStanga);
//		int gradDr = gradEchilibru(radacina->fiuDreapta);
//
//		return gradSt - gradDr;
//	}
//	else {
//		return 0;
//	}
//}
//
//Nod* rotireLaDreapta(Nod* radacina) {
//
//	if (radacina != NULL) {
//		Nod* nodAux = radacina->fiuStanga;
//		radacina->fiuStanga = nodAux->fiuDreapta;
//		nodAux->fiuDreapta = radacina;
//
//		return nodAux;
//	}
//}
//
//Nod* rotireLaStanga(Nod* radacina) {
//
//	if (radacina != NULL) {
//		Nod* nodAux = radacina->fiuDreapta;
//		radacina->fiuDreapta = nodAux->fiuStanga;
//		nodAux->fiuStanga = radacina;
//
//		return radacina;
//	}
//}
//
//void adaugareVacantaInAVL(Nod** radacina, Vacanta vacantaNoua) {
//
//	if (*radacina != NULL) {
//		if (vacantaNoua.idVacanta < (*radacina)->infoUtil.idVacanta) {
//			adaugareVacantaInAVL(&(*radacina)->fiuStanga, vacantaNoua);
//		}
//		else {
//			adaugareVacantaInAVL(&(*radacina)->fiuDreapta, vacantaNoua);
//		}
//
//		if (gradEchilibru(*radacina) == 2) {
//			if (gradEchilibru((*radacina)->fiuStanga) != 1) {
//				(*radacina)->fiuStanga = rotireLaStanga((*radacina)->fiuStanga);
//			}
//			*radacina = rotireLaDreapta(*radacina);
//		}
//		if (gradEchilibru(*radacina) == -2) {
//			if (gradEchilibru((*radacina)->fiuDreapta) != -1) {
//				(*radacina)->fiuDreapta = rotireLaDreapta((*radacina)->fiuDreapta);
//			}
//			*radacina = rotireLaStanga(*radacina);
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
//Vacanta* citireAVLFisier(const char* numeFisier) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//	while (!feof(file)) {
//		Vacanta vacantaNoua = citireVacanteFisier(file);
//		adaugareVacantaInAVL(&nou, vacantaNoua);
//		free(vacantaNoua.destinatie);
//	}
//	fclose(file);
//	return nou;
//}
//
//void afisareInOrdine(Nod* radacina) {
//	
//	if (radacina != NULL) {
//		afisareInOrdine(radacina->fiuStanga);
//		afisareVacante(radacina->infoUtil);
//		afisareInOrdine(radacina->fiuDreapta);
//	}
//}
//
//void afisarePreordine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareVacante(radacina->infoUtil);
//		afisarePreordine(radacina->fiuStanga);
//		afisarePreordine(radacina->fiuDreapta);
//	}
//}
//
//void dezalocareAVL(Nod** radacina) {
//
//	if (*radacina != NULL) {
//		dezalocareAVL((*radacina)->fiuStanga);
//		dezalocareAVL((*radacina)->fiuDreapta);
//		free((*radacina)->infoUtil.destinatie);
//		free(*radacina);
//
//		*radacina = NULL;
//	}
//}
//
//int nrArboriAVL(Nod* radacina) {
//
//	if (radacina != NULL) {
//		int nrStanga = nrArboriAVL(radacina->fiuStanga);
//		int nrDreapta = nrArboriAVL(radacina->fiuDreapta);
//
//		return 1 + nrStanga + nrDreapta;
//	}
//	else {
//		return 0;
//	}
//}
//
//
//float sumaTotalaVacante(Nod* radacina) {
//
//	if (radacina != NULL) {
//		float pretStanga = sumaTotalaVacante(radacina->fiuStanga);
//		float pretDreapta = sumaTotalaVacante(radacina->fiuDreapta);
//
//		return radacina->infoUtil.pretVacanta + pretStanga + pretDreapta;
//	}
//	else {
//		return 0;
//	}
//}
//
//float sumaVacantaSpecifica(Nod* radacina, const char* vacantaCautata) {
//
//	if (radacina != NULL) {
//		float sumaStanga = sumaVacantaSpecifica(radacina->fiuStanga,vacantaCautata);
//		float sumaDreapta = sumaVacantaSpecifica(radacina->fiuDreapta,vacantaCautata);
//		if (strcmp(radacina->infoUtil.destinatie, vacantaCautata) == 0) {
//			return radacina->infoUtil.pretVacanta + sumaStanga + sumaDreapta;
//		}
//		else {
//			return sumaStanga + sumaDreapta;
//		}
//	}
//	else {
//		return 0;
//	}
//}
//
//int main() {
//
//	Nod* radacina = citireAVLFisier("vacante_arbore.txt");
//	afisareInOrdine(radacina);
//
//	printf("\n------Nr noduri AVL: %d-----\n", nrArboriAVL(radacina));
//
//	printf("\n------Pretul pentru toate vacantele este de: %5.2f RON------\n", sumaTotalaVacante(radacina));
//
//	printf("\n------Pretul pentru o vacanta specifica este de: %5.2f------\n", sumaVacantaSpecifica(radacina, "Barcelona"));
//
//	return 0;
//}