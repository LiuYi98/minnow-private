#include "reassembler.hh"
#include <cstdint>

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring, Writer& output )
{
  if ( output.bytes_pushed() == 0 && this->capacity == 0 ) {
    // this statement will ideally be executed only once
    this->capacity = output.available_capacity();
  }

  if ( data.length() > output.available_capacity() ) {
    // TODO: will discard the whole string work? @sppfly
    return;
  }

  if ( first_index > this->expecting_index ) {
    // TODO: we just discard the whole string for now, will see if it works
    uint64_t available_capacity = this->capacity - this->pending_bytes;
    if ( data.length() > available_capacity ) {
      return;
    }
    this->buf.push_back(BufString(, ));
    this->pending_bytes += data.length();
  } else {
    // Finaly we can do this
    output.push(data);
    this->expecting_index += data.length();
    while (true)
    {
      for (auto& p: buf) {
        if (this->expecting_index < p) {

        }
      }
    }
    


  }

  if ( is_last_substring ) {
    output.close();
  }
}

uint64_t Reassembler::bytes_pending() const
{
  return this->pending_bytes;
}
