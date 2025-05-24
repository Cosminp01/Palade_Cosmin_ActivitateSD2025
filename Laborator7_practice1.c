//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
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
//struct Heap {
//	Masina* vector;
//	int lungime;
//	int nrMasini;
//};
//typedef struct Heap Heap;
//
//void afisareMasini(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//Masina citireMasinaFisier(FILE* file) {
//
//	Masina m;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
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
//
//	return m;
//}
//
//Heap initializareHeap(int lungime) {
//
//	Heap heap;
//	heap.lungime = lungime;
//	heap.nrMasini = 0;
//	heap.vector = (Masina*)malloc(sizeof(Masina) * lungime);
//
//	return heap;
//}
//
//void filtreazaHeap(Heap heap, int pozitieNod) {
//
//	int pozFiuStanga = 2 * pozitieNod + 1;
//	int pozFiuDreapta = 2 * pozitieNod + 2;
//	int pozMax = pozitieNod;
//
//	if (pozFiuStanga < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuStanga].id) {
//		pozMax = pozFiuStanga;
//	}
//	if (pozFiuDreapta < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuDreapta].id) {
//		pozMax = pozFiuDreapta;
//	}
//
//	if (pozMax != pozitieNod) {
//		Masina aux = heap.vector[pozMax];
//		heap.vector[pozMax] = heap.vector[pozitieNod];
//		heap.vector[pozitieNod] = aux;
//
//		if (pozMax <= (heap.nrMasini - 2) / 2) {
//			filtreazaHeap(heap, pozMax);
//		}
//	}
//}
//
//Heap citireMasiniHeapDinFisier(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	Heap heap = initializareHeap(10);
//
//	while (!feof(file)) {
//		heap.vector[heap.nrMasini++] = citireMasinaFisier(file);
//	}
//	fclose(file);
//
//	for (int i = (heap.nrMasini - 2) / 2; i >= 0; i--){
//		filtreazaHeap(heap, i);
//	}
//	return heap;
//}
//
//void afisareHeapReal(Heap heap) {
//	for (int i = 0; i < heap.nrMasini; i++) {
//		afisareMasini(heap.vector[i]);
//	}
//}
//
//void afisareHeapAscuns(Heap heap) {
//	for (int i = 0; i <= heap.lungime; i++) {
//		afisareMasini(heap.vector[i]);
//	}
//}
//
//Masina extrageMasina(Heap* heap) {
//	//extrage si returneaza masina de pe prima pozitie
//	//elementul extras nu il stergem...doar il ascundem
//	if (heap->nrMasini != 0) {
//		Masina aux = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->nrMasini - 1];
//		heap->vector[heap->nrMasini - 1] = aux;
//		heap->nrMasini--;
//
//		for (int i = (heap->nrMasini - 2) / 2; i >= 0; i--) {
//			filtreazaHeap(*heap, i);
//		}
//		return aux;//shallow copy
//	}
//}
//
//void dezalocareHeap(Heap * heap) {
//		//sterge toate elementele din Heap
//	for (int i = 0; i < heap->lungime; i++) {
//		free(heap->vector[i].model);
//		free(heap->vector[i].numeSofer);
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->lungime = 0;
//	heap->nrMasini = 0;
//	}
//
//int main() {
//
//	Heap heap = citireMasiniHeapDinFisier("masini.txt");
//	afisareHeapReal(heap);
//
//	printf("\nMasini extrase:\n");
//	afisareMasini(extrageMasina(&heap));
//
//	return 0;
//}