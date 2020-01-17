#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#pragma hdrstop
#define MAX 100

using namespace std;

void SaveData();
void LoadData();

class PhoneBook
{
      public:
             
      string nameDatabase;
      
      int ID[MAX];
      string name[MAX];
      string surname[MAX];
      string city[MAX];
      string address[MAX];
      string pNumber[MAX];
            
      void Initialize();
      void NewRecord(string, string, string, string, string);
      void DelRecord(int);
      void Search(int, string);
      void List();
      void ListSort();
      int GetSize();
};

void PhoneBook::Initialize()
{
     for(int i=0;i<MAX;i++)
     {
         name[i] = ""; surname[i] = ""; city[i] = "";
         address[i] = ""; pNumber[i] = ""; ID[i] = 0;
     }
}

void PhoneBook::NewRecord(string n, string s, string c, string a, string p)
{
     for(int i=0;i<MAX;i++)
     {
         if(ID[i] == 0)
         {
             name[i] = n;
             surname[i] = s;
             city[i] = c;
             address[i] = a;
             pNumber[i] = p;
             ID[i] = 1;
             break;
         }
     }
}

void PhoneBook::DelRecord(int id)
{
     name[id - 1] = ""; surname[id - 1] = ""; city[id - 1] = "";
     address[id -1] = ""; pNumber[id -1] = ""; ID[id -1] = 0;
     
     for(int i=(id - 1);i<MAX;i++)
     {
         if(i != (MAX - 1))
         {
             name[i] = name[i + 1];
             surname[i] = surname[i + 1];
             city[i] = city[i + 1];
             address[i] = address[i + 1];
             pNumber[i] = pNumber[i + 1];
             ID[i] = ID[i + 1];
         }
         else
         {
             name[i] = "";
             surname[i] = "";
             city[i] = "";
             address[i] = "";
             pNumber[i] = "";
             ID[i] = 0;
         }
     }
}

void PhoneBook::Search(int c, string val)
{
     cout << "===================================================" << endl;
     cout << "Wyniki wyszukiwania: " << nameDatabase << endl;
     cout << "===================================================" << endl;
     
     if(c == 1)
     {
         for(int i=0;i<MAX;i++)
         {
             if(ID[i] == 1)
             {
                if(surname[i] == val)
                {
                     cout << (i + 1) << " " << surname[i] << "\t" << name[i] << "\t" << city[i] << "\t" << address[i] << "\t" << pNumber[i] << endl; 
                }
             }
         }  
     }
     else if(c == 2)
     {
         for(int i=0;i<MAX;i++)
         {
             if(ID[i] == 1)
             {
                if(name[i] == val)
                {
                     cout << (i + 1) << " " << surname[i] << "\t" << name[i] << "\t" << city[i] << "\t" << address[i] << "\t" << pNumber[i] << endl; 
                }
             }
         }  
     }
     else if(c == 3)
     {
         for(int i=0;i<MAX;i++)
         {
             if(ID[i] == 1)
             {
                if(city[i] == val)
                {
                     cout << (i + 1) << " " << surname[i] << "\t" << name[i] << "\t" << city[i] << "\t" << address[i] << "\t" << pNumber[i] << endl; 
                }
             }
         }  
     }
     else if(c == 4)
     {
         for(int i=0;i<MAX;i++)
         {
             if(ID[i] == 1)
             {
                if(address[i] == val)
                {
                     cout << (i + 1) << " " << surname[i] << "\t" << name[i] << "\t" << city[i] << "\t" << address[i] << "\t" << pNumber[i] << endl; 
                }
             }
         }  
     }
     else
     {
         for(int i=0;i<MAX;i++)
         {
             if(ID[i] == 1)
             {
                if(pNumber[i] == val)
                {
                     cout << (i + 1) << " " << surname[i] << "\t" << name[i] << "\t" << city[i] << "\t" << address[i] << "\t" << pNumber[i] << endl; 
                }
             }
         }  
     }
     
     getch();
}

