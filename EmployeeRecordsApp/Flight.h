#pragma once
#include <string>

namespace AirlineReservationSystem {
	class Flight {
		public:
			void setSeatNumber(int seatNumber);
			int getSeatnumber() const;
		private:
			int mSeatNumber = -1;


	};
	

}