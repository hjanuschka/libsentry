#include "ctest.h"
#include "sentry.h"
#include <assert.h>
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)
CTEST(client, init) {
  struct sentry_client *c;
  c = sentry_create_client();
  sentry_set_dsn(c, "http://sentry.io/Asdas");
  ASSERT_STR("sentry.io", c->dsn->hostname);
}
