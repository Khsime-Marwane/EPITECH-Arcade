#ifndef ___EXCEPTION_HPP___
# define ___EXCEPTION_HPP___

#include <string>
#include <exception>

namespace arcade
{
  class Error : public std::exception
  {
  protected:
    std::string _message;

  public:
    Error(const std::string &) noexcept;
    Error() noexcept;
    virtual ~Error() noexcept {};

    virtual const char *what() const noexcept;
  };
}

#endif // ___EXCEPTION_HPP___
