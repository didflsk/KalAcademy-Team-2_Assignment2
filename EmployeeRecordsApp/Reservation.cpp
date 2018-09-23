#include "stdafx.h"
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace AirlineReservationSystem {
	Reservation::Reservation(const std::string& firstName,
		const std::string& lastName)
		: mFirstName(firstName), mLastName(lastName)
	{
		/*mFirstName = firstName;
		mLastName = lastName;*/
	}

	void Reservation::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Reservation::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Reservation::doReserve()
	{
		mBooked = true;
	}

	void Reservation::doCancel()
	{
		mBooked = false;
	}

	void Reservation::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}

	const string& Reservation::getFirstName() const
	{
		return mFirstName;
	}

	void Reservation::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}

	const string& Reservation::getLastName() const
	{
		return mLastName;
	}


	void Reservation::setSalary(int newSalary) {
		mSalary = newSalary;
	}

	int Reservation::getSalary() const {
		return mSalary;
	}


	void Reservation::setConfirmationNumber(int employeeNumber) {
		mConfirmationNumber = employeeNumber;
	}

	int Reservation::getConfirmationNumber() const {
		return mConfirmationNumber;
	}

	bool Reservation::isBooked() const {
		return mBooked;
	}

	void Reservation::display() const
	{
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-------------------------" << endl;
		cout << (isBooked() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getConfirmationNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

}


