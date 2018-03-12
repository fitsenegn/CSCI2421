#ifndef PRECONDVIOLATEDEXCEPTION_H_
#define PRECONDVIOLATEDEXCEPTION_H_

#include <stdexcept>
#include <string>


class PrecondViolatedException : public std::logic_error{
public:
  PrecondViolatedException(const std::string& message = "");
};






#endif
