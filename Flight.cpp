#include <iostream>
#include <iomanip>
#include "Flight.h" // Flight class definition

extern char airport[ 6 ][ 12 ];
extern int flightPrices[ 6 ][ 6 ];

Flight::Flight( string flightNumberValue, int departureAirportValue,
                int arrivalAirportValue, string departureTimeValue, string arrivalTimeValue )
{
   setFlightNumber( flightNumberValue );
   setDepartureAirport( departureAirportValue );
   setArrivalAirport( arrivalAirportValue );
   setDepartureTime( departureTimeValue );
   setArrivalTime( arrivalTimeValue );
}

void Flight::setFlightNumber( string flightNumberValue )
{
   size_t length = flightNumberValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      flightNumber[ i ] = flightNumberValue[ i ];
   flightNumber[ length ] = '\0';
}

string Flight::getFlightNumber()
{
   return flightNumber;
}

void Flight::setDepartureAirport( int departureAirportValue )
{
   departureAirport = departureAirportValue;
}

int Flight::getDepartureAirport()
{
   return departureAirport;
}

void Flight::setArrivalAirport( int arrivalAirportValue )
{
   arrivalAirport = arrivalAirportValue;
}

int Flight::getArrivalAirport()
{
   return arrivalAirport;
}

void Flight::setDepartureTime( string departureTimeValue )
{
   size_t length = departureTimeValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      departureTime[ i ] = departureTimeValue[ i ];
   departureTime[ length ] = '\0';
}

string Flight::getDepartureTime()
{
   return string( departureTime );
}

void Flight::setArrivalTime( string arrivalTimeValue )
{
   size_t length = arrivalTimeValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      arrivalTime[ i ] = arrivalTimeValue[ i ];
   arrivalTime[ length ] = '\0';
}

string Flight::getArrivalTime()
{
   return string( arrivalTime );
}
void  Flight::display1(string date)
{
	// cout << "Flight  Departure airport  Arrival airport        Date  Departure time  Arrival time  Fare " << endl; // deleted
	cout << setw(5) << flightNumber << setw(15) << airport[departureAirport] << setw(16) << airport[arrivalAirport] << setw(18) << date << setw(14)
		<< departureTime << setw(12) << arrivalTime << setw(10) << flightPrices[departureAirport][arrivalAirport] << endl;
}
void  Flight::display2(string name, string date)
{
	cout << setw(4) << name << setw(8) << flightPrices[departureAirport][arrivalAirport] << setw(5) << " GE" << flightNumber <<  setw(15) <<  
		airport[departureAirport] << " -   "<< airport[arrivalAirport] << setw(8) << date << setw(10) << departureTime << setw(15) << arrivalTime << endl;
}