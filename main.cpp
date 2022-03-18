#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu();
void ExecuteMenu(char, ShoppingCart&);

int main() {

    ItemToPurchase item1;
    ItemToPurchase item2;
    ShoppingCart Cart;
    string name;
    string date;
    string trash;
    char userInput = 'y';
    int quant;
    int price;
    int item1sum;
    int item2sum;
    int total;
    
    cout << "Enter customer's name:" << endl;
    getline(cin, name);
    getline(cin, trash);
    cout << "Enter today's date:" << endl;
    getline(cin, date);
    getline(cin, trash);
    
    Cart.SetNameAndDate(name, date);

    while (userInput != 'q')
    {
        PrintMenu();
        cin >> userInput;

    }
    
    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item1.SetName(name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    item1.SetPrice(price);
    cout << "Enter the item quantity" << endl;
    cin >> quant;
    item1.SetQuantity(quant);

    getline(cin, trash);

    cout << "Item 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item2.SetName(name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    item2.SetPrice(price);
    cout << "Enter the item quantity:" << endl;
    cin >> quant;
    item2.SetQuantity(quant);

    item1sum = item1.GetPrice() * item1.GetQuantity();
    item2sum = item2.GetPrice() * item2.GetQuantity();
    total = item1sum + item2sum;

    cout << "TOTAL COST" << endl;
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1sum << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2sum << endl;
    cout << endl;
    cout << "Total: " << total << endl;


    Cart.Test();


        


        return 0;
    }

void PrintMenu()
{
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char input, ShoppingCart& cart)
{
    ItemToPurchase item;
    string name;
    string description;
    string trash;
    int price;
    int quant;

    if (input == 'q')
    {
        exit(1);
    }
    else if (input == 'a')
    {
        cout << "Item 1" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, name);
        item.SetName(name);
        cout << "Enter the item price:" << endl;
        cin >> price;
        item.SetPrice(price);
        cout << "Enter the item quantity" << endl;
        cin >> quant;
        item.SetQuantity(quant);
    }
    else if (input == 'd')
    {
        cout << "What is the item you would like to remove" << endl;
        getline(cin, name);
        getline(cin, trash);
        cart.RemoveItem(name);
    }
    else if (input == 'c')
    {
        cout << "What would you like to change the quantity to" << endl;
        cin >> quant;
        
    }
}
