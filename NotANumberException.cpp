//
// Created by Jason on 6/7/2024.
//

#include "NotANumberException.h"

const char *NotANumberException::what() const noexcept
{
    return "Not a number";
}