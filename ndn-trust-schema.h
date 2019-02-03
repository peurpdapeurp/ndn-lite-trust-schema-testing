
#ifndef NDN_TRUST_SCHEMA_H
#define NDN_TRUST_SCHEMA_H

#include "../ndn-lite/ndn-constants.h"

#define NDN_TRUST_SCHEMA_ANY_NAME_COMPONENT 0x00
#define NDN_TRUST_SCHEMA_WILDCARD
#define NDN_TRUST_SCHEMA_WILDCARD_SEQUENCE
#define NDN_TRUST_SCHEMA_SUBPATTERN_INDEX
#define NDN_TRUST_SCHEMA_

/**
 * The structure to represent an NDN Trust Schema Pattern Component.
 */
typedef struct schema_component {
  /**
   * The component type.
   */
  uint32_t type;
  /**
   * The value which name component holds. (not include T and L)
   */
  uint8_t value[NDN_NAME_COMPONENT_BUFFER_SIZE];
  /**
   * The size of component value buffer.
   */
  uint32_t size;
} schema_component_t;

/**
 * The structure to represent the NDN Trust Schema Pattern.
 * This structure is memory expensive so please be careful when using it.
 */
typedef struct ndn_schema_pattern {
  /**
   * The array of schema components contained in this schema pattern (not including T and L)
   */
  schema_component_t components[NDN_NAME_COMPONENTS_SIZE];
  /**
   * The number of schema components
   */
  uint32_t components_size;
} ndn_schema_pattern_t;

/**
 * Init an NDN Trust Schema pattern from a string. This function will do memory copy and
 * only support regular string; not support URI currently.
 * @param name. Output. The NDN Trust Schema pattern to be inited.
 * @param string. Input. The string from which the NDN Trust Schema pattern is inited.
 * @param size. Input. Size of the input string.
 * @return 0 if there is no error.
 */
int
ndn_schema_pattern_from_string(ndn_schema_pattern_t* pattern, const char* string, uint32_t size);

#endif // NDN_TRUST_SCHEMA_H
