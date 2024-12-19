//
// Created by Jason on 6/7/2024.
//

#include "DivideByZeroException.h"

const char *DivideByZeroException::what() const noexcept
{
    return "Denominator is zero";
}