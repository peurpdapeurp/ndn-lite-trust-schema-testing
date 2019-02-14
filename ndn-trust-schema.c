
#include "ndn-trust-schema.h"

#include "../ndn-lite/ndn-error-code.h"
#include "../ndn-lite/ndn-constants.h"

#include <stdbool.h>
#include <stdio.h>

void _check_name_against_pattern(bool *name_valid, const ndn_trust_schema_pattern_t *pattern, const ndn_name_t* name) {

  const char function_msg_prefix[] = "In _check_name_against_pattern,";

  // allocate arrays for checking wildcard specializers
  char temp_wildcard_specializer_string_arr[NDN_TRUST_SCHEMA_PATTERN_COMPONENT_STRING_MAX_SIZE];  
  char temp_name_component_string_arr[NDN_TRUST_SCHEMA_PATTERN_COMPONENT_STRING_MAX_SIZE];
  
  int pat_len = pattern->components_size;
  int name_len = name->components_size;
  
  if (pat_len == 0 && name_len == 0) {
    *name_valid = true;
    return;
  }

  bool results[name_len+1][pat_len+1];

  // initialize all results to false
  for (int i = 0; i < name_len+1; i++) {
    for (int j = 0; j < pat_len+1; j++) {
      results[i][j] = false;
    }
  }

  // for the base case of comparing a 0 component name to a 0 component pattern,
  // the result is true
  results[0][0] = true;

  // first check successively larger substrings of the schema pattern containing
  // the first component of the pattern (i.e. from pattern <a><b><c>, check <a>, then <ab>, then <abc>)
  // against a 0 component name
  for (int j = 1; j < pat_len+1; j++) {
    if (pattern->components[j-1].type != NDN_TRUST_SCHEMA_WILDCARD_NAME_COMPONENT_SEQUENCE)
      break;
    results[0][j] = true;
  }

  for (int i = 1; i < name_len+1; i++) {
    for (int j = 1; j < pat_len+1; j++) {
      if (pattern->components[j-1].type == NDN_TRUST_SCHEMA_WILDCARD_NAME_COMPONENT)
      {
        results[i][j] = results[i-1][j-1];
      }
      else if (pattern->components[j-1].type == NDN_TRUST_SCHEMA_SINGLE_NAME_COMPONENT) {
	if (
	    memcmp(pattern->components[j-1].value, name->components[i-1].value, pattern->components[j-1].size) == 0 &&
	    pattern->components[j-1].size == name->components[i-1].size
	   )
	  results[i][j] = results[i-1][j-1];
      }
      else if (pattern->components[j-1].type == NDN_TRUST_SCHEMA_WILDCARD_SPECIALIZER) {
	memcpy(temp_wildcard_specializer_string_arr, pattern->components[j-1].value, pattern->components[j-1].size);
	temp_wildcard_specializer_string_arr[pattern->components[j-1].size] = '\0';

	memcpy(temp_name_component_string_arr, name->components[i-1].value, name->components[i-1].size);
	temp_name_component_string_arr[name->components[i-1].size] = '\0';
	
	printf("%s checking regex pattern %.*s against string %.*s\n",
	       function_msg_prefix,
	       pattern->components[j-1].size, temp_wildcard_specializer_string_arr,
	       name->components[i-1].size, temp_name_component_string_arr);
	
	int ret_val = re_match(temp_wildcard_specializer_string_arr, temp_name_component_string_arr);
	if (ret_val != TINY_REGEX_C_FAIL) {
	  results[i][j] = results[i-1][j-1];
	  printf("Got a match.\n");
	}
	else {
	  printf("Didnt get a match.\n");
	}
      }
      else if (pattern->components[j-1].type == NDN_TRUST_SCHEMA_SUBPATTERN_MATCH) {
	printf("Value of subpattern match found: %.*s\n", pattern->components[j-1].size, pattern->components[j-1].value);
	
      }
      else if (pattern->components[j-1].type == NDN_TRUST_SCHEMA_WILDCARD_NAME_COMPONENT_SEQUENCE) {
        results[i][j] = (results[i-1][j] || results[i][j-1]);
      }
    }
  }

  printf("Value of results array after processing:\n");
  for (int i = 0; i < name_len+1; i++) {
    for (int j = 0; j < pat_len+1; j++) {
      printf("%d ", results[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
  
  *name_valid = results[name_len][pat_len];
  
}

int
ndn_trust_schema_verify_data_name_key_name_pair(const ndn_trust_schema_rule_t* rule, const ndn_name_t* data_name, const ndn_name_t* key_name) {

  const char function_msg_prefix[] = "In ndn_trust_schema_verify_key_name, ";
  
  bool data_name_valid = true;
  bool key_name_valid = true;

  printf("Checking data name pattern.\n\n");
  
  _check_name_against_pattern(&data_name_valid, &rule->data_pattern, data_name);

  printf("Checking key name pattern.\n\n");
  
  _check_name_against_pattern(&key_name_valid, &rule->key_pattern, key_name);
  
  return (data_name_valid && key_name_valid) ? 0 : -1;
  
}
