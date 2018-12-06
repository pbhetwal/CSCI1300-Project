#include <iostream>
#include "Restaurant.h"

using namespace std;

int main()
{
    Menu T;
    //Menu(); ~Can be used to initialize data members to empty strings and 'written' to false
    T.Set_location("Erie, Colorado 80516"); //Sets location of where the store si
    string answer; //Used to know if user wants to know where the restaurant is located
    cout << "        Would you like to know where our restaurant is located? (y/n) ";
    cin >> answer;
    if (answer == "y") //If they say yes
    {
        cout << "                               " << T.Get_location() << endl; //Show them the location
    }
    T.FirstCustomer("Customers.txt");
    //T.Get_written(); ~Can be checked to see if the first customer was successfully written to the file of customers
    //T.Get_first_customer(); ~Can be used to see who the first customer was
    //T.AskName("Customers.txt"); ~This method can be used after we already have the first customer, which will then append to the customers file
    T.showMenu();
    T.loadPizzaMenu("Pizzas.txt"); //Load the pizzas we have from a file
    T.loadDrinkMenu("Drinks.txt"); //Load the drinks we have from a file

    Worker A;
    string request;
    string A1 = "Sarah"; //Name of the first waitress
    string B = "Michelle"; //Name of the second waitress
    Worker w[2]; //An array of objects using the class Worker
    w[0].setwaiterName(A1); //Set the first waitress' name
    w[1].setwaiterName(B); //Set the second waitress' name
    A.loadDrinkCosts("Drinks.txt"); //Load from a file and use the file to populate our drinkCosts array
    A.loadPizzaCosts("Pizzas.txt"); //Load from a file and use the file to populate our pizzaCosts array
    A.Set_tax(0.08); //Here, the tax can be set to any value that we'd like
    string ask; //Used to ask the user who they want as their waitress
    cout << endl;
    cout << "              Who do you want as your waitress? Michelle or Sarah? ";
    cin >> ask;
    //If Michelle
    if (ask == "Michelle")
        cout << "              Hi! My name is " << w[1].getwaiterName() << " and I'll take your order today.";
    //If Sarah
    if (ask == "Sarah")
        cout << "              Hi! My name is " << w[0].getwaiterName() << " and I'll take your order today.";
    A.getOrder(); //Get what they'd like to order
    //Ask them if they want our menu in the form of a list
    cout << "              Would you like a list of our pizzas and drinks? (y/n) ";
    cin >> request;
    if (request == "y")
    {
        T.getPizzas(); //Outputs pizzas we have as a list
        T.getDrinks(); //Outputs pizzas we have as a list
    }
    //A.Get_tax(); ~Can be used to see what the tax value is
    return 0;
}
