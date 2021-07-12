#pragma once
#ifndef _COMMODITY_H_
#define _COMMODITY_H_

#include <iostream>
using std::string;
using std::cout;

class Commodity {
public:
	string name;
	int id;
	double price;
	int num;
	string features;
public:
	Commodity(string n, int i, double p, int nu, string f = "") :
	name(n), id(i), price(p), num(nu), features(f) {}

	string getName() { return name; }
	double getPrice() { return price; }
	void setPrice(double p) { price = p; }
	int getNum() { return num; }
	void setNum(int n) { num = n; }
	string getFeatures() { return features; }
	void setFeatures(string f) { features = f; }
	
	virtual void printInfo() = 0;
};

#endif //_COMMODITY_H_