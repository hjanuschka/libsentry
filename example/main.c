#include <stdio.h>
#include <sentry/sentry.h>

int main(int argc, char ** argv) {

  struct sentry_client *c;
  c = sentry_create_client();
  sentry_set_dsn(c, "http://sentry.io/Asdas");
  printf("DSN %s\n", c->dsn->hostname);
  sentry_destroy_client(c);
}
