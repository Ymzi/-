// FlightSchedule.h
// FlightSchedule class definition. Represents the flight schedule.
#ifndef FLIGHT_SCHEDULE_H
#define FLIGHT_SCHEDULE_H

#include "vector.h" // vector class definition
//#include <vector>
#include "Flight.h" // Flight class definition

class FlightSchedule
{
public:
   FlightSchedule(); // calls loadFlightSchedule()
   ~FlightSchedule();

   // calls the function Flight::display2 to display the information regarding
   // the Flight object containing specified flightNumber
   void display1( int count, string flightNumber, string name, string date );

   // calls the function Flight::display1 to display the information regarding
   // the Flight object containing specified departureAirport and arrivalAirport
   void display2( int departureAirport, int arrivalAirport, string date );

   // calls the function Flight::display2 to display the information regarding
   // the Flight object containing specified flightNumber, departureAirport and arrivalAirport
   void display3( string flightNumber, int departureAirport, int arrivalAirport, string name, string date );
private:
   vector< Flight > flights; // vector of the flights

   // puts the flight schedule, read from the file FlightSchedule.dat, into the vector flights
   void loadFlightSchedule();
}; // end class FlightSchedule

#endif // FLIGHT_SCHEDULE_H
