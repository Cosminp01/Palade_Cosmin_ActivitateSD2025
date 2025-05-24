#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct informatiiVacanta {
	int idVacanta;
	char* destinatie;
	unsigned char pachetTuristic;
	float pretVacanta;
	int nrZile;
	double distantaKm;
};
typedef struct informatiiVacanta Vacanta;

struct Nod {
	Vacanta infoUtil;
	struct Nod* fiuStanga;
	struct Nod* fiuDreapta;
};
typedef struct Nod Nod;

void afisareVacante(Vacanta v) {
	printf("Informatii pentru vacanta cu nr. %d: \n", v.idVacanta);
	printf("Destinatie: %s \n", v.destinatie);
	printf("Pachet turistic: %c \n", v.pachetTuristic);
	printf("Pret vacanta: %5.2f RON\n", v.pretVacanta);
	printf("Zile: %d zile\n", v.nrZile);
	printf("Distanta destinatie: %.2f km\n\n", v.distantaKm);
}

Vacanta citireVacanteFisier(FILE* file) {
	
	Vacanta v;
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);

	v.idVacanta = atoi(strtok(buffer, sep));
	char* aux;
	aux = strtok(NULL, sep);
	v.destinatie = (char*)malloc(strlen(aux) + 1);
	strcpy(v.destinatie, aux);
	v.pachetTuristic = strtok(NULL, sep)[0];
	v.pretVacanta = atof(strtok(NULL, sep));
	v.nrZile = atoi(strtok(NULL, sep));
	v.distantaKm = strtod(strtok(NULL, sep), NULL);

	return v;
}

void adaugareVacantaInArbore(Nod** radacina, Vacanta vacantaNoua) {

	if (*radacina != NULL) {

		if (vacantaNoua.idVacanta < (*radacina)->infoUtil.idVacanta) {
			adaugareVacantaInArbore(&(*radacina)->fiuStanga, vacantaNoua);
		}
		else {
			adaugareVacantaInArbore(&(*radacina)->fiuDreapta, vacantaNoua);
		}
	}
	else {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->fiuDreapta = NULL;
		nou->fiuStanga = NULL;
		nou->infoUtil = vacantaNoua;

		nou->infoUtil.destinatie = (char*)malloc(sizeof(Nod) * (strlen(vacantaNoua.destinatie) + 1));
		strcpy(nou->infoUtil.destinatie, vacantaNoua.destinatie);

		*radacina = nou;
	}
}

Nod* citireArboreFisier(const char* numeFisier) {
	FILE* file = fopen(numeFisier, "r");
	Nod* nou = NULL;

	while (!feof(file)) {
		Vacanta vacantaNoua = citireVacanteFisier(file);
		adaugareVacantaInArbore(&nou, vacantaNoua);
		free(vacantaNoua.destinatie);
	}
	fclose(file);
	return nou;
}

void afisareArborePreordine(Nod* radacina) {//RSD

	if (radacina != NULL) {
	
		afisareVacante(radacina->infoUtil);
		afisareArborePreordine(radacina->fiuStanga);
		afisareArborePreordine(radacina->fiuDreapta);
	}
}

void afisareArboreInordine(Nod* radacina) {

	if (radacina != NULL) {
		afisareArboreInordine(radacina->fiuStanga);
		afisareVacante(radacina->infoUtil);
		afisareArboreInordine(radacina->fiuDreapta);
	}
}

void afisareArborePostOrdine(Nod* radacina) {

	if (radacina != NULL) {
		afisareArborePostOrdine(radacina->fiuStanga);
		afisareArborePostOrdine(radacina->fiuDreapta);
		afisareVacante(radacina->infoUtil);
	}
}

void dezalocarePostordine(Nod** radacina) {

	if (*radacina != NULL) {
		dezalocarePostordine((*radacina)->fiuStanga);
		dezalocarePostordine((*radacina)->fiuDreapta);
		free((*radacina)->infoUtil.destinatie);
		free(*radacina);

		*radacina = NULL;
	}
}

int inaltimeArbore(Nod* radacina) {
	if (radacina != NULL) {
		int stanga = inaltimeArbore(radacina->fiuStanga);
		int dreapta = inaltimeArbore(radacina->fiuDreapta);
		if (stanga > dreapta) {
			return 1 + stanga;
		}
		else {
			return 1 + dreapta;
		}
	}
	else {
		return 0;
	}
}

int nrNoduriArbore(Nod* radacina) {

	if (radacina != NULL) {
		int nodStanga = nrNoduriArbore(radacina->fiuStanga);
		int nodDreapta = nrNoduriArbore(radacina->fiuDreapta);

		return 1 + nodStanga + nodDreapta;
	}
	else {
		return 0;
	}
}

float sumaTotalaVacante(Nod* radacina) {

	if (radacina != NULL) {
		float pretStanga = sumaTotalaVacante(radacina->fiuStanga);
		float pretDreapta = sumaTotalaVacante(radacina->fiuDreapta);

		return radacina->infoUtil.pretVacanta + pretStanga + pretDreapta;
	}
	else {
		return 0;
	}
}

float sumaVacantaSpecifica(Nod* radacina, const char* vacantaCautata) {

	if (radacina != NULL) {
		float sumaStanga = sumaVacantaSpecifica(radacina->fiuStanga,vacantaCautata);
		float sumaDreapta = sumaVacantaSpecifica(radacina->fiuDreapta,vacantaCautata);
		if (strcmp(radacina->infoUtil.destinatie, vacantaCautata) == 0) {
			return radacina->infoUtil.pretVacanta + sumaStanga + sumaDreapta;
		}
		else {
			return sumaStanga + sumaDreapta;
		}
	}
	else {
		return 0;
	}
}



int main() {

	Nod* radacina;
	//radacina->fiuDreapta = 0;
	//radacina->fiuStanga = 0;

	radacina = citireArboreFisier("vacante_arbore.txt");
	afisareArboreInordine(radacina);

	printf("\n-------Afisare arbore PREORDINE!------\n");
	afisareArborePreordine(radacina);

	printf("\n------Inaltimea arborelui este: %d------- \n", inaltimeArbore(radacina));

	printf("\n------Nr de noduri ale arborelui sunt: %d-------- \n ", nrNoduriArbore(radacina));

	printf("\n------Pretul pentru toate vacantele este de: %5.2f RON------\n", sumaTotalaVacante(radacina));

	printf("\n------Pretul pentru o vacanta specifica este de: %5.2f------\n", sumaVacantaSpecifica(radacina, "Barcelona"));

	return 0;
}