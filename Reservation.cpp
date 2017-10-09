#include <iostream>
#include <iomanip>
#include "Reservation.h" // Reservation class definition

Reservation::Reservation( string flightNumberValue, string idValue,
                          string nameValue, string mobileValue, string dateValue )
{
   setFlightNumber( flightNumberValue );
   setId( idValue );
   setName( nameValue );
   setMobile( mobileValue );
   setDate( dateValue );
}

void Reservation::setFlightNumber( string flightNumberValue )
{
   size_t length = flightNumberValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      flightNumber[ i ] = flightNumberValue[ i ];
   flightNumber[ length ] = '\0';
}

string Reservation::getFlightNumber()
{
   return string( flightNumber );
}

void Reservation::setId( string idValue )
{
   size_t length = idValue.size();
   length = ( length < 12 ? length : 11 );
   for( size_t i = 0; i < length; i++ )
      id[ i ] = idValue[ i ];
   id[ length ] = '\0';
}

string Reservation::getId()
{
   return string( id );
}

void Reservation::setName( string nameValue )
{
   size_t length = nameValue.size();
   length = ( length < 8 ? length : 7 );
   for( size_t i = 0; i < length; i++ )
      name[ i ] = nameValue[ i ];
   name[ length ] = '\0';
}

string Reservation::getName()
{
   return string( name );
}

void Reservation::setMobile( string mobileValue )
{
   size_t length = mobileValue.size();
   length = ( length < 12 ? length : 11 );
   for( size_t i = 0; i < length; i++ )
      mobile[ i ] = mobileValue[ i ];
   mobile[ length ] = '\0';
}

string Reservation::getMobile()
{
   return string( mobile );
}

void Reservation::setDate( string dateValue )
{
   size_t length = dateValue.size();
   length = ( length < 12 ? length : 11 );
   for( size_t i = 0; i < length; i++ )
      date[ i ] = dateValue[ i ];
   date[ length ] = '\0';
}

string Reservation::getDate()
{
   return string( date );
}