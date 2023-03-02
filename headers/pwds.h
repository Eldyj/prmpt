#ifndef _PWDS_H_
#define _PWDS_H_

#  ifndef _NEXTOPT_H_
#    include"nextopt.h"
#  endif /* !_NEXTOPT_H_ */

#  ifndef _STDLIB_H
#    include<stdlib.h>
#  endif /* !_STDLIB_H */

char* pwd(void) {
  return getenv("PWD");
}

char* cwd(void) {
  char* buf;
  char* src = pwd();
  while(!next_opt(&src,&buf,'/'));
  return src;
}
#endif /* !_PWDS_H_ */
