#ifndef _STRING_H_
#  define _STRING_H_

size_t str_count_char(const char *str, const char ch) {
  size_t count = 0;
  while (*str) if (*str++ == ch) ++count;
  return count;
}

unsigned short starts_with(const char *str, const char *prefix) {
  size_t len = strlen(prefix);
  for (size_t i = 0; i < len; ++i) if (str[i] != prefix[i]) return 0;
  return 1;
}

#endif /* !_STRING_H_ */
