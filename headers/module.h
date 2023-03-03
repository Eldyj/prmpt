#ifndef _MODULE_H_
#  define _MODULE_H_

#  ifndef _SPWD_H_
#    include "spwd.h"
#  endif /* !_SPWD_H_ */

#  ifndef _ANSI_H_
#    include "ansi.h"
#  endif /* !_ANSI_H_ */

void module(char* src, char** lc, char* sep) {
  char* str = src;
  char* fg  = "";
  char* bg  = "";
  char* tx  = "";

  next_opt(&str,&fg,';');
  next_opt(&str,&bg,';');
  next_opt(&str,&tx,';');

  if (!*tx) return;
  
  if (!strcmp(tx,"@cwd")) tx = cwd();
  else if (!strcmp(tx,"@pwd")) tx = pwd();
  else if (!strcmp(tx,"@spwd")) tx = spwd();
  //else if (!strcmp(tx,"@spwde")) tx = spwde();

  printf("%s", ansi_col(bg,'b'));

  if (**lc != '-') printf("%s%s", ansi_col(*lc, 'f'), sep);

  printf(" %s%s \033[0m",ansi_col(fg,'f'),tx);
  *lc = bg;
}

#endif /* !_MODULE_H_ */

/*
 * TODO: turn module into function which will return string instead of printing it
 */
