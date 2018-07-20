#include <stdio.h>

#include "sentry.h"
#include "url.h"

struct sentry_dsn *sentry_create_dsn() {
  struct sentry_dsn *d = malloc(sizeof(struct sentry_dsn));
  return d;
}

struct sentry_client *sentry_create_client() {
  struct sentry_client *c = malloc(sizeof(struct sentry_client));
  c->dsn = sentry_create_dsn();
  return c;
}

int sentry_destroy_dsn(struct sentry_dsn *d) {
  free(d->hostname);
  free(d);
  return 0;
}

int sentry_set_dsn(struct sentry_client *c, char *dsn) {
  url_data_t *parsed = url_parse(dsn);
  c->dsn->hostname = strdup(parsed->host);
  url_free(parsed);
  return 0;
}

int sentry_destroy_client(struct sentry_client *c) {
  sentry_destroy_dsn(c->dsn);
  free(c);
  return 0;
}

int demo_func(int a) { return a * 2; }
