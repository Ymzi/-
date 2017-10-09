// Iterator class definition.
#ifndef ITERATOR_H
#define ITERATOR_H

template< typename T >
class Iterator 
{
   template< typename T > friend class vector;
public:
   Iterator(); // default constructor
   Iterator( const Iterator< T > &iteratorToCopy ); // copy constructor
   Iterator(T*);
   T& operator*() const;  // dereference an iterator
   T* operator->() const; // class member access operator

   const Iterator< T > &operator=( const Iterator< T > &right ); // assignment operator

   Iterator< T >& operator++();      // preincrement an iterator
   Iterator< T > operator+( int i ); // increment an iterator by i positions
   Iterator< T > operator-( int i ); // decrement an iterator by i positions

   bool operator==( const Iterator< T > &right ) const; // compare iterators for equality
   bool operator!=( const Iterator< T > &right ) const; // compare iterators for inequality
   bool operator<=( const Iterator< T > &right ) const; // compare iterators for less or equal
private:
   T *ptr; // keep a pointer to vector
}; // end class Iterator

// default constructor
template< typename T >
Iterator< T >::Iterator()
	: ptr(nullptr)
{
}
template< typename T >
Iterator< T >::Iterator(T*a)
	: ptr(a)
{
}
// copy constructor
template< typename T >
Iterator< T >::Iterator( const Iterator< T > &iteratorToCopy )
   : ptr( iteratorToCopy.ptr )
{
}

// overloaded dereference operator
template< typename T >
T& Iterator< T >::operator*() const
{
   return *ptr;
}

template< typename T >
T* Iterator< T >::operator->() const
{
   return ptr;
}

// overloaded assignment operator
template< typename T >
const Iterator< T >& Iterator< T >::operator=( const Iterator< T > &right )
{
   if( &right != this ) // avoid self-assignment
      ptr = right.ptr;
   return *this;
}

// overloaded prefix increment operator
template< typename T >
Iterator< T >& Iterator< T >::operator++()
{
   ++ptr;
   return *this;
}

template< typename T >
Iterator< T > Iterator< T >::operator+( int i )
{
   return Iterator< T >( ptr + i );
}

template< typename T >
Iterator< T > Iterator< T >::operator-( int i )
{
   return Iterator< T >( ptr - i );
}

// overloaded equality operator
template< typename T >
bool Iterator< T >::operator==( const Iterator< T > &right ) const
{
   return ptr == right.ptr;
}

// overloaded inequality operator
template< typename T >
bool Iterator< T >::operator!=( const Iterator< T > &right ) const
{
   return ptr != right.ptr;
}

// overloaded less or equal operator
template< typename T >
bool Iterator< T >::operator<=( const Iterator< T > &right ) const
{
   return ptr <= right.ptr;
}

#endif