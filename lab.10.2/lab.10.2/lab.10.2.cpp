#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); 
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); 
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname) 
{
	ifstream fin(fname); 
	string s;
	while (getline(fin, s)) 
	{
		cout << s << endl;
	}
	cout << endl;
}

int ProcessTXT(char* fname) // обчислення кількості слів, відокремлених пробілами
{
	ifstream fin(fname); 
	string s; 
	int k = 0; 

		while (fin >> s) 
		{
			k++; 
			cout << k << ": " << s << endl;
		}
	return k;
}

int main()
{
	char fname[] = "t1.txt";

	/*char fname[100];*/ 
	/*cout << "enter file name: "; cin >> fname;*/
	CreateTXT(fname); 
	PrintTXT(fname); 
	cout << "k(word) = " << ProcessTXT(fname) << endl;
	
	return 0;
}