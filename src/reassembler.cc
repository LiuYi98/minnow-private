#include "reassembler.hh"

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring, Writer& output )
{
  if (first_index == this->expecting_index) {
    
  }
  if (is_last_substring) {
    output.close();
  }
}

uint64_t Reassembler::bytes_pending() const
{
  // Your code here.
  return {};
}
