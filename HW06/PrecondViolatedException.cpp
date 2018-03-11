#include "PrecondViolatedException.h"


PrecondViolatedException::PrecondViolatedException(const std::string& message)
    : std::logic_error("Precondition Violated Exception: " + message)
{
}//end PrecondViolatedException
