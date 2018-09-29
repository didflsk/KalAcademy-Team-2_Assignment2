#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace AirlineReservationSystem {

	Reservation& Database::addReservation(const int& flightNumber, const std::string& firstName,
		const std::string& lastName)
	{
		Reservation theReservation(flightNumber, firstName, lastName);
		theReservation.setConfirmationNumber(mNextConfirmationNumber++);
		theReservation.doReserve();
		mReservations.push_back(theReservation);

		return mReservations[mReservations.size() - 1];
	}

	Reservation& Database::getReservation(int confirmationNumber)
	{
		for (auto& reservation : mReservations) {
			if (reservation.getConfirmationNumber() == confirmationNumber) {
				return reservation;
			}
		}
		throw logic_error("No reservation found.");
	}

	Reservation& Database::getReservation(const string& firstName, const string& lastName)
	{
		for (auto& reservation : mReservations) {
			if (reservation.getFirstName() == firstName &&
				reservation.getLastName() == lastName) {
				return reservation;
			}
		}
		throw logic_error("No reservation found.");
	}

	void Database::displayAll(const std::string& firstName,
		const std::string& lastName) const
	{
		for (const auto& reservation : mReservations) {
			if (reservation.getFirstName() == firstName &&
				reservation.getLastName() == lastName)
				reservation.display();
		}
	}
	
	void Database::displayCurrent() const
	{
		for (const auto& reservation : mReservations) {
			if (reservation.isBooked())
				reservation.display();
		}
	}

	void Database::displayFormer() const
	{
		for (const auto& reservation : mReservations) {
			if (!reservation.isBooked())
				reservation.display();
		}
	}

}
