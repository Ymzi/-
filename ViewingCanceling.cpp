#include <iostream>
#include "ViewingCanceling.h" // ViewingCanceling class definition

// ViewingCanceling constructor initializes data members
ViewingCanceling::ViewingCanceling( ReservationDatabase &theReservationDatabase,
                                    FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule ),
     id( "" )
{
} // end ViewingCanceling constructor
void ViewingCanceling::cancelingReservation()
{
	int number;
	viewingReservation();
	cout << " Enter your choice:";
	cin >> number;
	if (number < 1)
		return;
	reservationDatabase.cancelReservation(id, number);
	reservationDatabase.~ReservationDatabase();
}
bool ViewingCanceling::viewingReservation()
{
	// ReservationDatabase reservationDatabase; // deleted
	reservationDatabase = *new ReservationDatabase;
	int check = false;
	if (reservationDatabase.empty() == 0)
		check = true;
	else
	{
		cout << "No reservation information!" << endl;
		return 0;
	}
	if (check)
	{
		do
		{
			cout << "Enter ID Number: ";
			cin >> id;
		} while ((reservationDatabase.existReservation(id)) == false);
		cout << "     Name   Fare    Flight              Segment        Date  Departure time  Arrival time" << endl;
		reservationDatabase.display(id);
		return 1;
	}
	return 1;
}