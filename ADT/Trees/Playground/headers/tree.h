#ifndef TREE_H
#define TREE_H

// Generic header that includes the selected version
#ifdef TREE_V1
#include "v1.h"
#elif defined(TREE_V2)
#include "v2.h"
#elif defined(TREE_V3)
#include "v3.h"
#else
#include "v1.h"  // default
#endif

#endif
