#include "ctest.h"
#include <assert.h>
#include <sentry.h>
#include <stdlib.h>
#include <url.h>

// there are many different ASSERT macro's (see ctest.h)
CTEST(base, test2) { ASSERT_EQUAL(4, demo_func(2)); }

CTEST(base, test1) { ASSERT_EQUAL(4, demo_func(2)); }
