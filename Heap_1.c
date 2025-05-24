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
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//struct Heap {
//	Vacanta* vector;
//	int lungime;
//	int nrVacante;
//};
//typedef struct Heap Heap;
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
//Heap initializareHeap(int lungime) {
//
//	Heap heap;
//	heap.lungime = 0;
//	heap.nrVacante = 0;
//	heap.vector = (Vacanta*)malloc(sizeof(Vacanta) * lungime);
//
//	return heap;
//}
//
//void filtrareHeap(Heap heap, int pozNod) {
//
//	int pozFiuStanga = 2 * pozNod + 1;
//	int pozFiuDreapta = 2 * pozNod + 2;
//
//	int pozMax = pozNod;
//	if (pozFiuStanga < heap.nrVacante && heap.vector[pozMax].idVacanta < heap.vector[pozFiuStanga].idVacanta) {
//		pozMax = pozFiuStanga;
//	}
//	if (pozFiuDreapta < heap.nrVacante && heap.vector[pozMax].idVacanta < heap.vector[pozFiuDreapta].idVacanta) {
//		pozMax = pozFiuDreapta;
//	}
//
//	if (pozMax != pozNod) {
//		Vacanta nou = heap.vector[pozMax];
//		heap.vector[pozMax] = heap.vector[pozNod];
//		heap.vector[pozNod] = nou;
//
//		if (pozMax <= (heap.nrVacante - 2) / 2) {
//			filtrareHeap(heap, pozMax);
//		}
//	}
//}
//
//Heap citireVacanteHeapFisier(const char* numeFisier) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Heap heap = initializareHeap(10);
//	while (!feof(file)) {
//		heap.vector[heap.nrVacante++] = citireVacanteFisier(file);
//	}
//	fclose(file);
//
//	for (int i = (heap.nrVacante - 2) / 2; i >= 0; i--) {
//		filtrareHeap(heap, i);
//	}
//	return heap;
//}
//
//void afisareHeapReal(Heap heap) {
//
//	for (int i = 0; i < heap.nrVacante; i++) {
//		afisareVacante(heap.vector[i]);
//	}
//}
//
//void afisareHeapAscuns(Heap heap) {
//
//	for (int i = 0; i < heap.lungime; i++) {
//		afisareVacante(heap.vector[i]);
//	}
//}
//
//void dezalocareHeap(Heap* heap) {
//
//	for (int i = 0; i < heap->lungime; i++) {
//		free(heap->vector[i].destinatie);
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->lungime = 0;
//	heap->nrVacante = 0;
//}
//
//Vacanta extragereVacanta(Heap* heap, int idCautat) {
//
//	if (heap->nrVacante > 0) {
//		Vacanta nou = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->nrVacante - 1];
//		heap->vector[heap->nrVacante - 1] = nou;
//		heap->nrVacante--;
//
//		for (int i = (heap->nrVacante - 2) / 2; i >= 0; i--) {
//			filtrareHeap(*heap, i);
//		}
//		return nou;
//	}
//}
//
//int main() {
//
//	Heap heap = citireVacanteHeapFisier("vacante.txt");
//	afisareHeapReal(heap);
//
//	printf("\n------Afisare Heap ASCUNS!------\n");
//	afisareHeapAscuns(heap);
//
//	printf("\n------Afisare NOD Extras!-------\n");
//	afisareVacante(extragereVacanta(&heap, 10));
//
//	printf("\n------Afisare HEAP DEZALOCARE!------\n");
//	dezalocareHeap(&heap);
//	afisareHeapReal(heap);
//
//	return 0;
//}