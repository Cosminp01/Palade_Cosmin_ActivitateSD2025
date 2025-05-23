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
//void afisareVacante(Vacanta v) {
//	printf("Informatii pentru vacanta cu nr. %d: \n", v.idVacanta);
//	printf("Destinatie: %s \n", v.destinatie);
//	printf("Pachet turistic: %c \n", v.pachetTuristic);
//	printf("Pret vacanta: %5.2f RON\n", v.pretVacanta);
//	printf("Zile: %d zile\n", v.nrZile);
//	printf("Distanta destinatie: %.2f km\n\n", v.distantaKm);
//}
//
//Vacanta citireVacanteFisier(FILE* file) {
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
//int inaltimeArbore(Nod* radacina) {
//
//	if (radacina != NULL) {
//		int inaltimeStanga = inaltimeArbore(radacina->fiuStanga);
//		int inaltimeDreapta = inaltimeArbore(radacina->fiuDreapta);
//
//		return 1 + (inaltimeStanga > inaltimeDreapta ? inaltimeStanga : inaltimeDreapta);
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
//		return nodAux;
//	}
//}
//
//int gradEchilibru(Nod* radacina) {
//	if (radacina != NULL) {
//		int gradEchilibruSt = gradEchilibru(radacina->fiuStanga);
//		int gradEchilibruDr = gradEchilibru(radacina->fiuDreapta);
//
//		return gradEchilibruSt - gradEchilibruDr;
//	}
//	else {
//		return 0;
//	}
//}
//
//void adaugareVacantaAVL(Nod** radacina, Vacanta vacantaNoua) {
//
//	if (*radacina != NULL) {
//		if (vacantaNoua.idVacanta < (*radacina)->infoUtil.idVacanta) {
//			adaugareVacantaAVL(&(*radacina)->fiuStanga, vacantaNoua);
//		}
//		else {
//			adaugareVacantaAVL(&(*radacina)->fiuDreapta, vacantaNoua);
//		}
//
//		if (gradEchilibru(*radacina) == 2) {
//			if (gradEchilibru((*radacina)->fiuStanga) != 1) {
//				(*radacina)->fiuStanga = rotireLaStanga(*radacina)->fiuStanga;
//			}
//			*radacina = rotireLaDreapta(*radacina);
//		}
//		if (gradEchilibru(*radacina) == -2) {
//			if (gradEchilibru((*radacina)->fiuDreapta) != -1) {
//				(*radacina)->fiuDreapta = rotireLaDreapta(*radacina)->fiuDreapta;
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
//		adaugareVacantaAVL(&nou, vacantaNoua);
//		free(vacantaNoua.destinatie);
//	}
//	fclose(file);
//	return nou;
//}
//
//void afisareArborePreordine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareVacante(radacina->infoUtil);
//		afisareArborePreordine(radacina->fiuStanga);
//		afisareArborePreordine(radacina->fiuDreapta);
//	}
//}
//
//void afisareArboreInOrdine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareArboreInOrdine(radacina->fiuStanga);
//		afisareVacante(radacina->infoUtil);
//		afisareArboreInOrdine(radacina->fiuDreapta);
//	}
//}
//
//void dezalocarePostOrdine(Nod** radacina) {
//
//	if (*radacina != NULL) {
//		dezalocarePostOrdine((*radacina)->fiuStanga);
//		dezalocarePostOrdine((*radacina)->fiuDreapta);
//		free((*radacina)->infoUtil.destinatie);
//		free(*radacina);
//
//		*radacina = NULL;
//	}
//}
//
//int main() {
//
//	
//	//radacina->fiuDreapta = NULL;
//	//radacina->fiuStanga = NULL;
//	//radacina->inaltime = 0;
//	Nod* radacina = citireAVLFisier("vacante_arbore.txt");
//	afisareArboreInOrdine(radacina);
//
//	return 0;
//}