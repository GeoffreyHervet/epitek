#include <string.h>

#define _GNU_SOURCE
#include <stdio.h>

#include "String.h"

# define S(s) \
  ({ \
   String *ss = malloc(sizeof(*ss)); \
   StringInit(ss, (s)); \
   ss; \
   })

# define ____ printf("----\n");

# define EXPECT(s,o) (printf("%s\n%s\n", (s), (o)->c_str(o)))

int main(void)
{
  int i;
  String *c = S("");
  printf("\n%s\n", c->c_str(c));
  ____

  String *b = S("lolilol");
  EXPECT("lolilol", b);
  ____

  c->assign_s(c, b);
  EXPECT("lolilol", c);
  ____

  b->assign_c(b, "amanone<3");
  EXPECT("amanone<3", b);
  ____

  b->append_s(b, c);
  EXPECT("amanone<3lolilol", b);
  ____

  c->append_c(c, "XPTDR");
  EXPECT("lolilolXPTDR", c);
  ____

  String *d = S("");
  d->append_c(d, "");
  EXPECT("", d);
  ____

  d->append_c(d, "beaume_b rox");
  EXPECT("beaume_b rox", d);
  ____

  printf("b\n%c\n", d->at(d, 0));
  ____

  printf("-1\n%d\n", d->at(S(""), 0));
  ____

  printf("-1\n%d\n", d->at(S("test"), -1));
  ____

  d->clear(d);
  EXPECT("", d);
  ____

  printf("0\n%d\n", d->size(d));
  ____

  printf("%d\n%d\n", (unsigned)strlen("amanone<3lolilol"), (unsigned)b->size(b));
  ____

  printf("0\n%d\n", b->compare_s(b, S("amanone<3lolilol")));
  ____

  printf("0\n%d\n", b->compare_c(b, "amanone<3lolilol"));
  ____

  printf("-1\n%d\n", b->compare_c(b, "amanone<3lolilom"));
  ____

  String *e = S("xxxamanone</3pointeurs");
  char y[50] = {0};

  e->copy(e, y, sizeof("amanone</3pointeurs"), 3);
  printf("amanone</3pointeurs\n%s\n", y);
  ____

  e->copy(e, y, 100000000, 3);
  printf("amanone</3pointeurs\n%s\n", y);
  ____

  bzero(y, 50);
  e->copy(e, y, 1, 0);
  printf("x\n%s\n", y);
  ____

  printf("-1\n%d\n", e->empty(e));
  ____

  printf("1\n%d\n", e->empty(S("")));
  ____

  printf("0\n%d\n", e->find_c(e, "x", 0));
  ____

  printf("0\n%d\n", e->find_c(e, "xx", 0));
  ____

  printf("1\n%d\n", e->find_c(e, "xxa", 0));
  ____

  printf("-1\n%d\n", e->find_c(e, "ahmedbougacha", 0));
  ____

  printf("-1\n%d\n", e->find_c(e, "xxx", 1));
  ____

  printf("-1\n%d\n", e->find_c(e, "s", 100000));
  ____

  printf("0\n%d\n", e->find_c(e, "", 0));
  ____

  printf("-1\n%d\n", e->find_c(e, "", 1000));
  ____

  String *f = S("abcdefghijk");
  String *tmp;

  tmp = f->substr(f, 4, 3);
  EXPECT("efg", tmp);
  StringDestroy(tmp);
  ____

  tmp = f->substr(f, -3, 10);
  EXPECT("ijk", tmp);
  StringDestroy(tmp);
  ____

  tmp = f->substr(f, -4, -5);
  EXPECT("defgh", tmp);
  StringDestroy(tmp);
  ____

  tmp = f->substr(f, 7, -3);
  EXPECT("fgh", tmp);
  StringDestroy(tmp);


  String *g = S("one-two-th_ree-four-_-");
  String *tab_s;
  char **tab_c;

  char *tab_ref_2[] =
  {
    "one-two-th",
    "ree-four-",
    "-",
  };
  tab_c = g->split_c(g, '_');
  for (i = 0; tab_c[i]; i++)
  {
    String el;
    StringInit(&el, tab_c[i]);
    ____

    EXPECT(tab_ref_2[i], &el);
  }

  tab_s = g->split_s(g, '_');
  for (i = 0; tab_s[i].empty(&tab_s[i]) != 1; i++)
  {
    ____

    EXPECT(tab_ref_2[i], &tab_s[i]);
  }

  char *tab_ref_1[] =
  {
    "one",
    "two",
    "th_ree",
    "four",
    "_",
  };



  tab_c = g->split_c(g, '-');
  for (i = 0; tab_c[i]; i++)
  {
    String el;
    StringInit(&el, tab_c[i]);
    ____

    EXPECT(tab_ref_1[i], &el);
  }

  tab_s = g->split_s(g, '-');
  for (i = 0; tab_s[i].empty(&tab_s[i]) != 1; i++)
  {
    ____

    EXPECT(tab_ref_1[i], &tab_s[i]);
  }

  String *h = S("this should never appear");
  ____

  h->join_c(h, '|', (const char **)tab_c);
  EXPECT("one|two|th_ree|four|_", h);

  ____

  h->join_s(h, '|', tab_s);
  EXPECT("one|two|th_ree|four|_", h);
  ____

  String *n = S("4242");
  printf("%d\n%d\n", 4242, n->to_int(n));
  ____

  String *j = S("0123456789");
  String *k = S("0123456789");
  j->insert_c(j, 6, "abcdefghijk");
  EXPECT("012345abcd", j);
  ____

  j->insert_c(j, 0, "abcdefghij");
  EXPECT("abcdefghij", j);
  ____

  k->insert_s(k, 6, j);
  EXPECT("012345abcd", k);

  return 0;
}
