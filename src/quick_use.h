#ifndef QUICK_USE
#define QUICK_USE

#ifdef DEFINE_ALL

#define INCLUDE_ALL
#define UNIVERSAL

#endif

#ifdef INCLUDE_ALL

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include "errors.h"

#endif

#ifdef UNIVERSAL

char* universal_convert_to_string(char __char);

#endif

#endif