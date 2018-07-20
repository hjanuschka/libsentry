#include "sentry.h"
#include <stdio.h>

int main(int argc, char **argv) {
  struct sentry_client *c;
  c = sentry_create_client();
  sentry_set_dsn(c, "http://www.sentry.io/111");
  printf("URL: %s\n", c->dsn->hostname);
  sentry_destroy_client(c);
}
