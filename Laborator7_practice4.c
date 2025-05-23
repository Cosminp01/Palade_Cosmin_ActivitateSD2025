//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct informatiiDomiciliu {
//
//	int id;
//	char* judet;
//	char* localitate;
//	char* strada;
//	double nrStrada;
//	int nrBloc;
//	unsigned char scara;
//	float etaj;
//};
//typedef struct informatiiDomiciliu Domiciliu;
//
//struct Nod {
//	Domiciliu infoUtil;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//struct Heap {
//	Domiciliu* vector;
//	int lungime;
//	int nrDomicilii;
//};
//typedef struct Heap Heap;
//
//void afisareDomicilii(Domiciliu d) {
//
//	printf("Informatii domiciliu %d:\n", d.id);
//	printf("Judet: %s\n", d.judet);
//	printf("Localitate: %s\n", d.localitate);
//	printf("Strada: %s\n", d.strada);
//	printf("Nr strada: %.2f\n", d.nrStrada);
//	printf("Bloc: %d\n", d.nrBloc);
//	printf("Scara: %c\n", d.scara);
//	printf("Etaj: %5.2f\n\n", d.etaj);
//}
//
//Domiciliu citireDomiciliiFisier(FILE* file) {
//
//	Domiciliu d;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	d.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	d.judet = (char*)malloc(strlen(aux) + 1);
//	strcpy(d.judet, aux);
//	aux = strtok(NULL, sep);
//	d.localitate = (char*)malloc(strlen(aux) + 1);
//	strcpy(d.localitate, aux);
//	aux = strtok(NULL, sep);
//	d.strada = (char*)malloc(strlen(aux) + 1);
//	strcpy(d.strada, aux);
//	d.nrStrada = strtod(strtok(NULL, sep), NULL);
//	d.nrBloc = atoi(strtok(NULL, sep));
//	d.scara = strtok(NULL, sep)[0];
//	d.etaj = atof(strtok(NULL, sep));
//	
//	return d;
//}
//
//Heap initializareHeap(int lungime) {
//
//	Heap heap;
//	heap.lungime = lungime;
//	heap.nrDomicilii = 0;
//	heap.vector = (Domiciliu*)malloc(sizeof(Domiciliu)*lungime);
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
//	if (pozFiuSt < heap.nrDomicilii && heap.vector[pozMax].id < heap.vector[pozFiuSt].id) {
//		pozMax = pozFiuSt;
//	}
//	if (pozFiuDr < heap.nrDomicilii && heap.vector[pozMax].id < heap.vector[pozFiuDr].id) {
//		pozMax = pozFiuDr;
//	}
//
//	if (pozMax != pozNod) {
//		Domiciliu nou = heap.vector[pozMax];
//		heap.vector[pozMax] = heap.vector[pozNod];
//		heap.vector[pozNod] = nou;
//
//		if (pozMax <= (heap.nrDomicilii - 2) / 2) {
//			filtrareHeap(heap, pozMax);
//		}
//	}
//}
//
//void afisareHeapReal(Heap heap) {
//
//	for (int i = 0; i < heap.nrDomicilii; i++) {
//		afisareDomicilii(heap.vector[i]);
//	}
//}
//
//void afisareHeapAscuns(Heap heap) {
//	for (int i = 0; i < heap.lungime; i++) {
//		afisareDomicilii(heap.vector[i]);
//	}
//}
//
//Heap citireDomiciliiHeapFisier(const char* numeFisier) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Heap heap = initializareHeap(10);
//	while (!feof(file)) {
//		heap.vector[heap.nrDomicilii++] = citireDomiciliiFisier(file);
//	}
//	fclose(file);
//
//	for (int i = ((heap.nrDomicilii - 2) / 2); i >= 0; i--) {
//		filtrareHeap(heap, i);
//	}
//	return heap;
//}
//
//void dezalocareHeap(Heap* heap) {
//
//	for (int i = 0; i < heap->lungime; i++) {
//		free(heap->vector[i].judet);
//		free(heap->vector[i].localitate);
//		free(heap->vector[i].strada);
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->lungime = 0;
//	heap->nrDomicilii = 0;
//}
//
//Domiciliu extragereDomiciliuDinHeap(Heap* heap) {
//
//	if (heap->nrDomicilii > 0 ) {
//		Domiciliu nou = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->nrDomicilii - 1];
//		heap->vector[heap->nrDomicilii - 1] = nou;
//		heap->nrDomicilii--;
//
//		for (int i = (heap->nrDomicilii - 2) / 2; i >= 0; i--) {
//			filtrareHeap(*heap, i);
//		}
//		return nou;
//	}
//}
//
//int main() {
//
//	Heap heap;
//	heap.lungime = 0;
//	heap.nrDomicilii = 0;
//
//	heap = citireDomiciliiHeapFisier("domicilii.txt");
//	afisareHeapReal(heap);
//
//	printf("\n-------Extragere Heap!-------\n");
//	afisareDomicilii(extragereDomiciliuDinHeap(&heap));
//
//	printf("\n-------Extragere Heap!-------\n");
//	afisareDomicilii(extragereDomiciliuDinHeap(&heap));
//
//	printf("\n-------Afisare heap dupa dezalocare!-------\n");
//	dezalocareHeap(&heap);
//	afisareHeapReal(heap);
//
//	return 0;
//}