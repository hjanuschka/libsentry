#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>

typedef struct url_parser_url {
  char *protocol;
  char *host;
  int port;
  char *path;
  char *query_string;
  int host_exists;
  char *host_ip;
} url_parser_url_t;


void free_parsed_url(url_parser_url_t *url_parsed);
int parse_url(char *url, bool verify_host, url_parser_url_t *parsed_url);
