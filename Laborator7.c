//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
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
////creare structura pentru Heap
////un vector de elemente, lungimea vectorului si numarul de elemente din vector
//struct Heap {
//	Masina* vector;
//	int lungime;
//	int nrMasini;
//};
//typedef struct Heap Heap;
//
//Masina citireMasiniDinFisier(FILE* file) {
//
//	Masina m;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	m.id = atoi(strtok(buffer, sep));
//	m.nrUsi = atoi(strtok(NULL, sep));
//	m.pret = atof(strtok(NULL, sep));
//	char* aux = strtok(NULL, sep);
//	m.model = (char*)malloc(strlen(aux)+1);
//	strcpy(m.model, aux);
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(strlen(aux)+1);
//	strcpy(m.numeSofer, aux);
//	m.serie = strtok(NULL, sep)[0];
//
//	fclose(file);
//	return m;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//Heap initializareHeap(int lungime) {
//	//initializeaza heap-ul cu 0 elemente 
//	//dar cu o lungime primita ca parametru
//	Heap heap;
//	heap.lungime = lungime;
//	heap.nrMasini = 0;
//	heap.vector = (Masina*)malloc(sizeof(Masina)*lungime);
//
//	return heap;
//}
//
//void filtreazaHeap(Heap heap, int pozitieNod) {
//	//filtreaza heap-ul pentru nodul a carei pozitie o primeste ca parametru
//	//ne declaram cei doi fii , fiuSta fiuDr
//	int pozFiuSt = 2 * pozitieNod + 1;
//	int pozFiuDr = 2 * pozitieNod + 2;
//	//plecam de la scenariul ca pozitia max dintre cele 3 elemente este fix pozitieNod, adica se afla pe pozitia 1
//	//adica radacina este mai mare decat fiuSt si fiuDr
//	int pozMax = pozitieNod;
//	//acum verificam daca chiar pozMax este radacina, petntru asta comparam valoarea radacinii cu valorile fiilor
//	//si de asemenea trebuie sa mai facem o verificare ca valorile celor 2 fii sa fie mai mici decat nr de elemente din vector
//	if (pozFiuSt < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuSt].id) {
//		pozMax = pozFiuSt;
//	}
//	if (pozFiuDr < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuDr].id) {
//		pozMax = pozFiuDr;
//	}
//
//	//dupa ce veriricam acest lucru, verificam daca presupunerea noastra este corecta
//	//adica daca gasim un max, trebuie sa facem inversarea prin metoda paharelor
//	if (pozMax != pozitieNod) {
//		//facem un nou vector ce va primi pozitia Max, pentru a ne putea deplasa cu el
//		Masina aux = heap.vector[pozMax];
//		heap.vector[pozMax] = heap.vector[pozitieNod];
//		heap.vector[pozitieNod] = aux;
//
//		//in acest moment am adus valoarea maxim sus
//		//dar dupa interschimbarea aceasta trebuie sa mai apelam o data filtrarea, adica trebuie sa verificam daca noul nod are fii si daca are sa se aplice algortimul de filtrare
//		//verificam daca fiu stanga este mai mic sau egal decat nr masini -1
//		//2*pozMax + 1 <= heap.nrMasini-1
//		if (pozMax <= ((heap.nrMasini - 2) / 2)) {
//			filtreazaHeap(heap, pozMax);
//		}
//	}
//}
//
////void filtreazaHeap1(Heap heap, int pozitieNod) {
////
////	int pozFiuStanga = 2 * pozitieNod + 1;
////	int pozFiuDreapta = 2 * pozitieNod + 2;
////	int pozMax = pozitieNod;
////
////	if (pozFiuStanga < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuStanga].id) {
////		pozMax = pozFiuStanga;
////	}
////	if (pozFiuDreapta < heap.nrMasini && heap.vector[pozMax].id < heap.vector[pozFiuDreapta].id) {
////		pozMax = pozFiuDreapta;
////	}
////
////	if (pozMax != pozitieNod) {
////		Masina aux = heap.vector[pozMax];
////		heap.vector[pozMax] = heap.vector[pozitieNod];
////		heap.vector[pozitieNod] = aux;
////
////		//pozMax *2 + 1 < = heap.nrMasini -1
////		if (pozMax <= ((heap.nrMasini - 2) / 2)) {
////			filtreazaHeap(heap, pozMax);
////		}
////	}
////}
//
//Heap citireHeapDeMasiniDinFisier(const char* numeFisier) {
//	//citim toate masinile din fisier si le stocam intr-un heap 
//	// pe care trebuie sa il filtram astfel incat sa respecte 
//	// principiul de MAX-HEAP sau MIN-HEAP dupa un anumit criteriu
//	// sunt citite toate elementele si abia apoi este filtrat vectorul
//
//	FILE* file = fopen(numeFisier, "r");
//	Heap heap = initializareHeap(10);
//	while (!feof(file)) {
//		heap.vector[heap.nrMasini++] = citireMasiniDinFisier(file);
//	}
//	fclose(file);
//
//	for (int i = (heap.nrMasini - 2)/2; i >= 0; i--) {
//		filtreazaHeap(heap, i);
//	}
//	
//	return heap;
//}
//
//void afisareHeap(Heap heap) {
//	//afiseaza elementele vizibile din heap
//	for (int i = 0; i < heap.nrMasini; i++) {
//		afisareMasina(heap.vector[i]);
//	}
//}
//
//void afiseazaHeapAscuns(Heap heap) {
//	//afiseaza elementele ascunse din heap
//	for (int i = 0; i < heap.lungime; i++) {
//		afisareMasina(heap.vector[i]);
//	}
//}
//
//Masina extrageMasina(void* heap) {
//	//extrage si returneaza masina de pe prima pozitie
//	//elementul extras nu il stergem...doar il ascundem
//}
//
//
//void dezalocareHeap(Heap* heap) {
//	//sterge toate elementele din Heap
//}
//
//int main() {
//
//	Heap heap = citireHeapDeMasiniDinFisier("masini.txt");
//	afisareHeap(heap);
//
//	return 0;
//}