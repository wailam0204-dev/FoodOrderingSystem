/*

Name :TING WAI LAM

Id :2301099

Program : SE

Compiler: MICROSOFT VISUAL STUDIO

=====================================

*/

//Preprocessor Directives
#include <iostream>  
#include <iomanip> // Sets the number of digits displayed for floating-point values
#include <cmath> // Compute the price and quantity
#include <string> //For user input food code
#include <fstream> // For file operations
using namespace std;

//Define all price
#define FOOD_NASILEMAK 9.5
#define FOOD_ROTICANAI 3.0
#define FOOD_FRIEDRICE 6.5

#define BEVERAGE_APPLEJUICE 8.0
#define BEVERAGE_ORANGEJUICE 7.5
#define BEVERAGE_MANGOJUICE 9.5

#define DESSERT_CHEESECAKE 7.5
#define DESSERT_ICECREAM 5.0
#define DESSERT_WAFFLE 4.5

//Function Prototypes
double get_order(int* nasilemak_quantity, int* roticanai_quantity, int* friedrice_quantity, int* applejuice_quantity, int* orangejuice_quantity, int* mangojuice_quantity, int* cheesecake_quantity, int* icecream_quantity, int* waffle_quantity,
	double* nasilemak_price, double* roticanai_price, double* friedrice_price, double* applejuice_price, double* orangejuice_price, double* mangojuice_price, double* cheesecake_price, double* icecream_price, double* waffle_price);   //pass-by 


double display_trolley(int* nasilemak_quantity, int* roticanai_quantity, int* friedrice_quantity, int* applejuice_quantity, int* orangejuice_quantity, int* mangojuice_quantity, int* cheesecake_quantity, int* icecream_quantity, int* waffle_quantity,
	double* nasilemak_price, double* roticanai_price, double* friedrice_price, double* applejuice_price, double* orangejuice_price, double* mangojuice_price, double* cheesecake_price, double* icecream_price, double* waffle_price);

void compute_prepare_time(int* nasilemak_quantity, int* roticanai_quantity, int* friedrice_quantity, int* applejuice_quantity, int* orangejuice_quantity, int* mangojuice_quantity, int* cheesecake_quantity, int* icecream_quantity, int* waffle_quantity);

void display_statistics(double total_price, double* daily_sales_overall, int* daily_orders_overall, int total_orders);



// Global variables for statistics
double daily_sales_overall = 0;
int total_orders = 0;
int daily_orders_overall;

int main(void)
{
	//search a file name daily_statistics.txt and open
	ifstream infile("daily_statistics.txt");
	if (infile.is_open()) {
		string line;
		string line2;

		// Read every line from the file to get the latest daily_sales_overall
		while (getline(infile, line)) {

			if (line.find("Daily Sales Overall: RM ") != string::npos) {

				string sales_str = line.substr(24);
				daily_sales_overall = stod(sales_str);
			}
		}

		// Reset file stream to read from the beginning again
		infile.clear();
		infile.seekg(0, ios::beg);

		// Read every line from the file to get the latest daily_orders_overall
		while (getline(infile, line2)) {

			if (line2.find("Daily Orders Overall: ") != string::npos) {

				string order_str = line2.substr(22);
				daily_orders_overall = stoi(order_str);
			}
		}
		infile.close();
	}

	cout << "Welcome to ASIA MIX RESTAURANT\n";
	cout << "This is our menu\n";

	// Variables
	int nasilemak_quantity = 0, roticanai_quantity = 0, friedrice_quantity = 0, applejuice_quantity = 0, orangejuice_quantity = 0, mangojuice_quantity = 0, cheesecake_quantity = 0, icecream_quantity = 0, waffle_quantity = 0;
	double nasilemak_price = 0, roticanai_price = 0, friedrice_price = 0, applejuice_price = 0, orangejuice_price = 0, mangojuice_price = 0, cheesecake_price = 0, icecream_price = 0, waffle_price = 0;


	// Function calls
	get_order(&nasilemak_quantity, &roticanai_quantity, &friedrice_quantity, &applejuice_quantity, &orangejuice_quantity, &mangojuice_quantity, &cheesecake_quantity, &icecream_quantity, &waffle_quantity,
		&nasilemak_price, &roticanai_price, &friedrice_price, &applejuice_price, &orangejuice_price, &mangojuice_price, &cheesecake_price, &icecream_price, &waffle_price); //pass-by address 

	double total_price = display_trolley(&nasilemak_quantity, &roticanai_quantity, &friedrice_quantity, &applejuice_quantity, &orangejuice_quantity, &mangojuice_quantity, &cheesecake_quantity, &icecream_quantity, &waffle_quantity,
		&nasilemak_price, &roticanai_price, &friedrice_price, &applejuice_price, &orangejuice_price, &mangojuice_price, &cheesecake_price, &icecream_price, &waffle_price);


	compute_prepare_time(&nasilemak_quantity, &roticanai_quantity, &friedrice_quantity, &applejuice_quantity, &orangejuice_quantity, &mangojuice_quantity, &cheesecake_quantity, &icecream_quantity, &waffle_quantity);


	display_statistics(total_price, &daily_sales_overall, &daily_orders_overall, total_orders);


	return 0;
}

