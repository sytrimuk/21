#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <locale>
#include <windows.h>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
setlocale(LC_ALL, "Russian");
SetConsoleOutputCP(1251);
SetConsoleCP(1251);

	srand(time(NULL));

	vector<int> win;
	vector<int> loss;
	
	long x = rand();
	srand(x);
	short c1 = rand() % 9 + 2;

	long y = rand();
	srand(y);
	short c2 = rand() % 9 + 2;

	short scD;
	scD = c1 + c2;

	if(2 <= scD && 21 >= scD){
		win.push_back(scD);
		loss.push_back(0);
	}
	else{
		loss.push_back(scD);
		win.push_back(0);
	}

	x = rand();
	srand(x);
	c1 = rand() % 9 + 2;

	y = rand();
	srand(y);
	c2 = rand() % 9 + 2;

	short scB;
	scB = c1 + c2;

	while (true){
		if (scB <= 16 && scB >= 2){
			long c = rand();
			srand(c);
			short c3 = rand() % 9 + 2;

			scB = scB + c3;
		}

		else if (scB <= 21){
			break;
		}

		else{
			break;
		}
	}

	if(2 <= scB && 21 >= scB){
		win.push_back(scB);
		loss.push_back(0);
	}
	else{
		loss.push_back(scB);
		win.push_back(0);
	}

	x = rand();
	srand(x);
	c1 = rand() % 9 + 2;

	y = rand();
	srand(y);
	c2 = rand() % 9 + 2;

	short scH;
	scH = c1 + c2;

	cout << "Ваши карты " << scH << endl << endl;

	bool zapros;
	cout << "Если хотите взять ещё карты напишите 1\nЕсли нет 0\nОбязательно(Может вылететь)\n" << endl;

	while (true){
		cout << "Ваш выбор: ";
		cin >> zapros;
		cout << endl;
		if (zapros == 1){
			long c = rand();
			srand(c);
			short c3 = rand() % 9 + 2;
			cout << "Вам выпало " << c3 << endl;
			scH = scH + c3;
		}
		else if (zapros == 0){break;}
		else{break;}
		cout << "Ваши карты " << scH << endl << endl;
	}

	if(2 <= scH && 21 >= scH){
		win.push_back(scH);
		loss.push_back(0);
	}
	else{
		loss.push_back(scH);
		win.push_back(0);
	}

	sort(win.begin(), win.end());

	if(scD <= 21 && scB <= 21 && scH <= 21){
		if (scD == win[2]){
			cout << "Выиграл Дила\nС таким количеством очков: "<< scD << endl;
			cout << "Это очки Бота " << scB << endl;
			cout << "Это очки Человека " << scH << endl;
		}
		else if (scB == win[2]){
			cout << "Выиграл Бот\nС таким количеством очков: "<< scB << endl;
			cout << "Это очки Дилы " << scD << endl;
			cout << "Это очки Человека " << scH << endl;
		}
		else if(scH == win[2]){
			cout << "Выиграл Человек\nС таким количеством очков: "<< scH << endl;
			cout << "Это очки Дилы " << scD << endl;
			cout << "Это очки бота " << scB << endl;
		}
		else{cout << "ЧО?";}
	}

	else{
		if (win[2] != 0){
			if (win[2] == scD){
				cout << "Выиграл Дила\nС таким количеством очков: "<< scD << endl;
				cout << "Это очки Бота " << scB << endl;
				cout << "Это очки Человека " << scH << endl;
			}

			else if (win[2] == scB){
				cout << "Выиграл Бот\nС таким количеством очков: "<< scB << endl;
				cout << "Это очки Дилы " << scD << endl;
				cout << "Это очки Человека " << scH << endl;
			}

			else if (win[2] == scH){
				cout << "Выиграл Человек\nС таким количеством очков: "<< scH << endl;
				cout << "Это очки Дилы " << scD << endl;
				cout << "Это очки бота " << scB << endl;
			}

			else if (win[1] == scD){
				cout << "Выиграл Дила\nС таким количеством очков: "<< scD << endl;
				cout << "Это очки Бота " << scB << endl;
				cout << "Это очки Человека " << scH << endl;
			}

			else if (win[1] == scB){
				cout << "Выиграл Бот\nС таким количеством очков: "<< scB << endl;
				cout << "Это очки Дилы " << scD << endl;
				cout << "Это очки Человека " << scH << endl;
			}

			else if (win[1] == scH){
				cout << "Выиграл Человек\nС таким количеством очков: "<< scH << endl;
				cout << "Это очки Дилы " << scD << endl;
				cout << "Это очки бота " << scB << endl;
			}
		}
		else if(loss[2] != 0 && loss[1] != 0 && loss[0] != 0){cout << "Победителей нет" << endl; cout << "Это очки Дилы " << scD << endl; cout << "Это очки бота " << scB << endl; cout << "Это очки Человека " << scH << endl;}
	}
	system("PAUSE");
	return 0;
}