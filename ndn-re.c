
#include "ndn-re.h"

// the interfaces from tiny-regex-c, for reference

/* /\* Typedef'd pointer to get abstract datatype. *\/ */
/* typedef struct regex_t* re_t; */


/* /\* Compile regex string pattern to a regex_t-array. *\/ */
/* re_t re_compile(const char* pattern); */


/* /\* Find matches of the compiled pattern inside text. *\/ */
/* int  re_matchp(re_t pattern, const char* text); */


/* /\* Find matches of the txt pattern inside text (will compile automatically first). *\/ */
/* int  re_match(const char* pattern, const char* text); */

#include "tiny-regex-c/re.h"

#include <stdio.h>

int ndn_re_match(const ndn_name_t *pattern, const ndn_name_t *name) {

  for (int i = 0; i < pattern->components_size; i++) {
    printf("/%.*s", pattern->components[i].size, pattern->components[i].value);
  }
  printf("\n");

}
