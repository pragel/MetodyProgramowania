#include <iostream>
using namespace std;

void menu();
void cos();
void tak();
void nie();
void bam();

int main()
{
	menu();
	int wybor;
	cin >> wybor;
	cout << endl;
	while(wybor != 5)
	{
		switch(wybor)
		{
			case 1 : cos();
				break;
			case 2 : tak();
				break;
			case 3 : nie();
				break;
			case 4 : bam();
				break;
			default : cout << "Cos nie wyszlo. Jeszcze raz \n";
		}
		menu();
		cin >> wybor;
		cout << endl;
	}
	cout << "This is POLSKA\nTakie realia :)";
	
	return 0;
}
void menu()
{
	cout << "Piec zlotych liczb na co czekasz wybierz cos: \n1-2-3-4 albo 5:\n1)takietam\t2)ktowie\n3)niewazne\t4)niewiem\n5)format\nNo to dawaj: ";
}
void cos()
{
	cout << "Proboj dalej\n" << endl;
}
void tak()
{
	cout << "Nadal nic\n" << endl;
}
void nie()
{
	cout << "To nie tu\n" << endl;
}
void bam()
{
	cout << "Tutaj tez nic nie znajdziesz :)\n" << endl;
}
