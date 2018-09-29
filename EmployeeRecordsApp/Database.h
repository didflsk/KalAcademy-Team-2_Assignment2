#pragma once

#include <iostream>
#include <vector>
#include "Reservation.h"

namespace AirlineReservationSystem {
	const int kFirstConfirmationNumber = 1000;

	class Database
	{
	public:
		Reservation& addReservation(const int& flightNumber, const std::string& firstName,
			const std::string& lastName);
		Reservation& getReservation(int confirmationNumber);
		Reservation& getReservation(const std::string& firstName,
			const std::string& lastName);

		void displayAll(const std::string& firstName,
			const std::string& lastName) const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Reservation> mReservations;
		int mNextConfirmationNumber = kFirstConfirmationNumber;
	};
}