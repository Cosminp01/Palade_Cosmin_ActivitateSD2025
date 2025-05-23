//#define _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
//
//struct InformatiiBilet {
//	int id;
//	char* titlu;
//	char* dataLansare;
//	unsigned char rand;
//	double loc;
//	float pretBilet;
//};
//typedef struct InformatiiBilet Bilet;
//
//struct Heap {
//	Bilet* vector;
//	int lungime;
//	int nrBilete;
//};
//typedef struct Heap Heap;
//
//void afisareBilete(Bilet bilet) {
//	printf("Biletul cu id-ul %d, are urmatoarele informatii:\n", bilet.id);
//	printf("Titlu film: %s\n", bilet.titlu);
//	printf("Data lansare: %s\n", bilet.dataLansare);
//	printf("Serie rand: %c\n", bilet.rand);
//	printf("Locul in sala: %.2f\n", bilet.loc);
//	printf("Pret bilet: %5.2f\n\n", bilet.pretBilet);
//}
//
//Bilet citireBileteFisier(FILE* file) {
//
//	Bilet b;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	b.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	b.titlu = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.titlu, aux);
//	aux = strtok(NULL, sep);
//	b.dataLansare = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.dataLansare, aux);
//	b.rand = strtok(NULL, sep)[0];
//	b.loc = strtod(strtok(NULL, sep), NULL);
//	b.pretBilet = atof(strtok(NULL, sep));
//
//	return b;
//}
//
//Heap initializareHeap(int lungime) {
//	
//	Heap heap;
//	heap.lungime = lungime;
//	heap.nrBilete = 0;
//	heap.vector = (Bilet*)malloc(sizeof(Bilet) * lungime);
//
//	return heap;
//}
//
//void filtrareHeap(Heap heap, int pozNod) {
//
//	int pozFiuSt = 2 * pozNod + 1;
//	int pozFiuDr = 2 * pozNod + 2;
//	int pozMax = pozNod;
//
//	if (pozFiuSt < heap.nrBilete && heap.vector[pozMax].id < heap.vector[pozFiuSt].id) {
//		pozMax = pozFiuSt;
//	}
//	if (pozFiuDr < heap.nrBilete && heap.vector[pozMax].id < heap.vector[pozFiuDr].id) {
//		pozMax = pozFiuDr;
//	}
//
//	if (pozMax != pozNod) {
//		Bilet aux = heap.vector[pozMax];
//		heap.vector[pozMax] = heap.vector[pozNod];
//		heap.vector[pozNod] = aux;
//
//		if (pozMax <= (heap.nrBilete - 2) / 2) {
//			filtrareHeap(heap, pozMax);
//		}
//	}
//}
//
//Heap citireBileteHeapFisier(const char* numeFisier) {
//	
//	FILE* file = fopen(numeFisier, "r");
//	Heap heap = initializareHeap(10);
//	while (!feof(file)) {
//		heap.vector[heap.nrBilete++] = citireBileteFisier(file);
//	}
//	fclose(file);
//
//	for (int i = (heap.nrBilete - 2 / 2); i >= 0; i--) {
//		filtrareHeap(heap, i);
//	}
//	return heap;
//}
//
//void afisareBileteRealHeap(Heap heap) {
//
//	for (int i = 0; i < heap.nrBilete; i++) {
//		afisareBilete(heap.vector[i]);
//	}
//}
//
//void afisareBileteAscunsHeap(Heap heap) {
//
//	for (int i = 0; i < heap.lungime; i++) {
//		afisareBilete(heap.vector[i]);
//	}
//}
//
//void dezalocareHeap(Heap* heap) {
//
//	for (int i = 0; i < heap->lungime; i++) {
//		free(heap->vector[i].titlu);
//		free(heap->vector[i].dataLansare);
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->lungime = 0;
//	heap->nrBilete = 0;
//}
//
//Bilet extragereBiletHeap(Heap* heap) {
//
//	if (heap->nrBilete > 0) {
//		Bilet aux = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->nrBilete - 1];
//		heap->vector[heap->nrBilete - 1] = aux;
//
//		for (int i = (heap->nrBilete - 2 / 2); i >= 0; i--) {
//			filtrareHeap(*heap, i);
//		}
//		return aux;
//	}
//}
//
//int main() {
//
//	Heap heap;
//	heap.lungime = 0;
//	heap.nrBilete = 0;
//
//	heap = citireBileteHeapFisier("bilete_film.txt");
//	afisareBileteRealHeap(heap);
//	printf("\n----------\n");
//	printf("Afisare bilet extras:\n");
//	afisareBilete(extragereBiletHeap(&heap));
//
//	printf("\n----------\n");
//	printf("Afisare bilete dupa dezalocarea memoriei!\n");
//	dezalocareHeap(&heap);
//
//	return 0;
//}