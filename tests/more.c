#include <stdlib.h>
#include <assert.h>
#include "ctest.h"
#include <sentry.h>


// there are many different ASSERT macro's (see ctest.h)
CTEST(more, test2) {
    ASSERT_EQUAL(4, demo_func(2));
}

CTEST(more, test1) {
    ASSERT_EQUAL(5, demo_func(2));
}




