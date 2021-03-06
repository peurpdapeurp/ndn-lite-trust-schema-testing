
    // the block of code below is code that I had written to get the actual indexes passed into the rule reference...
    // however, I am pretty sure it was a waste of time now; it is far simpler in the current implementation to assume
    // that if a rule is referenced, that it MUST have the same number of subpattern captures as the current data pattern,
    // and the problem of rule referencing becomes trivial in that I just have to pass a pointer to the subindex info array of the
    // data name of the original rule that was referencing the other rule...
    // therefore I am commenting out all code related to this more complex parsing  in case it becomes necessary

    /* int rule_ref_args_begin_idx = re_match(_rule_ref_args_rgxp, temp_pattern_comp_string_arr); */
    /* if (rule_ref_args_begin_idx == TINY_REGEX_C_FAIL) { */
    /*   return NDN_TRUST_SCHEMA_PATTERN_COMPONENT_PARSING_ERROR; */
    /* } */
    /* if (rule_ref_args_begin_idx > NDN_TRUST_SCHEMA_RULE_NAME_MAX_LENGTH) */
    /*   return NDN_OVERSIZE; */
    /* memset(component->value + NDN_TRUST_SCHEMA_RULE_REF_ARGS_BIT_FIELD_OFFSET, */
    /* 	   0, NDN_TRUST_SCHEMA_RULE_REFERENCE_ARGS_BIT_FIELD_SIZE); */
    /* if (rule_ref_args_begin_idx > size || */
    /* 	temp_pattern_comp_string_arr[rule_ref_args_begin_idx] != '(') */
    /*   return NDN_TRUST_SCHEMA_PATTERN_COMPONENT_PARSING_ERROR; */

    /* memcpy(component->value, string, rule_ref_args_begin_idx); */
    /* component->value[rule_ref_args_begin_idx] = '\0'; */

    /* int rule_ref_subpattern_arg_idx = rule_ref_args_begin_idx+1; */
    /* uint16_t *rule_ref_args_bit_field = (uint16_t *) (component->value + NDN_TRUST_SCHEMA_RULE_REF_ARGS_BIT_FIELD_OFFSET); */
    /* while (1) { */
    /*   int current_subpattern_arg_idx = re_match(_rule_ref_subpattern_index_rgxp, temp_pattern_comp_string_arr + rule_ref_subpattern_arg_idx); */
    /*   if (current_subpattern_arg_idx == TINY_REGEX_C_FAIL) return NDN_TRUST_SCHEMA_PATTERN_COMPONENT_PARSING_ERROR; */
      
    /*   rule_ref_subpattern_arg_idx += current_subpattern_arg_idx + 1; */
      
    /*   int current_subpattern_arg_end_idx = re_match(",", temp_pattern_comp_string_arr + rule_ref_subpattern_arg_idx); */
    /*   if (current_subpattern_arg_end_idx == TINY_REGEX_C_FAIL) { */
    /* 	current_subpattern_arg_end_idx = re_match(")", temp_pattern_comp_string_arr + rule_ref_subpattern_arg_idx); */
    /* 	if (current_subpattern_arg_end_idx == TINY_REGEX_C_FAIL || */
    /* 	    rule_ref_subpattern_arg_idx + current_subpattern_arg_end_idx != size-1) { */
    /* 	  return NDN_TRUST_SCHEMA_PATTERN_COMPONENT_PARSING_ERROR; */
    /* 	} */
    /*   } */
      
    /*   if (current_subpattern_arg_end_idx > 2) { */
    /* 	return NDN_TRUST_SCHEMA_PATTERN_COMPONENT_PARSING_ERROR; */
    /*   } */
      
    /*   if (current_subpattern_arg_end_idx == 1) { */
    /* 	memcpy(subpattern_idx_string, temp_pattern_comp_string_arr + rule_ref_subpattern_arg_idx, 1); */
    /*     subpattern_idx_string[1] = '\0'; */
    /*   } */
    /*   else if (current_subpattern_arg_end_idx == 2) */
    /* 	memcpy(subpattern_idx_string, temp_pattern_comp_string_arr + rule_ref_subpattern_arg_idx, current_subpattern_arg_end_idx); */
    /*   else */
    /* 	return NDN_TRUST_SCHEMA_PATTERN_COMPONENT_PARSING_ERROR; */
      
    /*   int idx = atoi(subpattern_idx_string); */
    /*   if (idx > NDN_TRUST_SCHEMA_MAX_SUBPATTERN_MATCHES - 1) { */
    /* 	return NDN_TRUST_SCHEMA_INVALID_SUBPATTERN_INDEX_REFERENCE; */
    /*   } */
      
    /*   *(rule_ref_args_bit_field) |= */
    /* 	(uint16_t) (0x01 << (NDN_TRUST_SCHEMA_RULE_REFERENCE_ARGS_BIT_FIELD_SIZE * 8 - idx - 1)); */
    /*   if (rule_ref_subpattern_arg_idx >= size-3) { */
    /* 	break; */
    /*   } */
    /* } */




/* #define NDN_TRUST_SCHEMA_PATTERN_COMPONENT_STRING_MAX_SIZE 50 */
/* #define NDN_TRUST_SCHEMA_RULE_REFERENCE_ARGS_BIT_FIELD_SIZE 2 */
/* #define NDN_TRUST_SCHEMA_RULE_NAME_MAX_LENGTH \ */
/*   (NDN_TRUST_SCHEMA_PATTERN_COMPONENT_BUFFER_SIZE - \ */
/*    NDN_TRUST_SCHEMA_RULE_REFERENCE_ARGS_BIT_FIELD_SIZE - 1) */
/* #define NDN_TRUST_SCHEMA_RULE_REF_ARGS_BIT_FIELD_OFFSET \ */
/*   (NDN_TRUST_SCHEMA_PATTERN_COMPONENT_BUFFER_SIZE - \ */
/*    NDN_TRUST_SCHEMA_RULE_REFERENCE_ARGS_BIT_FIELD_SIZE) */


    /* printf("Subpattern indexes passed into this rule reference: "); */
    
    /* uint16_t *rule_ref_args_bit_field = (uint16_t *) (rule->key_pattern.components[0].value + NDN_TRUST_SCHEMA_RULE_REF_ARGS_BIT_FIELD_OFFSET); */
    /* printf("Value of rule ref args bit field: %d\n", *rule_ref_args_bit_field); */
    /* for (int i = NDN_TRUST_SCHEMA_MAX_SUBPATTERN_MATCHES - 1; i >= 0 ; i--) { */
    /*   if (*rule_ref_args_bit_field >> i & 0x01) { */
    /* 	printf("%d, ", (NDN_TRUST_SCHEMA_MAX_SUBPATTERN_MATCHES - 1) - i); */
    /*   } */
    /* } */
    /* printf("\n"); */
