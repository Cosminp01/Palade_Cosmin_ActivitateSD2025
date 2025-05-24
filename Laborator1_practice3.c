//#include<stdio.h>
//#include<stdlib.h>
//
//
//struct Parcare {
//	int id;
//	float suprafata;
//	char* proprietar;
//	double pret;
//	char segment;
//};
//
//struct Parcare initializare(int idParcare, float suprafataParcare, const char* proprietarParcare, double pretParcare, char segementParcare) {
//	struct Parcare p;
//	p.id = idParcare;
//	p.suprafata = suprafataParcare;
//	p.proprietar = (char*)malloc(sizeof(char) * (strlen(proprietarParcare) + 1));
//	strcpy_s(p.proprietar, strlen(proprietarParcare) + 1, proprietarParcare);
//	p.pret = pretParcare;
//	p.segment = segementParcare;
//	return p;
//}
//
//void afisareParcari(struct Parcare p) {
//	if (p.proprietar != NULL) {
//		printf("Lotul de parcare cu nr %d, cu suprafata de %.5.2f, din segmentul %c, avand un pret de %.2f, apartine locatarului %s!\n",
//			p.id, p.suprafata, p.segment, p.pret, p.proprietar);
//	}
//	else {
//		printf("Lotul de parcare cu nr %d, este disponibil!\n", p.id);
//	}
//}
//
//void dezalocare(struct Parcare* p) {
//	if (p->proprietar != NULL) {
//		free(p->proprietar);
//		p->proprietar = NULL;
//	}
//}
//
//int main()
//{
//	struct Parcare p;
//	p = initializare(105, 12.5, "Palade", 4999.99, 'A');
//	afisareParcari(p);
//	dezalocare(&p);
//	return 0;
//}