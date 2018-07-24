#ifndef __STRINGHELPERS_H__
#define __STRINGHELPERS_H__

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

#include "StringHelpers.inl"

#endif // __STRINGHELPERS_H__