double get_order(int* nasilemak_quantity, int* roticanai_quantity, int* friedrice_quantity, int* applejuice_quantity, int* orangejuice_quantity, int* mangojuice_quantity, int* cheesecake_quantity, int* icecream_quantity, int* waffle_quantity,
	double* nasilemak_price, double* roticanai_price, double* friedrice_price, double* applejuice_price, double* orangejuice_price, double* mangojuice_price, double* cheesecake_price, double* icecream_price, double* waffle_price)
{
	//Show menu
	cout << "=======================================" << endl;
	cout << "Menu" << setw(21) << "RM" << endl;
	cout << "=======================================" << endl;
	cout << "F001 Nasi Lemak " << setw(10) << "9.50" << endl;
	cout << "F002 Roti Canai " << setw(10) << "3.00" << endl;
	cout << "F003 Fried Rice " << setw(10) << "6.50" << endl;
	cout << "======================================" << endl;
	cout << "B001 Apple Juice" << setw(10) << "8.00" << endl;
	cout << "B002 Orange Juice" << setw(9) << "7.50" << endl;
	cout << "B003 Mango Juice" << setw(10) << "9.50" << endl;
	cout << "======================================" << endl;
	cout << "D001 Cheesecake" << setw(11) << "7.50" << endl;
	cout << "D002 Ice Cream" << setw(12) << "5.00" << endl;
	cout << "D003 Waffle" << setw(15) << "4.50" << endl;
	cout << "======================================" << endl;

	// Local variables

	char answer; //  Loop for edit order
	string dishes_code; // For user input the dishes code



	do {


		// Let user input code, and insert quantity, and display the price
		cout << "                                  " << endl;
		cout << ">: Please insert the code to add order.(example: F001 or b002) " << endl; // Prompt user to follow menu input food code
		cout << ">: Caution: If you insert the dishes code again, the particular order quantity will be reset." << endl; //The quantity of dishes will be reset to 0 if it is reinput again
		cout << endl;
		cin >> dishes_code;

		if (dishes_code == "F001" || dishes_code == "f001")
		{
			cout << " Nasi Lemak RM9.50 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *nasilemak_quantity; //Input quantity

			if (*nasilemak_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else
				*nasilemak_price = *nasilemak_quantity * FOOD_NASILEMAK;
			cout << "The price of nasi lemak is RM " << *nasilemak_price << endl;


		}

		else if (dishes_code == "F002" || dishes_code == "f002")
		{
			cout << " Roti Canai RM3.00 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *roticanai_quantity;

			if (*roticanai_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}


			*roticanai_price = *roticanai_quantity * FOOD_ROTICANAI;
			cout << "The price of roti canai is RM " << *roticanai_price << endl;

		}

		else if (dishes_code == "F003" || dishes_code == "f003")
		{
			cout << " Fried Rice RM6.50 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *friedrice_quantity;

			if (*friedrice_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else
				*friedrice_price = *friedrice_quantity * FOOD_FRIEDRICE;
			cout << "The price of fried rice is RM " << *friedrice_price << endl;


		}

		else if (dishes_code == "B001" || dishes_code == "b001")
		{
			cout << " Apple Juice RM8.00 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *applejuice_quantity;

			if (*applejuice_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else

				*applejuice_price = *applejuice_quantity * BEVERAGE_APPLEJUICE;
			cout << "The price of apple juice is RM " << *applejuice_price << endl;
		}

		else if (dishes_code == "B002" || dishes_code == "b002")
		{
			cout << " Orange Juice RM7.50 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *orangejuice_quantity;

			if (*orangejuice_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else
				*orangejuice_price = *orangejuice_quantity * BEVERAGE_ORANGEJUICE;
			cout << "The price of orange juice is RM " << *orangejuice_price << endl;
		}

		else if (dishes_code == "B003" || dishes_code == "b003")
		{
			cout << " Mango Juice RM9.50 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *mangojuice_quantity;

			if (*mangojuice_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else
				*mangojuice_price = *mangojuice_quantity * BEVERAGE_MANGOJUICE;
			cout << "The price of mango juice is RM " << *mangojuice_price << endl;
		}

		else if (dishes_code == "D001" || dishes_code == "d001")
		{
			cout << " Cheese Cake RM7.50 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *cheesecake_quantity;

			if (*cheesecake_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else
				*cheesecake_price = *cheesecake_quantity * DESSERT_CHEESECAKE;
			cout << "The price of mango juice is RM " << *cheesecake_price << endl;

		}

		else if (dishes_code == "D002" || dishes_code == "d002")
		{
			cout << " Ice cream RM5.00 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *icecream_quantity;

			if (*icecream_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number.Please reorder again.\033[0m" << endl;
				break;
			}

			else

				*icecream_price = *icecream_quantity * DESSERT_ICECREAM;
			cout << "The price of ice cream is RM " << *icecream_price << endl;

		}

		else if (dishes_code == "D003" || dishes_code == "d003")
		{
			cout << " Waffle RM4.50 " << endl;
			cout << "\n Please insert quantity: ";
			cin >> *waffle_quantity;

			if (*waffle_quantity < 0)
			{
				cout << endl;
				cout << "\033[1;31mInvalid value. Please enter a valid number. Please reorder again.\033[0m" << endl;
				break;
			}

			else

				*waffle_price = *waffle_quantity * DESSERT_WAFFLE;
			cout << "The price of waffle is RM " << *waffle_price << endl;

		}

		else
		{
			// Display error when user input wrong food code
			cout << "\033[1;31mInvalid food code entered.\033[0m \n";

		}


		cout << "=============================================================" << endl;
		cout << " Your Trolley" << setw(12) << "RM" << setw(16) << "QUANTITY" << setw(10) << "TOTAL" << endl;
		cout << "=============================================================" << endl;
		cout << "F001 Nasi Lemak " << setw(10) << "9.50" << setw(11) << fixed << setprecision(2) << *nasilemak_quantity << setw(14) << fixed << setprecision(2) << *nasilemak_price << endl;
		cout << "F002 Roti Canai " << setw(10) << "3.00" << setw(11) << *roticanai_quantity << setw(14) << *roticanai_price << endl;
		cout << "F003 Fried Rice " << setw(10) << "6.50" << setw(11) << *friedrice_quantity << setw(14) << *friedrice_price << endl;
		cout << "=============================================================" << endl;
		cout << "B001 Apple Juice" << setw(10) << "8.00" << setw(11) << *applejuice_quantity << setw(14) << *applejuice_price << endl;
		cout << "B002 Orange Juice" << setw(9) << "7.50" << setw(11) << *orangejuice_quantity << setw(14) << *orangejuice_price << endl;
		cout << "B003 Mango Juice" << setw(10) << "9.50" << setw(11) << *mangojuice_quantity << setw(14) << *mangojuice_price << endl;
		cout << "=============================================================" << endl;
		cout << "D001 Cheesecake" << setw(11) << "7.50" << setw(11) << *cheesecake_quantity << setw(14) << *cheesecake_price << endl;
		cout << "D002 Ice Cream" << setw(12) << "5.00" << setw(11) << *icecream_quantity << setw(14) << *icecream_price << endl;
		cout << "D003 Waffle" << setw(15) << "4.50" << setw(11) << *waffle_quantity << setw(14) << *waffle_price << endl;
		cout << "===============================================================" << endl;
		cout << "\n Would you like to make any changes or additions? (Y/N) \n"; // Choices for add-on or confirmed billing
		cin >> answer;




	} while (answer == 'Y' || answer == 'y'); // Loop for add on other items


	return 0;
}

double display_trolley(int* nasilemak_quantity, int* roticanai_quantity, int* friedrice_quantity, int* applejuice_quantity, int* orangejuice_quantity, int* mangojuice_quantity, int* cheesecake_quantity, int* icecream_quantity, int* waffle_quantity,
	double* nasilemak_price, double* roticanai_price, double* friedrice_price, double* applejuice_price, double* orangejuice_price, double* mangojuice_price, double* cheesecake_price, double* icecream_price, double* waffle_price)
{
	double total_price; // Local variable


	cout << "=============================================================" << endl;
	cout << " Your Trolley" << setw(12) << "RM" << setw(16) << "QUANTITY" << setw(10) << "TOTAL" << endl;
	cout << "=============================================================" << endl;
	cout << "F001 Nasi Lemak " << setw(10) << "9.50" << setw(11) << fixed << setprecision(2) << *nasilemak_quantity << setw(14) << fixed << setprecision(2) << *nasilemak_price << endl;
	cout << "F002 Roti Canai " << setw(10) << "3.00" << setw(11) << *roticanai_quantity << setw(14) << *roticanai_price << endl;
	cout << "F003 Fried Rice " << setw(10) << "6.50" << setw(11) << *friedrice_quantity << setw(14) << *friedrice_price << endl;
	cout << "=============================================================" << endl;
	cout << "B001 Apple Juice" << setw(10) << "8.00" << setw(11) << *applejuice_quantity << setw(14) << *applejuice_price << endl;
	cout << "B002 Orange Juice" << setw(9) << "7.50" << setw(11) << *orangejuice_quantity << setw(14) << *orangejuice_price << endl;
	cout << "B003 Mango Juice" << setw(10) << "9.50" << setw(11) << *mangojuice_quantity << setw(14) << *mangojuice_price << endl;
	cout << "=============================================================" << endl;
	cout << "D001 Cheesecake" << setw(11) << "7.50" << setw(11) << *cheesecake_quantity << setw(14) << *cheesecake_price << endl;
	cout << "D002 Ice Cream" << setw(12) << "5.00" << setw(11) << *icecream_quantity << setw(14) << *icecream_price << endl;
	cout << "D003 Waffle" << setw(15) << "4.50" << setw(11) << *waffle_quantity << setw(14) << *waffle_price << endl;

	cout << "===============================================================" << endl;
	cout << "The food will be prepare after make payment." << endl;
	cout << "Please make payment at the counter, thanks!" << endl;

	total_price = (fabs)(*nasilemak_price) + (fabs)(*roticanai_price) + (fabs)(*friedrice_price) + (fabs)(*applejuice_price) + (fabs)(*orangejuice_price) + (fabs)(*mangojuice_price) + (fabs)(*cheesecake_price) + (fabs)(*icecream_price) + (fabs)(*waffle_price);
	cout << " \033[1;32m The total price is RM \033[0m" << (fabs)(total_price) << endl; //Compute prices, fabs function ensure that total_price is always positive 

	if (total_price > 0)
	{
		total_orders++;
	}

	else
		cout << "Error." << endl;

	return total_price;


}

void compute_prepare_time(int* nasilemak_quantity, int* roticanai_quantity, int* friedrice_quantity, int* applejuice_quantity, int* orangejuice_quantity, int* mangojuice_quantity, int* cheesecake_quantity, int* icecream_quantity, int* waffle_quantity)
{
	int total_prepare_time = 0;
	int food_prepare_time;
	int beverage_prepare_time;
	int dessert_prepare_time;



	food_prepare_time = (*nasilemak_quantity + *roticanai_quantity + *friedrice_quantity) * 5;//minutes   
	beverage_prepare_time = (*applejuice_quantity + *orangejuice_quantity + *mangojuice_quantity) * 2;//minutes
	dessert_prepare_time = (*cheesecake_quantity + *icecream_quantity + *waffle_quantity) * 2;//minutes 

	total_prepare_time = (food_prepare_time + beverage_prepare_time + dessert_prepare_time); //Compute preparation time

	if (total_prepare_time < 0)
	{
		cout << "\033[1;31mInvalid order.\033[0m";

	}
	else
		cout << "Your order will be taking " << total_prepare_time << " minutes. " << endl;

	return;

}

void display_statistics(double total_price, double* daily_sales_overall, int* daily_orders_overall, int total_orders)
{
	// Update daily sales and orders overalls
	*daily_sales_overall += total_price;
	*daily_orders_overall += total_orders;

	// Display daily statistics on the console
	cout << "=========================================" << endl;
	cout << "Daily Sales Overall: RM " << *daily_sales_overall << endl;
	cout << "Daily Orders Overall: " << *daily_orders_overall << endl;

	// Saving daily statistics to a file
	ofstream outfile("daily_statistics.txt");
	if (outfile.is_open()) {
		outfile << "Daily Sales Overall: RM " << *daily_sales_overall << endl;
		outfile << "Daily Orders Overall: " << *daily_orders_overall << endl;
		outfile.close();
		cout << "Daily statistics saved to file 'daily_statistics.txt'." << endl;
	}
	else {
		cout << "Unable to open file for saving daily statistics." << endl;
	}
}