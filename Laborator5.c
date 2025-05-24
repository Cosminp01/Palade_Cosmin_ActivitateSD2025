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

struct Nod {
	Televizor infoUtil;
	struct Nod* next;
	struct Nod* prev;
};

typedef struct Nod Nod;

//structura Lista dubla
struct ListaDubla {
	Nod* first;
	Nod* last;
	int nrNoduri;
};
typedef struct ListaDubla ListaDubla;

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
	char sep[4] = ",;\n";
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

void afisareListaDublaDeLaInceput(ListaDubla lista) {
	Nod* capAux = lista.first;
	while (capAux != NULL) {
		afisareTelevizoare(capAux->infoUtil);
		capAux = capAux->next;
	}
}

void afisareListaDublaDeLaSfarsit(ListaDubla lista) {
	Nod* capAux = lista.last;
	while (capAux != NULL) {
		afisareTelevizoare(capAux->infoUtil);
		capAux = capAux->prev;
	}
}

void adaugareNodListaDublaFinal(ListaDubla* lista, Televizor televizorNou) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->infoUtil = televizorNou;
	nou->next = NULL;
	nou->prev = lista->last;
	if (lista->last != NULL) {
		lista->last->next = nou;
	}
	else {
		lista->first = nou;
	}
	lista->last = nou;
	lista->nrNoduri++;
}

void adaugareNodListaDublaInceput(ListaDubla* lista, Televizor televizorNou) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->infoUtil = televizorNou;
	nou->prev = NULL;
	nou->next = lista->first;

	if (lista->first != NULL) {
		lista->first->prev = nou;
	}
	else {
		lista->last = nou;
	}
	lista->first = nou;
	lista->nrNoduri++;
}

ListaDubla citireListaDublaFisier(const char* numeFisier) {//transmitere prin valoare
	
	ListaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;
	FILE* file = fopen(numeFisier, "r");
	if (file != NULL) {
		while (!feof(file)) {
			adaugareNodListaDublaFinal(&lista, citireTelevizoareFisier(file));
		}
	}
	fclose(file);
	return lista;
}

void dezalocareListaDubla(ListaDubla* lista) {
	Nod* nodAux = lista->first;
	while (nodAux != NULL) {
		Nod* capAux = nodAux;
		capAux = capAux->next;
		if (capAux->infoUtil.producator != NULL) {
			free(capAux->infoUtil.producator);
		}
		if (capAux->infoUtil.tehnologie != NULL) {
			free(capAux->infoUtil.tehnologie);
		}
		free(capAux);
	}
	
	lista->first = NULL;
	lista->last = NULL;
	lista->nrNoduri = 0;
	
}

float mediaPretTelevizoare(ListaDubla lista) {
	if (lista.nrNoduri > 0) {
		float sumaTotala = 0;
		Nod* nodAux = lista.first;//iau o lista aditionala careia ii asociezi adresa primul nod
		if (nodAux != NULL) {
			sumaTotala += nodAux->infoUtil.pretTV;
			nodAux = nodAux->next;
		}
		return sumaTotala / lista.nrNoduri;
	}
	return 0;
}

void stergereNodListaDubla(ListaDubla* lista, int idCautat) {
	
	if (lista->first == NULL) {
		return;
	}
	Nod* capAux = lista->first;
	while (capAux != NULL && capAux->infoUtil.id != idCautat) {
		capAux = capAux->next;
	}
	if (capAux == NULL) {
		return;
	}

	if (capAux->prev == NULL) {
		lista->first = capAux->next;
		if (lista->first != NULL) {
			lista->first->prev = NULL;
		}
	}
	else {
		capAux->prev->next = capAux->next;
		if (capAux->next != NULL) {
			capAux->next->prev = capAux->prev;
		}
		else {
			lista->last = capAux->prev;
		}
	}
	if (capAux->infoUtil.producator != NULL) {
		free(capAux->infoUtil.producator);
	}
	if (capAux->infoUtil.tehnologie != NULL) {
		free(capAux->infoUtil.tehnologie);
	}
	free(capAux);
	lista->nrNoduri--;
}

int main()
{
	ListaDubla lista = citireListaDublaFisier("televizoare.txt");
	afisareListaDublaDeLaInceput(lista);

	printf("\n-----------------\n");
	printf("\nAfisare LD de la sfarsit:\n");
	stergereNodListaDubla(&lista, 4);
	afisareListaDublaDeLaSfarsit(lista);

	printf("\n-----------------\n");
	printf("\nPretul mediu al televizoarelor este: %5.2f\n", mediaPretTelevizoare(lista));

	printf("\n-----------------\n");
	printf("\nAFisare dupa DEZALOCARE!!\n");
	dezalocareListaDubla(&lista);
	
	return 0;
}