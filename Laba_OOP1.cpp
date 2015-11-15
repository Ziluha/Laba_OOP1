// Laba_OOP1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

#define NULL 0
#define DAYNUMB 31
#define MONTHNUMB 12
#define DAYNUMBFEBR 28
#define DAYNUMB2 30
#define ONE 1
#define FEBRUARY 2

class Date
{

	int day[DAYNUMB];
	int month[MONTHNUMB];
	int year;
	string monthName[MONTHNUMB];

public:
	Date::Date(){
		cout << "Вызов конструктора по умолчанию" << endl;
	}

	
	void Date::setDate(int DAY[], int MONTH[], int YEAR){

		for (int i = NULL; i < MONTHNUMB; i++)
		{
			month[i] = MONTH[i];
			if (month[i]<NULL || month[i]>MONTHNUMB)
			{
				cout << "Неверная дата" << endl;
				break;
			}
		}
		for (int i = NULL; i < DAYNUMB; i++)
		{
			day[i] = DAY[i];
			if (day[i]<NULL || day[i]>DAYNUMB)
			{
				cout << "Неверная дата" << endl;
				break;
			}
		}
		year = YEAR;
	}

	void Date::setMonthName(string MONTHNAME[]){
		for (int i = NULL; i < MONTHNUMB; i++)
			monthName[i] = MONTHNAME[i];
	}
	Date::~Date(){
		cout << "Вызов деструктора" << endl;
	}

	int* Date::getDay(void){
	return day;
	}
	int* Date::getMonth(void){
	return month;
	}
	string* Date::getMonthName(void){
	return monthName;
	}
	int Date::getYear(void){
	return year;
	}

	void Date::printDate(int i){
		for (int k = NULL; k < i; k++)
		{
			{
				if (month[k] == 1 || month[k] == 3 || month[k] == 5 || month[k] == 7 || month[k] == 8 || month[k] == 10 || month[k] == 12)
				for (int j = NULL; j < DAYNUMB; j++)
					cout << day[j] << "/" << month[k] << "/" << year << endl;
				else if (month[k] == FEBRUARY)
				for (int j = NULL; j < DAYNUMBFEBR; j++)
					cout << day[j] << "/" << month[k] << "/" << year << endl;
				else
				for (int j = NULL; j < DAYNUMB2; j++)
					cout << day[j] << "/" << month[k] << "/" << year << endl;
			}
			cout << endl;
		}
	}

	void Date::printDate2(int i){
		for (int k = NULL; k < i; k++)
		{
			{
				if (month[k] == 1 || month[k] == 3 || month[k] == 5 || month[k] == 7 || month[k] == 8 || month[k] == 10 || month[k] == 12)
				for (int j = NULL; j < DAYNUMB; j++)
					cout << day[j] << " " << monthName[k] << " " << year << endl;
				else if (month[k] == FEBRUARY)
				for (int j = NULL; j < DAYNUMBFEBR; j++)
					cout << day[j] << " " << monthName[k] << " " << year << endl;
				else
				for (int j = NULL; j < DAYNUMB2; j++)
					cout << day[j] << " " << monthName[k] << " " << year << endl;
			}
			cout << endl;
		}
	}

	void Date::printConkrDate(int NDAY, int NMONTH){
		for (int i = NULL; i < MONTHNUMB; i++)
			for (int j = NULL; i < DAYNUMB; i++)
				if (month[i] == NMONTH && day[j] == NDAY)
					cout << day[j] << "/" << month[i] << "/" << year << endl;
	}
	
};



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	Date d1, d2, d3;
	
	int days[DAYNUMB];
	int months[MONTHNUMB];
	int years = 2015;
	string monthsNames[MONTHNUMB] = { "января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря" };
	
	for (int i = NULL; i < DAYNUMB; i++)
	{
		days[i] = i + 1;
	}
	for (int i = NULL; i < MONTHNUMB; i++)
	{
		months[i] = i + 1;
	}
	d1.setDate(days, months, years);
	d1.setMonthName(monthsNames);

	int* d = d1.getDay();
	int* m = d1.getMonth();
	string* mn = d1.getMonthName();
	int y = d1.getYear();
	//d1.printDate2(2);
	
	int number = 28;
	int numberMonth = 9;
	int numbTomorrow = 29;
	
	d2.setDate(&number, &numberMonth, years);
	
	d2.setDate(&numbTomorrow, &numberMonth, years);
	
	d2.printConkrDate(*(d2.getDay()), numberMonth);


	system("pause");
	return 0;
}