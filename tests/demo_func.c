#include "ctest.h"
#include <assert.h>
#include <sentry.h>
#include <stdlib.h>
#include <url.h>

// there are many different ASSERT macro's (see ctest.h)
CTEST(base, test2) { ASSERT_EQUAL(4, demo_func(2)); }

CTEST(base, test1) { ASSERT_EQUAL(4, demo_func(2)); }

CTEST(base, url1) {
  char *gh_url = "git://git@github.com:jwerle/url.h.git";
  char *url =
      "http://user:pass@subdomain.host.com:8080/p/a/t/h?query=string#hash";

  url_data_t *parsed = url_parse(url);
  url_data_t *gh_parsed = url_parse(gh_url);


  //url_data_inspect(parsed);
  //url_data_inspect(gh_parsed);

  ASSERT_STR("github.com", gh_parsed->host);
  
}
