#include <stdlib.h>
#include <assert.h>
#include "ctest.h"
#include <sentry.h>


// there are many different ASSERT macro's (see ctest.h)
CTEST(base, test2) {
    ASSERT_EQUAL(4, demo_func(2));
}

CTEST(base, test1) {
    ASSERT_EQUAL(4, demo_func(2));
}




