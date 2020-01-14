#include<iostream>
#include <string>
#include <sstream>
#include<cstdlib>
using namespace std;

int wybor;
int x, y; 
short pesel;

int main()
{
cout << "MENU GLOWNE" << endl;
cout << "Tomasz Wojtarowicz" <<endl;
cout << "-------------------" <<endl;
cout << "1. Zmiana na duze litery" <<endl;
cout << "2. Numer Pesel" <<endl;
cout << "Wybierz cyfre: ";
cin  >> wybor;

switch(wybor)
{
	case 1:
		{
			char znak;
			cin>>znak; 
			while(znak!='.') 
			{
				if(znak>95)
	  				cout<<(char)(znak-32);
				else
					cout<<znak; 
	
				cin>>znak; 
				}
	
			cout<<endl;
			}
	
	case 2:
		{
			cout << "Podaj swoj numer pesel: " << endl;
			cin >> pesel;
			cout << "Twoj numer pesel to: "	<< pesel << endl;
		}		
}


system("pause");
return 0;
}
