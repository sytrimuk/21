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
#include <string.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
setlocale(LC_ALL, "Russian");
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
system("color 70" );

	vector<int> win;
	int WscD = 0;
	int WscB = 0;
	int WscH = 0;

	vector<int> loss;
	int LscD = 0;
	int LscB = 0;
	int LscH = 0;

	bool vibor;
	string zapros;

    int kon = 0;

	while (true){
		win.clear();
		loss.clear();

		cout << endl;
		cout << "Если хотите сделать ещё один кон, то напишите go\nЕсли хотите вывести статистику всех игроков, то напишите stat\nЕсли хотите завершить игру, то напишите exit\n";
		cin >> zapros;
		if (zapros == "go"){
            system("cls");
			cout << "=====================================================================================================" << endl;
			srand(time(NULL));
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

			cout << "Если хотите взять ещё карты напишите 1\nЕсли нет 0\nОбязательно(Может вылететь)\n" << endl;

			srand(time(NULL));
			x = rand();
			srand(x);
			y = rand();
			srand(y);
			while (true){
				cout << "Ваш выбор: ";
				cin >> vibor;
				cout << endl;
				if (vibor == 1){

					long c = rand();
					srand(c);
					short c3 = rand() % 9 + 2;
					cout << "Вам выпало " << c3 << endl;
					scH = scH + c3;
				}

				else if (vibor == 0){break;}
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
				if (win[2] == win[1]) {
					if (win[2] == win[1] && win[1] == win[0]){
						cout << "У всех ничья" << endl;
					}
					else if (win[2] == scD && win[2] == scB){
						cout << "У Крупье и Бота ничья" << endl;
						LscH++;
					}
					else if(win[2] == scD && win[2] == scH){
						cout << "У Крупье и Человека ничья" << endl;
						LscB++;
					}
					else if(win[2] == scB && win[2] == scH){
						cout << "У Бота и Человека ничья" << endl;
						LscD++;
					}
				}

				else if (scD == win[2]){
					cout << "Выиграл Крупье\nС таким количеством очков: "<< scD << endl;
					cout << "Это очки Бота " << scB << endl;
					cout << "Это очки Человека " << scH << endl;

					WscD++;
					LscB++; LscH++;
				}
				else if (scB == win[2]){
					cout << "Выиграл Бот\nС таким количеством очков: "<< scB << endl;
					cout << "Это очки Дилы " << scD << endl;
					cout << "Это очки Человека " << scH << endl;

					WscB++;
					LscD++; LscH++;
				}
				else if(scH == win[2]){
					cout << "Выиграл Человек\nС таким количеством очков: "<< scH << endl;
					cout << "Это очки Дилы " << scD << endl;
					cout << "Это очки бота " << scB << endl;

					WscH++;
					LscD++; LscB++;
				}
				else{cout << "ЧО?";}
			}


			else{
				if (win[2] != 0){

					if (win[2] == win[1] && win[1] == win[0]){
						cout << "У всех ничья" << endl;
					}
					else if (win[2] == win[1]){
						if (win[2] == scD && win[2] == scB){
							cout << "У Крупье и Бота ничья" << endl;
							LscH++;
						}
						else if(win[2] == scD && win[2] == scH){
							cout << "У Крупье и Человека ничья" << endl;
							LscB++;
						}
						else if(win[2] == scB && win[2] == scH){
							cout << "У Бота и Человека ничья" << endl;
							LscD++;
						}
					}

					else if (win[2] == scD){
						cout << "Выиграл Крупье\nС таким количеством очков: "<< scD << endl;
						cout << "Это очки Бота " << scB << endl;
						cout << "Это очки Человека " << scH << endl;

						WscD++;
						LscB++; LscH++;
					}

					else if (win[2] == scB){
						cout << "Выиграл Бот\nС таким количеством очков: "<< scB << endl;
						cout << "Это очки Дилы " << scD << endl;
						cout << "Это очки Человека " << scH << endl;

						WscB++;
						LscD++; LscH++;
					}

					else if (win[2] == scH){
						cout << "Выиграл Человек\nС таким количеством очков: "<< scH << endl;
						cout << "Это очки Дилы " << scD << endl;
						cout << "Это очки бота " << scB << endl;

						WscH++;
						LscD++; LscB++;
					}

					else if (win[1] == scD){
						cout << "Выиграл Крупье\nС таким количеством очков: "<< scD << endl;
						cout << "Это очки Бота " << scB << endl;
						cout << "Это очки Человека " << scH << endl;

						WscD++;
						LscB++; LscH++;
					}

					else if (win[1] == scB){
						cout << "Выиграл Бот\nС таким количеством очков: "<< scB << endl;
						cout << "Это очки Дилы " << scD << endl;
						cout << "Это очки Человека " << scH << endl;

						WscB++;
						LscD++; LscH++;
					}

					else if (win[1] == scH){
						cout << "Выиграл Человек\nС таким количеством очков: "<< scH << endl;
						cout << "Это очки Дилы " << scD << endl;
						cout << "Это очки бота " << scB << endl;

						WscH++;
						LscD++; LscB++;
					}
				}

				else if(loss[2] != 0 && loss[1] != 0 && loss[0] != 0){cout << "Победителей нет" << endl; cout << "Это очки Крупье " << scD << endl; cout << "Это очки бота " << scB << endl; cout << "Это очки Человека " << scH << endl; LscD++; LscB++; LscH++;}
			}
			cout << "=====================================================================================================" << endl;

			kon++;
		}

		else if (zapros == "stat"){
			system("cls");
			cout << "=====================================================================================================" << endl;
			cout << "win" << endl << "Побед у Крупье: " << WscD << endl << "Побед у Бота: " << WscB << endl << "Побед у Человека: " << WscH << endl;
            cout << endl;
			cout << "loss" << endl << "Проигрышей у Крупье: " << LscD << endl << "Проигрышей у Бота: " << LscB << endl  << "Проигрышей у Человека: " << LscH << endl;
			cout << "=====================================================================================================" << endl;
		}

		else if(zapros == "exit"){system("cls"); cout << "=====================================================================================================" << endl; break;}
		else if(zapros == "kon"){system("cls"); cout << "Вы играли " << kon << " раундов(-ов)" << endl;}
	}

	cout << "win" << endl << "Побед у Крупье: " << WscD << endl << "Побед у Бота: " << WscB << endl << "Побед у Человека: " << WscH << endl;
	cout << endl;
	cout << "loss" << endl << "Проигрышей у Крупье: " << LscD << endl << "Проигрышей у Бота: " << LscB << endl  << "Проигрышей у Человека: " << LscH << endl;

	system("PAUSE");
	return 0;
}
