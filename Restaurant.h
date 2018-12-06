///Pari Bhetwal
///Ta: Nicholas Farrow
///Recitation 112
///C++ Project
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

    class Menu
    {
        public:
            //More than 4 methods
            //This constructor just initializes our data members
            Menu()
            {
                //Blank customer name
                first_customer = "";
                written = false;
                //Blank location
                location = "";
                //Initialize arrays with blanks
                for (int j = 0; j < 9; j++)
                {
                    pizzas[j] = "";
                }

                for (int k = 0; k < 9; k++)
                {
                     drinks[k] = "";
                }
            }
            //This method outputs the menu to the user
            void showMenu() //Shows the user the menu
            {
                cout << "                           Welcome to Pari's Pizzeria!" << endl;
                cout << "                           Please, look over our menu." << endl;
                cout << "                                     Pizzas" << endl;
                cout << "           Small Pepperoni Pizza $5.50    Medium Pepperoni Pizza $7.79" << endl;
                cout << "           Large Pepperoni Pizza $10.00       Small Cheese Pizza $5.00" << endl;
                cout << "           Medium Cheese Pizza $7.30          Large Cheese Pizza $9.40" << endl;
                cout << "           Small Vegetable Pizza $4.89    Medium Vegetable Pizza $7.00" << endl;
                cout << "           Large Vegetable Pizza $9.20" << endl;
                cout << "                                     Drinks" << endl;
                cout << "     Small Soda $1.50          Medium Soda $2.00           Large Soda $2.50" << endl;
                cout << "     Small Lemonade $2.00     Medium Lemonade $2.50    Large Lemonade $3.00" << endl;
                cout << "     Small Water $1.00         Medium Water $1.20         Large Water $1.40" << endl;
            }

            bool AskName(string outFile) //Asks for name, and then appends to the customers file, this is used if not the first customer
            {
                string name;
                cout << "                   Good evening, may I please have your name?" << endl;
                cout << "                                        ";
                cin >> name;
                cout << "          Pleased to have you " << name << "! The waitress will be with you shortly" << endl;
                ofstream write; //Allows me to write to a file
                write.open(outFile, ios::app); //We will be appending, meaning not replacing words within the file
                if (write.is_open()) //If the file we're going to write to is open
                {
                    write << "Customer: " << name << endl;  //Write the name of the customer to the file
                    return true; //If I was able to open such file
                }
                else return false; //If I could not open such file, then return false
            }
            void FirstCustomer(string outFile) //Writes the first customer's name to a file saying he/she was the first customer
            {
                string first;
                cout << "                You're the first customer ever! What's your name!?" << endl;
                cout << "                                      ";
                cin  >> first;
                first_customer = first; //Save that name, since someone might want it later
                cout << "          Pleased to have you " << first << "! The waitress will be with you shortly" << endl;
                ofstream write; //Used to write to said file
                write.open(outFile);
                string line;
                if (write.is_open()) //If it's open
                {
                    write << "First Customer: " << first << endl;
                    written = true;
                }
            }

            bool Get_written() //We can see if we were able to the write the first customer to the customers file
            {
                return written;
            }

            //Can return first customers name
            string Get_first_customer()
            {
                return first_customer;
            }

            bool loadPizzaMenu(string filename) //Actually load the pizza menu from a file to store in an array
            {
                ifstream get;
                get.open(filename); //Opens passed filename
                string line;
                if (get.is_open()) //Only if opening of said file is successful
                {
                    int j = 0;
                    while(getline(get,line)) //While I'm able to get a line from said file
                    {
                        string pizza; //The string I want from the line
                        istringstream cc(line); //Stream from the line so that I may store it
                        getline(cc, pizza, ','); //Get the string before the comma
                        pizzas[j] = pizza; //Store that into the array
                        j++; //Index
                    }
                get.close();
                return true;
                }
                else return false;
            }

            bool loadDrinkMenu(string filename) //Actually load the drink menu from a file to store in an array
            {
                ifstream get;
                get.open(filename);
                string line;
                if (get.is_open())
                {
                    int j = 0;
                    while (getline(get,line))
                    {
                        string drink;
                        istringstream cc(line);
                        getline(cc,drink,',');
                        drinks[j] = drink;
                        j++;
                    }
                 get.close();
                 return true;
                }
                else return false;
            }

            void Set_location (string L) //Sets the location of the store
            {
                location = L;
            }

            string Get_location() //Returns the location of the store
            {
                return location;
            }

            void getPizzas() //If anyone wants to see the array of pizzas
            {
                for (int i = 0; i < 9; i++)
                {
                    cout << "              " << pizzas[i] << endl;
                }
            }

            void getDrinks() //If anyone wants to see the array of drinks
            {
                for (int i = 0; i < 9; i++)
                {
                    cout << "              " << drinks[i] << endl;
                }
            }

        private:
            //More than 4 data members
            string first_customer; //First customer we ever got
            bool written; //If we're able to write the first customer we ever got to a file
            string location; //The location of the shop
            string pizzas[9]; //Array for the pizzas we have (without price)
            string drinks[9];  //Array for the drinks we have (without price)
    };

    class Worker
    {
        public:
            //More than 4 methods

            //Used to initialize
            Worker()
            {
                waiterName = "";
                tip = -1.0;
                tax = -1.0;
                for (int i = 0; i < 9; i++)
                {
                    pizzaCosts[i] = -1.0;
                    drinkCosts[i] = -1.0;
                }
            }

            bool loadPizzaCosts(string filename) //Reads from a file and only loads the prices into an array
            {

                ifstream get;
                get.open(filename); //Opens passed filename
                string line;
                if (get.is_open()) //Only if opening of said file is successful
                {
                    int j = 0;
                    while(getline(get,line)) //While I'm able to get a line from said file
                    {
                        string IDC; //I won't care about this
                        string IC; //This is the thing I want, the price of each menu item
                        istringstream cc(line); //This will allow us to stream from the line and thus store as a variable
                        getline(cc, IDC, ','); //Get the thing I don't want
                        getline(cc, IC); //The thing right after the comma is the thing I want
                        pizzaCosts[j] = stof(IC); //Convert from string to float value and store into pizzaCosts array
                        j++; //Index, so each position within the array has a different value
                    }
                get.close(); //Close the file
                return true; //Return true if I'm able to open said file
                }
                else return false; //If I can't, then return false
            }

            bool loadDrinkCosts (string filename) //Reads from a file and only loads the prices into an array
            {
                ifstream get; //Allows us to stream in from a file
                get.open(filename); //Opens passed filename
                string line; //Used to get each line from the file as a string
                if (get.is_open()) //Only if opening of said file is successful
                {
                    int j = 0; //Used to index through array
                    while(getline(get,line)) //While I'm able to get a line from said file
                    {
                        string IDC; //Don't care about this string
                        string IC; //The string I'll convert into a float
                        istringstream cc(line); //SO, stream from the line so that I can store it as a variable
                        getline(cc, IDC, ','); //Get the first thing on the line before the comma, but I won't do anything with it
                        getline(cc, IC); //Get the string I want
                        drinkCosts[j] = stof(IC); //Convert this string to a float and store it into the drinkCosts array
                        j++; //Index so that each value within the drinkCosts
                    }
                get.close(); //Close the file
                return true; //Return true if I was able to open said file
                }
                else return false; //If not, then return false
            }

            bool writeCheck(float total)//Writes the total amount of money the user spent to a file
            {
                ofstream write; //I will be using this to write to the receipt file
                write.open("Receipt.txt", ios::app); //I will be appending
                if (total > 0) //Only if the total is greater than 0
                {
                    if (write.is_open())
                    {
                    write << "ORDER TOTAL: " << "$" << total << endl;
                    return true;
                    }

                }
                return false; //Returns false if there's no total since the user did not order anything or if we could not open the file
            }

            bool getOrder() //Gets the order from the user regarding what they'd like (user input), and tells them their total with tax and tip
            {
                string pizza;
                int quantity;
                float pizzacost;
                float total = 0;
                string answer;
                string drink;
                cout << endl;
                cout << "              Would you like to get a pizza? (y/n) ";
                cin >> answer;
                if (answer == "y")
                {
                    cout << "              Which kind? (i.e. SP = Small Pepperoni) ";
                    cin >> pizza;
                        //Costs are dependent on what kind of pizza and the size
                        if (pizza == "SP")
                            pizzacost = pizzaCosts[0];
                        if (pizza == "MP")
                            pizzacost = pizzaCosts[1];
                        if (pizza == "LP")
                            pizzacost = pizzaCosts[2];
                        if (pizza == "SC")
                            pizzacost = pizzaCosts[3];
                        if (pizza == "MC")
                            pizzacost = pizzaCosts[4];
                        if (pizza == "LC")
                            pizzacost = pizzaCosts[5];
                        if (pizza == "SV")
                            pizzacost = pizzaCosts[6];
                        if (pizza == "MV")
                            pizzacost = pizzaCosts[7];
                        if (pizza == "LV")
                            pizzacost = pizzaCosts[8];

                    cout << "              How many? (SO: >= 1): ";
                    cin >> quantity;

                }
                string answer2;
                int quantity2;
                float drinkcost;
                cout << "              Would you like a drink today? (y/n) ";
                cin >> answer2;
                if (answer2 == "y")
                {
                    cout << "              Which kind? (i.e. SS = Small Soda): ";
                    cin >> drink;
                    cout << "              How many? (SO: >= 1): ";
                    cin >> quantity2;
                        //Costs are dependent on what kind of drink and the size
                        if (drink == "SS")
                            drinkcost = drinkCosts[0];
                        if (drink == "MS")
                            drinkcost = drinkCosts[1];
                        if (drink == "LS")
                            drinkcost = drinkCosts[2];
                        if (drink == "SL")
                            drinkcost = drinkCosts[3];
                        if (drink == "ML")
                            drinkcost = drinkCosts[4];
                        if (drink == "LL")
                            drinkcost = drinkCosts[5];
                        if (drink == "SW")
                            drinkcost = drinkCosts[6];
                        if (drink == "MW")
                            drinkcost = drinkCosts[7];
                        if (drink == "LW")
                            drinkcost = drinkCosts[8];
                }

                //If they say no to wanting a drink or a pizza
                if (answer == "n" && answer2 == "n")
                {
                    cout << "              Goodbye!" << endl;
                    exit(0);
                }

                float temptip;
                string gettip;
                cout << "              Would you like to tip? (y/n) ";
                cin >> gettip;
                if (gettip == "y")
                {
                    cout << "              Enter tip percent (i.e. 0.08 = 8%) ";
                    cin >> temptip; //We will get the tip percent as a decimal
                    tip = temptip;
                }
                else tip = 0; //If they don't want to tip then the tip will be 0

                if (answer == "n" && answer2 == "y")
                {
                    total = total + (drinkcost * quantity2) +((drinkcost * quantity2) * tax) + ((drinkcost * quantity2) * tip);
                }
                if (answer == "y" && answer2 == "n")
                    total = total + (pizzacost * quantity) + ((pizzacost * quantity) * tax) + ((pizzacost * quantity) * tip);
                if (answer == "y" && answer2 == "y")
                    total = total + ((drinkcost * quantity2) +((drinkcost * quantity2) * tax) + ((drinkcost * quantity2) * tip)) + ((pizzacost * quantity) + ((pizzacost * quantity) * tax) + ((pizzacost * quantity) * tip));

                cout << "              Your total is: " << "$" << total << endl;
                cout << "              Thank you so much for coming, please do come again!" << endl;

                writeCheck(total);
            }

            //Set the waiter's name
            void setwaiterName(string N)
            {
                waiterName = N;
            }

            //Get the waiters name
            string getwaiterName()
            {
                return waiterName;
            }

            //Set the value of what tax is
            void Set_tax (float T)
            {
                tax = T;
            }

            //Get the tax value
            float Get_tax ()
            {
                return tax;
            }

            void Get_pizzaCosts() //Outputs the values in the pizzaCosts array
            {
                //Index through whole array
                for (int i = 0; i < 9; i++)
                {
                    cout << "                                 " << pizzaCosts[i] << endl; //Output each value with an end of line
                }
            }

            void Get_drinkCosts() //Outputs the values in the drinkCosts array
            {
                //Index through whole array
                for (int i = 0; i < 9; i++)
                {
                    cout << "                                 " << drinkCosts[i] << endl; //Output each value with an end of line
                }
            }
        private:
            //More than 4 data members
            string waiterName;
            float pizzaCosts[9]; //An array to hold the cost for the different kinds of pizzas and their respective sizes
            float drinkCosts[9]; //An array to hold the cost for the different kinds of pizzas and their respective sizes
            float tax; //The tax amount
            float tip; //The tip amount

    };
