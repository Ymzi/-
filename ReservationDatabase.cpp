// ReservationDatabase.cpp
// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <fstream>
#include "ReservationDatabase.h" // ReservationDatabase class definition
#include "FlightSchedule.h" // FlightSchedule class definition

// ReservationDatabase default constructor loads flight reservations from the file Reservations.dat
ReservationDatabase::ReservationDatabase()
{
	loadReservations();
}

// ReservationDatabase destructor stores flight reservations into the file Reservations.dat
ReservationDatabase::~ReservationDatabase()
{
	storeReservations();
}

void ReservationDatabase::addReservation(Reservation reservation)
{
	reservations.push_back(reservation);
}

bool ReservationDatabase::empty()
{
	return (reservations.size() == 0);
}

bool ReservationDatabase::existReservation(string id)
{
	vector< Reservation >::iterator it;
	for (it = reservations.begin(); it != reservations.end(); ++it)
	if (it->getId() == id)
		return true;

	return false;
}
void ReservationDatabase::cancelReservation(string id, int n)
{
	int num = 0;
	vector< Reservation >::iterator it = reservations.begin(); // added
	/*for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].getId() == id)
		{
			num += 1;
			if (num == n)
			{
				reservations[i].setId("");
				reservations[i].setDate(""); // added
				reservations[i].setFlightNumber(""); // added
				reservations[i].setMobile(""); // added
				reservations[i].setName(""); // added
				reservations.erase(it); // added
				cout << "\nReservation Cancelled!\n";
			}
		}
	}*/
	for (int i = 0; i < reservations.size(); i++, ++it/*added*/)
	{
		if (reservations[i].getId() == id)
		{
			num += 1;
			if (num == n)
			{
				// reservations[i].setId(""); // deleted
				reservations.erase(it); // added
				cout << "\nReservation Cancelled!\n";
			}
		}
	}
}
void ReservationDatabase::display(string id)
{
	int num = 1;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].getId() == id)
		{
			FlightSchedule a;
			a.display1(num, reservations[i].getFlightNumber(), reservations[i].getName(), reservations[i].getDate());
			num += 1;
		}
	}
}
void ReservationDatabase::loadReservations()
{
	ifstream intput("Reservations.dat", ios::in | ios::binary);
	Reservation tmp;
	while (intput.read(reinterpret_cast<char*>(&tmp), sizeof(Reservation)))
		reservations.push_back(tmp);
	intput.close();
}
void ReservationDatabase::storeReservations()
{
	ofstream output("Reservations.dat", ios::out | ios::binary);
	for (int i = 0; i < reservations.size(); i++)
		output.write(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
	output.close();
}