void PhoneBook::List()
{
     cout << "===================================================" << endl;
     cout << "Wszystkie rekordy bazy danych: " << nameDatabase << endl;
     cout << "===================================================" << endl;
     int checkValue = 0;
     
     for(int i=0;i<MAX;i++)
     {
         if(ID[i] != 0)
         {
             cout << (i + 1) << " " << surname[i] << "\t" << name[i] << "\t" << city[i] << "\t" << address[i] << "\t" << pNumber[i] << endl; 
             checkValue++;          
         }
     }
     
     if(checkValue == 0)
     {
          cout << "W bazie danych nie ma zadnych rekordow !";
          getch();
     }
     else
     {
         getch();
     }
}

//PhoneBook dane;

//void PhoneBook::ListSort()
//{    
//    int tc = 0;
//    int counter = GetSize();
//    string ts[counter][5];
//    
//    for(int i=0;i<MAX;i++)
//    {
//            if(ID[i] == 1)
//            {
//                    ts[tc][0] = surname[i];
//                    ts[tc][1] = name[i];
//                    ts[tc][2] = city[i];
//                    ts[tc][3] = address[i];
//                    ts[tc][4] = pNumber[i];
//                    tc++; 
//            }
//    }
//    
//    for (int i = counter - 1; i > 0; i--)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            string p1 = ts[j][0];
//            string d1 = ts[j + 1][0];
//                    
//            string p2 = ts[j][1];
//            string d2 = ts[j + 1][1];
//            
//            string p3 = ts[j][2];
//            string d3 = ts[j + 1][2];
//            
//            string p4 = ts[j][3];
//            string d4 = ts[j + 1][3];
//            
//            string p5 = ts[j][4];
//            string d5 = ts[j + 1][4];
//                    
//            if (p1 > d1)
//            {
//                ts[j][0] = d1;
//                ts[j + 1][0] = p1;
//                
//                ts[j][1] = d2;
//                ts[j + 1][1] = p2;
//                
//                ts[j][2] = d3;
//                ts[j + 1][2] = p3;
//                
//                ts[j][3] = d4;
//                ts[j + 1][3] = p4;
//                
//                ts[j][4] = d5;
//                ts[j + 1][4] = p5;
//            }
//        }
//    }
//    
//    for(int i=0;i<counter;i++)
//    {
//            cout << ts[i][0] << "\t" << ts[i][1] << "\t" << ts[i][2] << "\t" << ts[i][3] << "\t" << ts[i][4] << "\t" << endl;
//    }
//    
//    getch();
//}

int PhoneBook::GetSize()
{
    int size = 0;
    for(int i=0;i<MAX;i++)
    {
        if(ID[i] == 1)
        {
            size++;
        }
    }
    
    return size;
}
      
