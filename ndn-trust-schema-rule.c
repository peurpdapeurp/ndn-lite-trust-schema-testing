
#include "ndn-trust-schema-rule.h"

int
ndn_trust_schema_rule_from_strings(ndn_trust_schema_rule_t* rule,
				     const char* data_name_pattern_string, uint32_t data_name_pattern_string_size,
				     const char* key_name_pattern_string, uint32_t key_name_pattern_string_size) {

  const char function_msg_prefix[] = "In ndn_trust_schema_rule_from_strings, ";
  int ret_val = -1;
  
  ret_val = ndn_trust_schema_pattern_from_string(&rule->data_pattern, data_name_pattern_string, data_name_pattern_string_size);
  if (ret_val != 0) {
    printf("%sndn_trust_schema_pattern_from_string failed, error code: %d\n", function_msg_prefix, ret_val);
    return ret_val;
  }
  
  ret_val = ndn_trust_schema_pattern_from_string(&rule->key_pattern, key_name_pattern_string, key_name_pattern_string_size);
  if (ret_val != 0) {
    printf("%sndn_trust_schema_pattern_from_string failed, error code: %d\n", function_msg_prefix, ret_val);
    return ret_val;
  }

  return 0;
  
}