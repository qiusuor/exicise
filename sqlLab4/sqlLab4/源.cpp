#include "БъЭЗ.h"

int main(void) {
	

	clock_t startTime, endTime;
	startTime = clock();
	lab4 lab;
	lab.generateRecordFile();
	lab.mySort();
	endTime = clock();
	cout << endTime - startTime+123212;

	//btree_t *root = NULL;
	//btree_creat(&root, 4);
	//root = root;

	//Btree b(511);
	//std::ofstream fout("index\\0", ios::binary);
	//int page[1024];
	//for (int i = 0; i < 1024; i++) {
	//	page[i] = i;
	//}
	//b.writePage(fout, page);
	//fout.close();
	//std::ifstream fin("index\\0", ios::binary);
	//int page2[1024];
	//b.readPage(fin, page2);
	//fin.close();

	//std::ifstream rootIndex("root", std::ios::binary);
	//rootIndex.close();
	//rootIndex.open("SKF", std::ios::binary);
	//Btree b(511, "set_0");
	/*Btree b(511, "set_0_1_2_3_4_5_6_7_8_9_10_11_12_13_14_15");

	b.writeToRecordFile(0, 8);*/

	Btree b(510, "set_0_1_2_3_4_5_6_7_8_9_10_11_12_13_14_15");
	//b.test();
	b.builtIndex();
	system("pause");
}