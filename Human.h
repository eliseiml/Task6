#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Класс первого уровня - Человек
class Human
{
protected:
	int age;
	string name;
	string sex;

public:
	Human(int a, string n, string s) {
		age = a;
		name = n;
		sex = s;
	}
	virtual void setAge(int a) = 0;
	virtual void setName(string n) = 0;
	virtual void setSex(string s) = 0;
	virtual void printInfo() = 0;
};

//Классы второго уровня
//Взрослый
class Adult :public Human {
protected:
	string occupation;

public:
	Adult(int a, string n, string s, string o) : Human(a, n, s){
		occupation = o;
	}
	void setAge(int a) override { age = a; }
	void setName(string n) override { name = n; }
	void setSex(string s) override { sex = s; }
	virtual void setOccupation(string o) = 0;
	virtual void getAverageIncome() = 0;
	void printInfo() override {
		cout << "Имя: " << name << ", возраст: " << age << ", пол: " << sex << ", род детельности: " << occupation << endl;
	}
};

//Ребенок
class Child :public Human {
protected:
	int numOfSocieties;

public:
	Child(int a, string n, string s, int nos) : Human(a, n, s) {
		numOfSocieties = nos;
	}
	virtual void setAge(int a) override { age = a; }
	virtual void setName(string n) override { name = n; }
	virtual void setSex(string s) override { sex = s; }
	virtual void getSumPrice() = 0;
	virtual void printInfo() {
		cout << "Имя: " << name << ", возраст: " << age << ", пол: " << sex << ", количество секций(кружков): " << numOfSocieties << endl;
	}
};

//Конкретные классы 

//Работающий
class Worker :public Adult {

public:
	Worker(int a, string n, string s, string o) : Adult(a, n, s, o) {}

	void setOccupation(string o) override {
		occupation = o;
	}
	void getAverageIncome() override {
		int a = rand() % 500;
		cout << "Средний доход (зарплата) " << name << " составляет " << a << " долларов" << endl;
	}
};

//Пенсионер
class Retiree :public Adult {
public:
	Retiree(int a, string n, string s, string o) : Adult(a, n, s, o) {}

	void setOccupation(string o) override {
		occupation = o;
	}
	void getAverageIncome() {
		int a = rand() % 250;
		cout << "Средний доход (пенсия) " << name << " составляет " << a << " долларов" << endl;
	}
};

//Дошкольник
class Preschooler :public Child {
public:
	Preschooler(int a, string n, string s, int nos) : Child(a,n,s,nos){}
	void getSumPrice() override {
		int a = rand() % 30;
		cout << "Средняя стоимость секции у " << name << " - " << a << " долларов" << endl;
		cout << "Он(а) посещает " << numOfSocieties << " секций. Суммарная стоимость: " << a * numOfSocieties << " долларов" << endl;
	}
};

//Учащийся
class Schoolchild :public Child {
public:
	Schoolchild(int a, string n, string s, int nos): Child(a,n,s,nos){}

	void getSumPrice() override {
		int a = rand() % 15;
		cout << "Средняя стоимость секции у " << name << " - " << a << " долларов" << endl;
		cout << "Он(а) посещает " << numOfSocieties << " секций. Суммарная стоимость: " << a * numOfSocieties << " долларов" << endl;
	}
};
