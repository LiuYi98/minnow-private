#include <stdexcept>

#include "byte_stream.hh"
#include <string>

using namespace std;

ByteStream::ByteStream( uint64_t capacity )
  : capacity_( capacity )
  , s { "" }
  , current { 0 }
  , total_pushed { 0 }
  , total_popped { 0 }
  , closed { false }
  , error { false }
{}

void Writer::push( string data )
{
  if ( this->available_capacity() == 0 ) {
    return;
  }
  int64_t count = 0;
  if ( data.length() < this->available_capacity() ) {
    count = data.length();
  } else {
    count = available_capacity();
  }
  this->s += data.substr( 0, count );
  this->current += count;
  this->total_pushed += count;
}

void Writer::close()
{
  this->closed = true;
}

void Writer::set_error()
{
  // Your code here.
  this->error = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return this->closed;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return this->capacity_ - this->current;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return this->total_pushed;
}

string_view Reader::peek() const
{
  // Your code here.
  return this->s;
}

bool Reader::is_finished() const
{
  // Your code here.
  return this->closed && ( 0 == this->current );
}

bool Reader::has_error() const
{
  // Your code here.
  return this->error;
}

void Reader::pop( uint64_t len )
{
  if ( current == 0 ) {
    return;
  }
  int64_t count;
  if ( len < this->current ) {
    count = len;
  } else {
    count = this->current;
  }
  this->s = this->s.substr( count, s.length() );
  this->current -= count;
  this->total_popped += count;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return this->current;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return this->total_popped;
}
