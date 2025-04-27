#include <stdio.h>
#include<stdlib.h>

/*int main() {
	printf("Salutare!\n Introduceti un nr intreg:");
	int variabila = 0;
	scanf_s("%d", &variabila);
	printf("Ai introdus: %d", variabila);
	return 0;

}*/

struct Masina {
	int id;
	char* Marca;
	float pret;
	int Anfabricatie;
};

struct Masina initializareMasina(int ID, const char* MarcaMasina, float PretMasina, int AndeFabricatie) {
	struct Masina m;
	m.id = ID;
	m.Marca = (char*)malloc(sizeof(char) * (strlen(MarcaMasina) + 1));
	strcpy_s(m.Marca, strlen(m.Marca) + 1, MarcaMasina);
	m.pret = PretMasina;
	m.Anfabricatie = AndeFabricatie;
	return m;
}

void afisareMasini(struct Masina m) {
	if (m.Marca != NULL) {
		printf("%d. Masina %c fabricata in anul %d, are pretul de %5.2f.\n",
			m.id, m.Marca, m.Anfabricatie, m.pret);
	}
	else {
		printf("%d. Masina fabricata in anul %d, are pretul de %5.2f.\n",
			m.id, m.Anfabricatie, m.pret);
	}
}

int main(){
	struct Masina m;
	m = initializareMasina(1, "VW", 15250.34, 2024);
	afisareMasini(m);
	return 0;
}