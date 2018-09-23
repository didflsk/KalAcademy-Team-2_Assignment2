#pragma once

#include <iostream>
#include <vector>
#include "Reservation.h"

namespace AirlineReservationSystem {
	const int kFirstEmployeeNumber = 1000;

	class Database
	{
	public:
		Reservation& addEmployee(const std::string& firstName,
			const std::string& lastName);
		Reservation& getEmployee(int employeeNumber);
		Reservation& getEmployee(const std::string& firstName,
			const std::string& lastName);

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Reservation> mReservations;
		int mNextConfirmationNumber = kFirstConfirmationNumber;
	};
}