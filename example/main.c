#include <stdio.h>
#include <sentry/sentry.h>

int main(int argc, char ** argv) {
  int a = demo_func(1);
  printf("Test %d\n", a);
}
