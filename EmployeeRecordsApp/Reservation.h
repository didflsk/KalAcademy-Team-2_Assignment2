#pragma once
#include <string>

namespace AirlineReservationSystem {
	const int kDefaultStartingSalary = 30000;
	class Reservation
	{
	public:
		Reservation() = default;
		Reservation(const std::string& firstName,
			const std::string& lastName);

		void doReserve();
		void doCancel();
		void promote(int raiseAmount = 100);
		void demote(int demeritAmount = 100);
		void display() const;

		//Getters and setters
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setConfirmationNumber(int employeeNumber);
		int getConfirmationNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isBooked() const;
	private:
		std::string mFirstName;
		std::string mLastName;
		int mConfirmationNumber = -1;
		int mSalary = kDefaultStartingSalary;
		bool mBooked = false;
	};
}