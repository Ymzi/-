// MakingReservation.cpp
// Member-function definitions for class MakingReservation.
#include <iostream>
#include "MakingReservation.h" // MakingReservation class definition

extern char airport[ 6 ][ 12 ];
extern int flightPrices[ 6 ][ 6 ];

// MakingReservation constructor initializes data members
MakingReservation::MakingReservation( ReservationDatabase &theReservationDatabase,
                                      FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule )
{
} // end MakingReservation constructor
void MakingReservation::execute()
{
	Reservation  *newreservation;
	newreservation = new Reservation;
	string data;
	cout << "Input Booking Data" << endl;
	cout << "Departure Date (yyyy/mm/dd)¡G";
	cin >> data;
	newreservation->setDate(data);
	cout << "Departure Airport¡G" << endl;
	for (int i = 1; i < 6; i++)
	{
		cout << i << ". " << airport[i] << endl;
	}
	int check1 = -1;
	do
	{
		cout << "?";
		cin >> check1;
	} while (check1 < 1||check1 >5);
	cout << "Arrival Airport:" << endl;
	int a = 1;
	for (int i = 1; i < 6; i++)
	{
		if (flightPrices[check1][i] != 0)
			cout << i << ".  " << airport[i] << endl;
	}
	int check2 = -1;
	do
	{
		cout << "?";
		cin >> check2;
	} while (flightPrices[check1][check2]==0);
	flightSchedule.display2(check1,check2,data);
	string number, id, name, phone;
	cout << "Flight Number:" << endl;
	cin >>  number;
	newreservation->setFlightNumber(number);
	cout << "Input ID Number: " << endl;
	cin >> id;
	newreservation->setId(id);
	cout << "Name: " << endl;
	cin >> name;
	newreservation->setName(name);
	cout << "Mobile Phone: " << endl;
	cin >> phone;
	newreservation->setMobile(phone);
	cout << "Name   Fare    Flight              Segment        Date  Departure time  Arrival time" << endl;
	flightSchedule.display3(number, check1, check2,name,data);
	reservationDatabase.addReservation(*newreservation);
	reservationDatabase.~ReservationDatabase();
	reservationDatabase = *new ReservationDatabase; // added
	cout << "Reservation Completed!" << endl;
}