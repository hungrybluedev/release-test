#include <releasetest/util/util.h>
#include <releasetest/version.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  printf("Congratulations! You can run this build!\n");
  printf("\nVersion is: %s\n\n", RELEASE_TEST_VERSION);
  printf("Answer obtained is: %d\n", get_answer());
  printf("String obtained is: %s\n", get_message());
  return EXIT_SUCCESS;
}
