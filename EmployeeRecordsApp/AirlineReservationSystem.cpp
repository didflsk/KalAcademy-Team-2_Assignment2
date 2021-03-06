// EmployeeRecordsApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Database.h"
#include <iomanip>

using namespace std;
using namespace AirlineReservationSystem;

int displayMenu();
void doReserve(Database& db);
void doCancel(Database& db);
void display(Database& db);
//void doDemote(Database& db);

int main()
{
	/*cout << "Testing the Employee class." << endl;
	Employee emp;
	emp.setFirstName("John");
	emp.setLastName("Doe");
	emp.setEmployeeNumber(71);
	emp.setSalary(50000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();*/

	/*Database myDB;

	Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
	emp1.fire();

	Employee& emp2 = myDB.addEmployee("Marc", "White");
	emp2.setSalary(100000);

	Employee& emp3 = myDB.addEmployee("John", "Doe");
	emp3.setSalary(10000);
	emp3.promote();

	cout << "all employees: " << endl << endl;
	myDB.displayAll();

	cout << endl << "current employees: " << endl << endl;
	myDB.displayCurrent();

	cout << endl << "former employees: " << endl << endl;
	myDB.displayFormer();*/

	Database reservationDB;

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			doReserve(reservationDB);
			break;
		case 2:
			doCancel(reservationDB);
			break;
		case 3:
			display(reservationDB);
			break;
		case 4:
			display(reservationDB);
			break;
		case 5:
			reservationDB.displayFormer();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Airline Reservation Database" << endl;
	cout << "-----------------------------" << endl;
	cout << "-----------------------------" << endl;
	cout << "                             " << endl;
	
	cout << "1) Reserve a flight" << endl;
	cout << "2) Cancel a flight" << endl;
	cout << "3) Confirm flight by name" << endl;
	cout << "4) Confirm flight by confirmation number" << endl;
	cout << "5) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";

	cin >> selection;

	return selection;
}

void doReserve(Database& db)
{
	int flightNumber;
	int seatNumber;
	string firstName;
	string lastName;
	int phoneNumber;


	std::cout << std::left;
	std::cout <<
		setw(20) << "[Flight Number]" << setw(15) << "[Departure]" << setw(20) << "[Arrival]" << setw(20) << "[Fare]" << '\n' <<
		setw(20) << "Flight 100" << setw(15) << "Seattle,WA " << setw(20) << "Los Angeles,CA" << setw(20) << "$350" << '\n' <<
		setw(20) << "Flight 200" << setw(15) << "Seattle,WA" << setw(20) << "New York City,NY" << setw(20) << "$550" << '\n' <<
		setw(20) << "Flight 300" << setw(15) << "Seattle,WA" << setw(20) << "Chicago,IL" << setw(20) << "$500" << '\n' <<
		setw(20) << "Flight 400" << setw(15) << "Seattle,WA" << setw(20) << "Honolulu,HI" << setw(20) << "$650" << '\n' <<
		setw(20) << "Flight 500" << setw(15) << "Seattle,WA" << setw(20) << "Miami,FL" << setw(20) << "$700" << '\n';
	
	cout << "-------------------------" << endl;
	cout << "                         " << endl;
	cout << "-------------------------" << endl;


	cout << "Flight number?";
	cin >> flightNumber;
	cout << "Seat Number?";
	cin >> seatNumber;
	cout << "First name?";
	cin >> firstName;
	cout << "Last name?";
	cin >> lastName;
	cout << "Contact number?";
	cin >> phoneNumber;
	


	db.addReservation(flightNumber, firstName, lastName);
}

void doCancel(Database& db)
{
	int confirmationNumber;

	cout << "Confirmation number? ";
	cin >> confirmationNumber;

	try {
		Reservation& res = db.getReservation(confirmationNumber);
		res.doCancel();
		cout << "Reservation " << confirmationNumber << " cancelled." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to cancel the reservation: " << exception.what() << endl;
	}
}
	void display(Database& db)
	{
		string firstName;
		string lastName;

		cout << "First name?" << endl;
		cin >> firstName;
		cout << "Last name?" << endl;
		cin >> lastName;

		Reservation& res = db.getReservation(firstName, lastName);
		db.displayAll(firstName, lastName);
	}

	
	
		




