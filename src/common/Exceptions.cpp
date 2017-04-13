//
// Author: Maud Marel 
// Date: 2017-04-04 22:07:40 
//
// Last Modified by:   Maud Marel 
// Last Modified time: 2017-04-04 22:07:40
//

#include "Exceptions.hh"

arcade::Error::Error(const std::string &message) noexcept : _message(message)
{
}

arcade::Error::Error() noexcept : _message("")
{
}

const char *arcade::Error::what() const noexcept
{
  return (_message.data());
}