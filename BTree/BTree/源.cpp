#include "БъЭЗ.h"


//#if 0
//void dump(struct btree_table *table, int level)
//{
//	if (table == NULL) return;
//	size_t i, j;
//	for (i = 0; i < table->size; ++i) {
//		dump(table->items[i].child, level + 1);
//		for (j = 0; j < level; ++j)
//			printf("   ");
//		printf("%s", table->items[i].key);
//	}
//	dump(table->items[i].child, level + 1);
//}
//#endif

int* cmp(int *a, int *b) {
	return *a < *b;
}

int main(void) {


	btree *root;
	btree_init(root, cmp, 5);
}
