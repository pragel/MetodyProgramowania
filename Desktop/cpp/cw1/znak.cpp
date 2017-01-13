#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	cout << "Podaj dowolne znaki (liczby nie zostana wyœwietlone) - zakoncz wprowadzanie za pomoca @: \n";
	char ch;
	cin >> ch;
	cin.get(ch);
	while(ch != '@')
	{
		if(isalpha(ch)){
			cout << ch << endl;
		}
		else if(isupper(ch))
			cout << tolower(ch) << endl;
		else if (islower(ch)){
			cout << toupper(ch);
		}
		cin.get(ch);
	}
}
