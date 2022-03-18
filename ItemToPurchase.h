#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

class ItemToPurchase
{
public:
	ItemToPurchase() { itemName = ""; itemPrice = 0; itemQuant = 0; };
	void SetName(string name) { itemName = name; }
	string GetName() { return itemName; }
	void SetPrice(int price) { itemPrice = price; }
	int GetPrice() { return itemPrice; }
	void SetQuantity(int quant) { itemQuant = quant; }
	int GetQuantity() { return itemQuant; }
	void SetDescription(string desc) { itemDescription = desc; }
	string GetDescription() { return itemDescription; }
	void PrintItemCost() { cout << itemName << " " << itemQuant << " " << itemPrice << " " << itemSubtotal << endl; }
	void PrintItemDescription() { cout << itemName << " " << itemDescription << endl; }
private:
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuant;
	int itemSubtotal;
	
};


