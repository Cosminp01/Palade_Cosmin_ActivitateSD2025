#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct InfoTelevizor {
	int id;
	float pretTV;
	double diagonalaTV;
	char* producator;
	char* tehnologie;
	unsigned char clasaEnergetica;
};

typedef struct InfoTelevizor Televizor;

void afisareTelevizoare(Televizor t) {

	printf("Televizorul cu id-ul %d, are urmatoarele specificatii:\n", t.id);
	printf("Pret este de: %5.2f RON\n", t.pretTV);
	printf("Diagonala:%.2f inch\n", t.diagonalaTV);
	printf("Producator:%s\n", t.producator);
	printf("Tehnologie:%s\n", t.tehnologie);
	printf("Clasa Energetica:%c\n\n", t.clasaEnergetica);
}

Televizor citireTelevizoareFisier(FILE* file) {
	Televizor t;
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);

	t.id = atoi(strtok(buffer, sep));
	t.pretTV = atof(strtok(NULL, sep));
	t.diagonalaTV = strtod(strtok(NULL, sep), NULL);
	char* aux;
	aux = strtok(NULL, sep);
	t.producator = (char*)malloc(strlen(aux) + 1);
	strcpy(t.producator, aux);
	aux = strtok(NULL, sep);
	t.tehnologie = (char*)malloc(strlen(aux) + 1);
	strcpy(t.tehnologie, aux);
	t.clasaEnergetica = strtok(NULL, sep)[0];
	return t;
}

struct Nod {
	Televizor infoUtil;
	struct Nod* next;
};
typedef struct Nod Nod;

struct HashTable {
	int dim;
	Nod** tabelaVector;
};
typedef struct HashTable Table;

void afisareTelevizoareLS(Nod* cap) {
	while (cap != NULL) {
		afisareTelevizoare(cap->infoUtil);
		cap = cap->next;
	}
}

void adaugareTelevizorInLS(Nod* cap, Televizor tvNou) {
	Nod* capAux = cap;
	if (capAux->next != NULL) {
		cap = capAux->next;
	}

	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->infoUtil = tvNou;
	nou->next = NULL;
	capAux->next = nou;
}

void dezalocareLS(Nod** cap) {
	while (*cap != NULL) {
		Nod* capAux = *cap;
		*cap = (*cap)->next;
		if (capAux->infoUtil.producator != NULL) {
			free(capAux->infoUtil.producator);
		}
		if (capAux->infoUtil.tehnologie != NULL) {
			free(capAux->infoUtil.tehnologie);
		}
		free(capAux);
	}
	*cap = NULL;
}

Table initializareHashTable(int dimensiune) {
	Table table;
	table.dim = dimensiune;
	table.tabelaVector = (Nod**)malloc(dimensiune * sizeof(Nod*));

	for (int i = 0; i < dimensiune; i++) {
		table.tabelaVector[i] = NULL;
	}
	return table;
}

int calculeazaPozitieHash(const char* producatorCautat, int dimensiune) {
	int suma = 0;
	for (int i = 0; i < strlen(producatorCautat); i++) {
		suma += producatorCautat[i];
	}
	return suma % dimensiune;
}

void adaugareTelevizorInTabela(Table table, Televizor tvNou) {
	int pozitie = calculeazaPozitieHash(tvNou.producator, table.dim);
	if (table.tabelaVector[pozitie] == NULL) {
		table.tabelaVector[pozitie] = (Nod*)malloc(sizeof(Nod));
		table.tabelaVector[pozitie]->infoUtil = tvNou;
		table.tabelaVector[pozitie]->next = NULL;
	}
	else {
		adaugareTelevizorInLS(table.tabelaVector[pozitie], tvNou);
	}
}

Table citireTelevizoareTabelaFisier(const char* numeFisier, int dimensiune) {
	Table table = initializareHashTable(dimensiune);
	FILE* file = fopen(numeFisier, "r");
	if (file != NULL) {
		while (!feof(file)) {
			Televizor tv = citireTelevizoareFisier(file);
			adaugareTelevizorInTabela(table, tv);
		}
	}
	fclose(file);
	return table;
}

void afisareTelevizoareTabela(Table table) {
	for (int i = 0; i < table.dim; i++) {
		if (table.tabelaVector[i] != NULL) {
			printf("\nLista masinilor de pe pozitia %d, sunt: \n", i);
			afisareTelevizoareLS(table.tabelaVector[i]);
		}
		else {
			printf("\nPe pozitia %d, nu avem niciun televizor!\n", i);
		}
	}
}

void dezalocareTabela(Table* table) {
	for (int i = 0; i < table->dim; i++) {
		dezalocareLS(&(table->tabelaVector[i]));
	}

	free(table->tabelaVector);
	table->tabelaVector = NULL;
	table->dim = 0;
}

float mediePreturiLista(Nod* cap) {
	float sumaPreturi = 0;
	int contor = 0;
	while (cap != NULL) {
		sumaPreturi += cap->infoUtil.pretTV;
		contor++;
		cap = cap->next;
	}
	if (contor > 0) {
		return sumaPreturi / contor;
	}
}


float* afisareMediePeClustere(Table table, int* nrClustere) {
	
	float* vectorPreturi = 0;
	(*nrClustere) = 0;
	for (int i = 0; i < table.dim; i++) {
		if (table.tabelaVector[i] != NULL) {
			(*nrClustere)++;
		}
	}

	vectorPreturi = (float*)malloc(sizeof(float) * (*nrClustere));
	int contor = 0;
	for (int i = 0; i < table.dim; i++) {
		if (table.tabelaVector[i] != NULL) {
			vectorPreturi[contor] = mediePreturiLista(table.tabelaVector[i]);
			contor++;
		}
	}
	return vectorPreturi;
}

int main() {

	Table table = citireTelevizoareTabelaFisier("televizoare.txt", 6);
	afisareTelevizoareTabela(table);

	int nrClustere = 0;
	float* vectorpreturi = afisareMediePeClustere(table, &nrClustere);

	printf("\nPreturile medii pe clustere sunt:\n");
	for (int i = 0; i < nrClustere; i++) {
		printf("Pentru clusterul %d , media este %.2f RON \n",i, vectorpreturi[i]);
	}

	printf("\nAfisarea tabelei de TV-uri dupa dezalocare!\n");
	dezalocareTabela(&table);
	afisareTelevizoareTabela(table);

	return 0;
}