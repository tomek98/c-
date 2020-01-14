#include<iostream>
#include<cstdlib>
using namespace std;

int wybor;
int x, y; 

int main()
{
cout << "MENU GLOWNE" << endl;
cout << "Tomasz Wojtarowicz" <<endl;
cout << "-------------------" <<endl;
cout << "1. Zmiana na duze litery" <<endl;
cout << "Wybierz literê: ";
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
}


system("pause");
return 0;
}
