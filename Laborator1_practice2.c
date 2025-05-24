//#include<stdio.h>
//#include<stdlib.h>
//
//
//struct Apartamente {
//	int id;
//	float suprafata;
//	char* cartier;
//	double pret;
//	int anConstructie;
//};
//
////cream o functie de initializare a unui apartament
//struct Apartamente initializare(int idApartament, float suprafataAp, const char* numeCartier, double pretApartament, int anConstructieApartament) {
//	struct Apartamente a;
//	a.id = idApartament;
//	a.suprafata = suprafataAp;
//	a.cartier = (char*)malloc(sizeof(char) * (strlen(numeCartier) + 1));
//	strcpy_s(a.cartier, strlen(numeCartier) + 1, numeCartier);
//	a.pret = pretApartament;
//	a.anConstructie = anConstructieApartament;
//	return a;
//};
//
//void afisareApartamente(struct Apartamente a) {
//	if (a.cartier != NULL) {
//		printf("%d. Apartamentul este construit in anul %d, are o suprafata de %5.2f mp si se afla in cartierul %s. Pretul total este de %.3f EURO!\n",
//			a.id, a.anConstructie, a.suprafata, a.cartier, a.pret);
//	}
//	else {
//		printf("Apartamentul nu mai este disponibil!");
//	}
//}
//
//void dezalocare(struct Apartamente* a)//se transmite prin pointer in momentul incare dorim sa i facem o modificare
//{
//	//verificam daca pointer ul nostru este diferit de NULL
//	if (a->cartier != NULL) {
//		free(a->cartier);
//		//in acest moment noi eliberam spatiul de memorie a blocului
//		//dar daca lasam asa, in continuare , pointer ul meu va retine adresa catre acel bloc, care este sters
//		//recomandat este sa l initializam cu NULL pt a nu mai retine nicio adresa in interioul acestuia
//		a->cartier = NULL;
//	}
//}
//
//void modificarePret(struct Apartamente* a, double pretNou) 
////se transmite prin valoare
////adica, se copiaza din stiva de memorie a functiei main, pretul declarat pt apartament, in stiva de memorie a functiei modificarePret
//{
//	if (a->pret > 0) {//se veririca ca acea valaore sa fie mai mare de 0
//		a->pret = pretNou;//se face dereferentiere
//		printf("Noul pret al apartamentului este de %.3f!\n", a->pret);
//	}
//}
//
//int main()
//{
//	struct Apartamente a;
//	a = initializare(10, 78.5, "Rahova", 109999.991, 2024);
//	afisareApartamente(a);
//	printf("\n");
//	printf("Noul pret este!\n");
//	modificarePret(&a, 125000.012);
//	dezalocare(&a);
//	return 0;
//}