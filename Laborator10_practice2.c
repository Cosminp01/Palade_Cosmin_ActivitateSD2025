#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Nod {
	Masina infoUtil;
	struct Nod* fiuStanga;
	struct Nod* fiuDreapta;
};
typedef struct Nod Nod;

void afisareMasini(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

Masina citireMasinaFisier(FILE* file) {

	Masina m;
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);

	m.id = atoi(strtok(buffer, sep));
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);
	m.model = (char*)malloc(strlen(aux) + 1);
	strcpy(m.model, aux);
	aux = strtok(NULL, sep);
	m.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m.numeSofer, aux);
	m.serie = strtok(NULL, sep)[0];

	return m;
}

void adaugareMasinaArbore(Nod** radacina, Masina masinaNoua) {

	if (*radacina != NULL) {
		if (masinaNoua.id < (*radacina)->infoUtil.id) {
			adaugareMasinaArbore(&(*radacina)->fiuStanga, masinaNoua);
		}
		else {
			adaugareMasinaArbore(&(*radacina)->fiuDreapta, masinaNoua);
		}
	}
	else {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->fiuStanga = NULL;
		nou->fiuDreapta = NULL;
		nou->infoUtil = masinaNoua; //shallow copy

		//deep copy
		nou->infoUtil.model = (char*)malloc(sizeof(char) * (strlen(masinaNoua.model) + 1));
		strcpy(nou->infoUtil.model, masinaNoua.model);
		nou->infoUtil.numeSofer = (char*)malloc(sizeof(char) * (strlen(masinaNoua.numeSofer) + 1));
		strcpy(nou->infoUtil.numeSofer, masinaNoua.numeSofer);

		(*radacina) = nou;
	}
}

Nod* citireArboreFisier(const char* numeFisier) {

	FILE* file = fopen(numeFisier, "r");
	Nod* nou = NULL;
	while (!feof(file)) {
		Masina masinaNoua = citireMasinaFisier(file);
		adaugareMasinaArbore(&nou, masinaNoua);
		free(masinaNoua.model);
		free(masinaNoua.numeSofer);
	}
	fclose(file);
	return nou;
}

void afisarePreOrdineArbore(Nod* radacina) { //RSD
	if (radacina != NULL) {
		afisareMasini(radacina->infoUtil);
		afisarePreOrdineArbore(radacina->fiuStanga);
		afisarePreOrdineArbore(radacina->fiuDreapta);
	}
}

void afisareInOrdineArbore(Nod* radacina) {//SRD	
	if (radacina != NULL) {
		afisareInOrdineArbore(radacina->fiuStanga);
		afisareMasini(radacina->infoUtil);
		afisareInOrdineArbore(radacina->fiuDreapta);
	}
}

void afisarePostOrdineArbore(Nod* radacina) {//SDR
	if (radacina != NULL) {
		afisarePostOrdineArbore(radacina->fiuStanga);
		afisarePostOrdineArbore(radacina->fiuDreapta);
		afisareMasini(radacina->infoUtil);
	}
}

void dezalocareArborePostOrdine(Nod** radacina) {
	if (*radacina != NULL) {
		dezalocareArborePostOrdine((*radacina)->fiuStanga);
		dezalocareArborePostOrdine((*radacina)->fiuDreapta);
		free((*radacina)->infoUtil.model);
		free((*radacina)->infoUtil.numeSofer);
		free(*radacina);

		*radacina = NULL;
	}
}

Masina extragereMasinaDinArboreById(Nod* radacina, int idCautat) {
	Masina m;
	m.id = -1;
	if (radacina != NULL) {
		if (idCautat < radacina->infoUtil.id) {
			return extragereMasinaDinArboreById(radacina->fiuStanga, idCautat);
		}
		else if (idCautat > radacina->infoUtil.id) {
			return extragereMasinaDinArboreById(radacina->fiuDreapta, idCautat);
		}
		else {
			return radacina->infoUtil;
		}
		return m;
	}
}

int determinaNrNoduri(Nod* radacina) {
	if (radacina != NULL) {
		int stanga = determinaNrNoduri(radacina->fiuStanga);
		int dreapta = determinaNrNoduri(radacina->fiuDreapta);
		return 1 + stanga + dreapta;
	}
	else {
		return 0;
	}
}

int calculeazaInaltimeArbore(Nod* radacina) {
	if (radacina != NULL) {
		int inaltimeStanga = calculeazaInaltimeArbore(radacina->fiuStanga);
		int inaltimeDreapta = calculeazaInaltimeArbore(radacina->fiuDreapta);

		if (inaltimeStanga > inaltimeDreapta) {
			return 1 + inaltimeStanga;
		}
		else {
			return 1 + inaltimeDreapta;
		}
	}
	else {
		return 0;
	}
}

float calculeazaPretMasiniArbore(Nod* radacina) {

	if (radacina != NULL) {
		float pretStanga = calculeazaPretMasiniArbore(radacina->fiuStanga);
		float pretDreapta = calculeazaPretMasiniArbore(radacina->fiuDreapta);
		return radacina->infoUtil.pret + pretStanga + pretDreapta;
	}
	else {
		return 0;
	}
}

float calculeazaPretulMasinilorPtUnSofer(Nod* radacina, const char* soferCautat) {

	if (radacina != NULL) {
		float pretStanga = calculeazaPretulMasinilorPtUnSofer(radacina->fiuStanga, soferCautat);
		float pretDrepata = calculeazaPretulMasinilorPtUnSofer(radacina->fiuDreapta, soferCautat);

		if (strcmp(radacina->infoUtil.numeSofer, soferCautat) == 0) {
			return  radacina->infoUtil.pret + pretStanga + pretDrepata;
		}
		else {
			return pretStanga + pretDrepata;
		}
	}
	else {
		return 0;
	}
}

int main() {

	Nod* radacina = citireArboreFisier("masini.txt");
	printf("\n---------Afisare arbore PREORDINE!---------\n");
	afisarePreOrdineArbore(radacina);

	printf("\n-------Afisare arbore extras!-------\n");
	afisareMasini(extragereMasinaDinArboreById(radacina, 10));

	printf("\n--------Numar total de noduri in arbore: %d--------\n", determinaNrNoduri(radacina));

	printf("\n--------Inaltimea arboreului este:%d------\n", calculeazaInaltimeArbore(radacina));

	printf("\n--------Pretul total pentru masini este:%5.2f-----\n", calculeazaPretMasiniArbore(radacina));

	printf("\n--------Pretul masinilor pentru un un sofer specific este:%5.2f------\n", calculeazaPretulMasinilorPtUnSofer(radacina, "Ionescu"));

	printf("\n---------Afisare arbore INORDINE!---------\n");
	afisareInOrdineArbore(radacina);
	printf("\n---------Afisare arbore POSTORDINE!---------\n");
	afisarePreOrdineArbore(radacina);

	printf("\n--------Afisare arbore dupa dezalocare!-------\n");
	dezalocareArborePostOrdine(&radacina);
	afisareInOrdineArbore(radacina);
	return 0;
}