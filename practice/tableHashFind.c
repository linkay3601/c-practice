/**
 * 线性表散列查找
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

char *strdUp(char *);
unsigned hash(char *s);

struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);


int main()
{
    struct nlist *np;

    char *key = "name";
    char *value = "linkay";

    install(key, value);
    np = lookup(key);
    printf("the value is: %s\n", np->defn);
}


/* 对字符串求一个 Hash 值*/
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}


/* 对指定的 key 进行散列表查找 */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}


/* 更新或插入指定 key 的值 */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdUp(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdUp(defn)) == NULL)
        return NULL;
    return np;
}


/* 字符串复制 */
char *strdUp(char *s)
{
	char *p;
	
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}
