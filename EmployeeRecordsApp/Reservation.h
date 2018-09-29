#pragma once
#include <string>

namespace AirlineReservationSystem {
	
	class Reservation
	{
	public:
		Reservation() = default;
		Reservation(const std::string& firstName,
			const std::string& lastName);
		Reservation(const int& flightNumber, const std::string& firstName,
			const std::string& lastName);

		void doReserve();
		void doCancel();
		void display() const;
		

		//Getters and setters
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setConfirmationNumber(int confirmationNumber);
		int getConfirmationNumber() const;

		bool isBooked() const;
	private:
		std::string mFirstName;
		std::string mLastName;
		int mFlightNumber;
		int mConfirmationNumber = -1;
		bool mBooked = false;
	};
}