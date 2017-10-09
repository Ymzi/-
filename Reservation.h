// Reservation.h
// Reservation class definition. Represents a reservation.
#ifndef RESERVATION_H
#define RESERVATION_H

#include "Flight.h"

class Reservation
{
public:
   // constructor initializes data members
   Reservation( string flightNumberValue = "", string idValue = "",
                string nameValue = "", string mobileValue = "", string dateValue = "" );

   void setFlightNumber( string flightNumberValue );
   string getFlightNumber();
   void setId( string idValue );
   string getId();
   void setName( string nameValue );
   string getName();
   void setMobile( string mobileValue );
   string getMobile();
   void setDate( string dateValue );
   string getDate();

private:
   char flightNumber[ 8 ]; // flight number
   char id[ 12 ];          // id number
   char name[ 8 ];         // name
   char mobile[ 12 ];      // mobile phone number
   char date[ 12 ];        // departure date
};

#endif