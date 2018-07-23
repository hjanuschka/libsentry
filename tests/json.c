#include "ctest.h"
#include "sentry.h"
#include <json-c/json.h>
#include <assert.h>
#include <stdlib.h>

// there are many different ASSERT macro's (see ctest.h)
CTEST(json, build_payload) {
  json_object * json;
  json = json_object_new_object();
  json_object_object_add(json, "test", json_object_new_string("value"));
  ASSERT_STR("{ \"test\": \"value\" }", json_object_to_json_string(json));
  json_object_put(json);

}
