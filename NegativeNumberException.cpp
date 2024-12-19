//
// Created by Jason on 6/7/2024.
//

#include "NegativeNumberException.h"

const char *NegativeNumberException::what() const noexcept
{
    return "Number is negative";
}
