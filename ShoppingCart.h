#pragma once
#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart
{
public:
	ShoppingCart() { customerName = "none"; currentDate = "January 1, 2016"; }
	void SetNameAndDate(string name, string date) { customerName = name; currentDate = date;}
	string GetName() { return customerName; }
	string GetDate() { return currentDate; }
	void AddItem(ItemToPurchase item) { cartItems.push_back(item); }
	void RemoveItem(string itemName);
	void ModifyItem(string itemName);
	int Search(vector<ItemToPurchase> items, ItemToPurchase itemName);
	int Search(vector<ItemToPurchase> items, string itemName);
	int GetNumItemsInCart();
	int CostOfCart();
	void PrintTotal();
	void PrintDescriptions();
	void Test();
	

private:
	string customerName;
	string currentDate;
	vector<ItemToPurchase> cartItems;
	int found;
};

void ShoppingCart::RemoveItem(string itemName)
{
	found = Search(cartItems, itemName);
	if (found == -1)
	{
		cout << "Item not found in cart. Nothing removed." << endl;
	}
	else
	{
		cartItems.erase(remove(cartItems.begin(), cartItems.end(), found), cartItems.end());
	}
}

void ShoppingCart::ModifyItem(string itemName)
{
	int newquant;
	found = Search(cartItems, itemName);
	if (found == -1)
	{
		cout << "Item not found in cart. Nothing removed." << endl;
	}
	else
	{
		cout << "What would you like to change the quantity to: " << endl;
		cin >> newquant;
	}
}

int ShoppingCart::Search(vector<ItemToPurchase> items, ItemToPurchase itemName)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (itemName.GetName() == items[i].GetName())
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

int ShoppingCart::Search(vector<ItemToPurchase> items, string itemName)
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (itemName == items[i].GetName())
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

void ShoppingCart::Test()
{
	cout << cartItems.size() << endl;
}

int ShoppingCart::GetNumItemsInCart()
{
	unsigned int size = cartItems.size();
	int numItems = 0;
	for (unsigned int i = 0; i < size; ++i)
	{
		numItems += cartItems[i].GetQuantity();
	}
	return numItems;
}

int ShoppingCart::CostOfCart()
{
	unsigned int size = cartItems.size();
	int cost = 0;
	for (unsigned int i = 0; i < size; ++i)
	{
		cost += cartItems[i].GetPrice();
	}
	return cost;
}

void ShoppingCart::PrintTotal()
{
	int cartTotal = 0;
	unsigned int size = cartItems.size();
	for (unsigned int i = 0; i < size; ++i)
	{
		cartTotal += (cartItems[i].GetPrice() * cartItems[i].GetQuantity());
	}
	cout << "Your carts total is: " << cartTotal;
}

void ShoppingCart::PrintDescriptions()
{
	unsigned int size = cartItems.size();
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << cartItems[i].GetName() << " : " << cartItems[i].GetDescription();
	}
}
