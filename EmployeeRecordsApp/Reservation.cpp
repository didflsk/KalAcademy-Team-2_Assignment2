#include "stdafx.h"
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace AirlineReservationSystem {
	Reservation::Reservation(const int& flightNumber, const std::string& firstName,
		const std::string& lastName)
		: mFlightNumber(flightNumber), mFirstName(firstName), mLastName(lastName)
	{
		/*mFirstName = firstName;
		mLastName = lastName;*/
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
		cout << "Reservation Info" << endl;
		cout << "Passenger: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-------------------------" << endl;
		cout << (isBooked() ? "Booked" : "Cancelled") << endl;
		cout << "Confirmation Number: " << getConfirmationNumber() << endl;
		cout << endl;
	}
	

}


