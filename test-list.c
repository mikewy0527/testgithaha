#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct pool_t {
	struct list_head list;
	int num;
} pool_t;

pool_t pl;

int main()
{
	INIT_LIST_HEAD(&pl.list);
	pool_t *node = (pool_t *)malloc(sizeof(pool_t));
	node->num = 10;
	list_add_tail(&node->list, &pl.list);

	struct list_head *pos, *q;
	pool_t *e;
	list_for_each_safe(pos, q, &pl.list) {
		e = list_entry(pos, pool_t, list);
		printf("%d\n", e->num);
		list_del(&e->list);
	}

	return 0;
}
