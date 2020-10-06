#ifndef REPLACEMENTFUNCTIONS_HPP_INCLUDED
#define REPLACEMENTFUNCTIONS_HPP_INCLUDED

#include <stdio.h>
#include <time.h>
#include <inttypes.h>

#define ATOMIC_BLOCK(type)
#define dbg_assert(value1,value2) if(!(value1)) printf(value2)

#define log_debug(msg, ...)   void();
#define log_trace(msg, ...)   void();
#define log_info(msg, ...)    void();

#endif // REPLACEMENTFUNCTIONS_HPP_INCLUDED