int main()
{
    LoadData();
    
    if(dane.nameDatabase == "")
    {
        string bName;
        cout << "===================================================" << endl;
        cout << "Baza danych teleadresowych" << endl;
        cout << "===================================================";
        cout << endl << endl;
        cout << "Podaj nazwe dla nowej bazy danych: "; cin >> bName; 
        dane.nameDatabase = bName;                    
    }
    
    DEFAULT:
    system("cls");
    cout << "Zarzadzanie baza danych: " << dane.nameDatabase << endl;
    cout << "===================================================" << endl << endl;
    cout << "  1. Dodaj nowy rekord" << endl;
    cout << "  2. Usun rekord" << endl;
    cout << "  3. Pokaz wszystkie" << endl;
    cout << "  4. Pokaz posortowane dane" << endl;
    cout << "  5. Wyszukaj" << endl;
    cout << "  6. Zapisz baze i wyjdz" << endl << endl;
    
    int stats = dane.GetSize();
    char choice;
    
    cout << "Statystyki:" << endl;
    cout << "===================================================" << endl;
    cout << "Pojemnosc bazy: " << MAX << ", zajetych: " << stats << ", wolnych: " << MAX - stats << endl;
    cout << "===================================================" << endl;
    cout << "Autor: Krzysztof Wa³êska" << endl << endl;
    cout << "Twoj wybor: "; cin >> choice;
    
    switch(choice)
    {
        case '1' :
             {
                 system("cls");
                 string n, s, c, a, p;
                 cout << "===================================================" << endl;
                 cout << "Podaj imie i nazwisko: ";
                 cin >> n; cin >> s;
                 cout << "===================================================" << endl;
                 cout << "Podaj miejscowosc: ";
                 cin >> c;
                 cout << "===================================================" << endl;
                 cout << "Podaj nazwe ulicy: ";
                 cin >> a;
                 cout << "===================================================" << endl;
                 cout << "Podaj numer telefonu: ";
                 cin >> p;
                 
                 dane.NewRecord(n, s, c, a, p);
                 goto DEFAULT;
             }
        
        case '2' :
             {
                 system("cls");
                 int idr, idd;
                 idd = dane.GetSize();
                 
                 if(idd == 0)
                 {
                        cout << "===================================================" << endl << endl;
                        cout << "W bazie nie ma zadnych rekordow !" << endl << endl;
                        cout << "==================================================";
                        getch();
                        goto DEFAULT;
                 }
                 else
                 {
                        cout << "===================================================" << endl;
                        cout << "Podaj numer rekordu do usuniecia: [1-" << idd << "]: ";
                        cin >> idr;
                 
                        dane.DelRecord(idr);
                        goto DEFAULT;
                 }
             }
             
        case '3' :
             {
                  system("cls");
                  dane.List();
                  goto DEFAULT;
             }
        
        case '4' :
             {
                  system("cls");
                  dane.ListSort();
                  goto DEFAULT;
             }
             
        case '5' :
             {
                 int cr;
                 string tcr, scr;
                 
                 ERROR:
                 system("cls");
                 cout << "===================================================" << endl;
                 cout << "Kryteria wyszukiwania:" << endl;
                 cout << "===================================================" << endl;
                 cout << "  1. Nazwisko" << endl;
                 cout << "  2. Imie" << endl;
                 cout << "  3. Miasto" << endl;
                 cout << "  4. Ulica" << endl;
                 cout << "  5. Numer telefonu" << endl;
                 cout << endl << "Twoj wybor: ";
                 cin >> cr;
                 
                 if(cr >= 1 && cr <= 5)
                 {
                 }
                 else
                 {
                     goto ERROR;
                 }
                 
                 if(cr == 1) { tcr = "nazwisko"; }
                 if(cr == 2) { tcr = "imie"; }
                 if(cr == 3) { tcr = "miasto"; }
                 if(cr == 4) { tcr = "nazwe ulicy"; }
                 if(cr == 5) { tcr = "numer telefonu"; }
                 
                 cout << "Podaj " << tcr << ": ";
                 cin >> scr;
                 
                 dane.Search(cr, scr);
                 goto DEFAULT;
             }
             
        case '6' :
             {
                 SaveData();
                 return 0;
             }
             
        default :
             {
                 goto DEFAULT;
             }
    }
}

void SaveData()
{
     fstream dsave;
     dsave.open("data.bdf", ios::out);
     dsave << dane.nameDatabase << endl;
     
     for(int i=0;i<MAX;i++)
     {
         if(dane.ID[i] != 0)
         {
             dsave << dane.name[i] << " " << dane.surname[i] << " " << dane.city[i] << " " << dane.address[i] << " "
                   << dane.pNumber[i] << " " << dane.ID[i] << endl;
         }
     }
     
     dsave.close();
}

void LoadData()
{
    dane.Initialize();
    dane.nameDatabase = "";
    
    fstream dload;
    dload.open("data.bdf", ios::in);
    dload >> dane.nameDatabase;
    
    for(int i=0;i<MAX;i++)
    {
        dload >> dane.name[i] >> dane.surname[i] >> dane.city[i] >> dane.address[i] >> dane.pNumber[i] >> dane.ID[i];
    }
    
    dload.close();
}
