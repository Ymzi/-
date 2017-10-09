// FlightSchedule.cpp
// Member-function definitions for class FlightSchedule.
#include <iostream>
#include <fstream>
#include "FlightSchedule.h" // FlightSchedule class definition

// FlightSchedule default constructor loads flight schedule from the file FlightSchedule.dat
FlightSchedule::FlightSchedule()
{
   loadFlightSchedule();
}

FlightSchedule::~FlightSchedule()
{
}
void FlightSchedule::display1(int count, string flightNumber, string name, string date)
{
	for (int i = 0; i < flights.size(); i++)
	{
		if (flights[i].getFlightNumber() == flightNumber)
		{
			cout << count << ".  ";
			flights[i].display2(name, date);
		}
	}
}
void FlightSchedule::display2(int departureAirport, int arrivalAirport, string date)
{
	cout << "Flight  Departure airport  Arrival airport        Date  Departure time  Arrival time  Fare " << endl; // added
	for (int i = 0; i < flights.size(); i++)
	{
		if (flights[i].getDepartureAirport() == departureAirport && flights[i].getArrivalAirport() == arrivalAirport)
		{
			flights[i].display1(date);
		}
	}
}
void FlightSchedule::display3(string flightNumber, int departureAirport, int arrivalAirport, string name, string date)
{
	for (int i = 0; i < flights.size(); i++)
	{
		if (flights[i].getFlightNumber() == flightNumber)
			flights[i].display2(name, date);
	}
}
void FlightSchedule::loadFlightSchedule()
{
	ifstream intput("FlightSchedule.dat", ios::in | ios::binary);
	Flight tmp;
	while (intput.read(reinterpret_cast<char*>(&tmp), sizeof(Flight)))
		flights.push_back(tmp);
	intput.close();
}