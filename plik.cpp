#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int SIZE = 60;
int main()
{
	char filename[SIZE];
	ifstream infile; // obiekt obslugujacy odczyt z pliku
	
	cout << "Wprowadz nazwe pliku: ";
	cin.getline(filename, SIZE);
	infile.open(filename); // polaczenie infile z plikiem
	if (!infile.is_open()) // nieudana proba otwarcia pliku
	{
		cout << "Otwarcie pliku " << filename << "nie powiodlo sie.\n";
		cout << "Program zostanie zakonczony.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0; //liczba elementow do odczytu
	
	infile >> value; //pobieranie pierwszej wartosci
	while (infile.good()) // poki dobre dane i nie EOF
	{
		++count; // wczytano kolejn¹ dan¹
		sum += value; // obliczanie biezacej sumy 
		infile >> value; // pobieranie nastepnej wartosci
	}
	if (infile.eof())
		cout << "Koniec pliku.\n";
	else if (infile.fail())
		cout << "Wczytywanie danych przerwane - blad.\n";
	else 
		cout << "Wczytywanie danych przerwane, przyczyna nieznana.\n";
	if (count == 00)
		cout << "Nie przetworzono zadnych danych.\n";
	else
	{
		cout << "Wczytanych elementow: " << count << endl;
		cout << "Suma: " << sum << endl;
		cout << "Srednia: " << sum / count << endl;
	}
	infile.close(); //zamkniecie pliku
	return 0;
}

