#ifndef _TEMPLATES_H_
#  define _TEMPLATES_H_

#  ifndef _SPWD_H_
#    include"spwd.h"
#  endif

char* user(void) {
  return getenv("USER");
}

char* host(void) {
  return getenv("HOSTNAME");
}

#endif /* !_TEMPLATES_H_ */
