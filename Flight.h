#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
using namespace std;

class Flight
{
public:
   // constructor initializes data members
   Flight( string flightNumberValue = "", int departureAirportValue = 0, int arrivalAirportValue = 0,
           string departureTimeValue = "", string arrivalTimeValue = "" );

   void setFlightNumber( string flightNumberValue );
   string getFlightNumber();
   void setDepartureAirport( int departureAirportValue );
   int getDepartureAirport();
   void setArrivalAirport( int arrivalAirportValue );
   int getArrivalAirport();
   void setDepartureTime( string departureTimeValue );
   string getDepartureTime();
   void setArrivalTime( string arrivalTimeValue );
   string getArrivalTime();

   // displays flightNumber, airport[ departureAirport ], airport[ arrivalAirport ], date,
   // departureTime, arrivalTime and flightPrices[ departureAirport ][ arrivalAirport ]
   void display1( string date );

   // displays name, flightPrices[ departureAirport ][ arrivalAirport ], flightNumber,
   // airport[ departureAirport ], airport[ arrivalAirport ], date, departureTime, arrivalTime
   void display2( string name, string date );
private:
   char flightNumber[ 8 ];  // flight number
   int departureAirport;    // departure airport code
   int arrivalAirport;      // arrival airport code
   char departureTime[ 8 ]; // departure time
   char arrivalTime[ 8 ];   // arrival time
};

#endif