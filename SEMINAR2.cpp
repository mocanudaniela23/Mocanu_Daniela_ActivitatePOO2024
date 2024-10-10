#include <iostream>
#include <string>
using namespace std;
struct Tara {
	char* denumire;
	int nrlocuitori;
	string capitala;
	bool areiesirelamare;
};

void afisareTara(Tara tara)
{

}

Tara* citirePointerLaTara()
{
	Tara* p = new Tara();
	cout << "capitala:";
	cin >> p->capitala;
	cout << "Denumire:";
	char buffer[100];
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);
	cout << "Numar locuitori:";
	cin >> p->nrlocuitori;
	cout << "Are iesire la mare? (0-NU; 1-DA)";
	cin >> p->areiesirelamare;
	return p;
	//char aux;
	//if(aux=='Y' ||
}

void afisarePointerLaTara(Tara* pt)
{
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrlocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areiesirelamare ? "DA" : "NU") << endl;
}

int main()
{
	Tara tara;
	tara.areiesirelamare = false;
	Tara* pTara;
	pTara = &tara; // sau new Tara()
	pTara->areiesirelamare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nrlocuitori = 200;

	afisarePointerLaTara(pTara);

	Tara* p2Tara = citirePointerLaTara();
	afisarePointerLaTara(p2Tara);

	delete[]pTara->denumire;
	delete pTara;

	Tara* vector;
	vector = new Tara[2];

	delete[]vector;

	int nrPointeri = 2;
	//vector de pointeri
	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];
	for (int i = 0; i < nrPointeri; i++)
	{
		pointeri[i] = citirePointerLaTara();
	}
	//procesare

	for (int i = 0; i < nrPointeri; i++)
	{
		afisarePointerLaTara(pointeri[i]);
	}
	for (int i = 0; i < nrPointeri; i++)
	{
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}
	delete[]pointeri;
	//memory leak=o zona de memorie care nu a fost dezalocata si nu mai avem adresa de referinta a zonei catre ea
}