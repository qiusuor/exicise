#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <random>
#include <boost/lexical_cast.hpp>  
#include<time.h> 

using namespace std;
using namespace boost;

class lab4 {
public:
	void generateRecordFile() {
		std::default_random_engine random(time(NULL));
		std::uniform_int_distribution<int> dis1(0, INT_MAX);
		std::ofstream fout("record.dat", std::ios::binary);
		int nNum = 20;

		set<int> appear;
		std::string str("Hello world!");
		for (int i = 0; i < 1000000; ) {
			nNum = dis1(random);
			if (!appear.count(nNum)) {
				fout.write((char*)&nNum, sizeof(int));
				fout.write(str.c_str(), sizeof(char) * (str.size()));
				i++;
			}
		}
		fout.close();
	}
	void mySort() {
		std::ifstream fin("record.dat", std::ios::binary);
		for (int i = 0; i < 15; i++)
			sortOneBlock(fin, i, 65536);
		sortOneBlock(fin, 15, 16960);
		fin.close();

		std::ifstream fin_15("set_15", std::ios::binary);
		std::ifstream fin_14("set_14", std::ios::binary);
		std::ifstream fin_13("set_13", std::ios::binary);
		std::ifstream fin_12("set_12", std::ios::binary);
		std::ifstream fin_11("set_11", std::ios::binary);
		std::ifstream fin_10("set_10", std::ios::binary);
		std::ifstream fin_9("set_9", std::ios::binary);
		std::ifstream fin_8("set_8", std::ios::binary);
		std::ifstream fin_7("set_7", std::ios::binary);
		std::ifstream fin_6("set_6", std::ios::binary);
		std::ifstream fin_5("set_5", std::ios::binary);
		std::ifstream fin_4("set_4", std::ios::binary);
		std::ifstream fin_3("set_3", std::ios::binary);
		std::ifstream fin_2("set_2", std::ios::binary);
		std::ifstream fin_1("set_1", std::ios::binary);
		
		std::ofstream fout_13_14_15("set_13_14_15", std::ios::binary);
		mergeSort(fin_15, fin_14, fin_13,fout_13_14_15);
		fout_13_14_15.close();
		fin_13.close();
		fin_14.close();
		fin_15.close();

		std::ofstream fout_10_11_12("set_10_11_12", std::ios::binary);
		mergeSort(fin_10, fin_11, fin_12, fout_10_11_12);
		fout_10_11_12.close();
		fin_10.close();
		fin_11.close();
		fin_12.close();

		std::ofstream fout_7_8_9("set_7_8_9", std::ios::binary);
		mergeSort(fin_7, fin_8, fin_9, fout_7_8_9);
		fout_7_8_9.close();
		fin_7.close();
		fin_8.close();
		fin_9.close();


		std::ofstream fout_4_5_6("set_4_5_6", std::ios::binary);
		mergeSort(fin_4, fin_5, fin_6, fout_4_5_6);
		fout_4_5_6.close();
		fin_4.close();
		fin_5.close();
		fin_6.close();

		std::ofstream fout_1_2_3("set_1_2_3", std::ios::binary);
		mergeSort(fin_1, fin_2, fin_3, fout_1_2_3);
		fout_1_2_3.close();
		fin_1.close();
		fin_2.close();
		fin_3.close();


		std::ifstream fin_1_2_3("set_1_2_3", std::ios::binary);
		std::ifstream fin_4_5_6("set_4_5_6", std::ios::binary);
		std::ifstream fin_0("set_0", std::ios::binary);
		std::ofstream fout_0_1_2_3_4_5_6("set_0_1_2_3_4_5_6", std::ios::binary);
		mergeSort(fin_1_2_3, fin_4_5_6, fin_0, fout_0_1_2_3_4_5_6);
		fout_0_1_2_3_4_5_6.close();
		fin_1_2_3.close();
		fin_4_5_6.close();
		fin_0.close();

		std::ifstream fin_13_14_15("set_13_14_15", std::ios::binary);
		std::ifstream fin_10_11_12("set_10_11_12", std::ios::binary);
		
		std::ofstream fout_10_11_12_13_14_15("set_10_11_12_13_14_15", std::ios::binary);
		mergeSort2(fin_13_14_15, fin_10_11_12, fout_10_11_12_13_14_15);
		fout_10_11_12_13_14_15.close();
		fin_13_14_15.close();
		fin_10_11_12.close();

		std::ifstream fin_10_11_12_13_14_15("set_10_11_12_13_14_15", std::ios::binary);
		std::ifstream fin_0_1_2_3_4_5_6("set_0_1_2_3_4_5_6", std::ios::binary);
		std::ifstream fin_7_8_9("set_7_8_9", std::ios::binary);
		std::ofstream fout_0_1_2_3_4_5_6_7_8_9_10_11_12_13_14_15("set_0_1_2_3_4_5_6_7_8_9_10_11_12_13_14_15", std::ios::binary);
		mergeSort(fin_10_11_12_13_14_15, fin_0_1_2_3_4_5_6, fin_7_8_9, fout_0_1_2_3_4_5_6_7_8_9_10_11_12_13_14_15);
		fout_0_1_2_3_4_5_6_7_8_9_10_11_12_13_14_15.close();
		fin_10_11_12_13_14_15.close();
		fin_0_1_2_3_4_5_6.close();
		fin_7_8_9.close();

	}
protected:
	
	void sortOneBlock(std::ifstream &fin, int i,int size) {
		vector<item> oneSet(size);
		readBlock(fin, oneSet, size);
		/*for (int i = 0; i < size; i++) {
			fin.read((char*)&oneSet[i].seq, sizeof(int));

			fin.read(oneSet[i].data, sizeof(char) * 12);

		}*/
		sort(oneSet.begin(), oneSet.end(), cmp);
		string fileName = "set_" + lexical_cast<string>(i);
		std::ofstream fout(fileName, std::ios::binary);
		writeBlock(fout, oneSet, size);
		/*for (int i = 0; i < size; i++) {
			fout.write((char*)&oneSet[i].seq, sizeof(int));
			fout.write(oneSet[i].data, sizeof(char) * (12));
		}*/
		fout.close();


	}
	void mergeSort(std::ifstream &fin1, std::ifstream &fin2, std::ifstream &fin3, std::ofstream &fout) {
		vector<item> outPutBlock(16384);
		vector<item> inPutBlock0(16384);
		vector<item> inPutBlock1(16384);
		vector<item> inPutBlock2(16384);

		int size1=readBlock(fin1, inPutBlock0, 16384);
		int size2 = readBlock(fin2, inPutBlock1, 16384);
		int size3 = readBlock(fin3, inPutBlock2, 16384);

		int i = 0;
		int j = 0;
		int k = 0;
		int count = 0;
		while (i<size1 || j<size2 || k<size3)
		{
			int tmp = INT_MAX;
			int valid = -1;
			if (i < size1) {
				tmp = inPutBlock0[i].seq;
				valid = 0;
			}
			if (j < size2 && tmp >= inPutBlock1[j].seq) {
				tmp = inPutBlock1[j].seq;
				valid = 1;
			}
			if (k < size3 && tmp >= inPutBlock2[k].seq) {
				tmp = inPutBlock2[k].seq;
				valid = 2;
			}

			if (valid == 0) {
				outPutBlock[count] = inPutBlock0[i++];
				if (i == size1) {
					size1 = readBlock(fin1, inPutBlock0, 16384);
					i = 0;
				}
			}
			else if (valid == 1) {
				outPutBlock[count] = inPutBlock1[j++];
				if (j == size2) {
					size2 = readBlock(fin2, inPutBlock1, 16384);
					j = 0;
				}
			}		
			else if (valid == 2) {
				outPutBlock[count] = inPutBlock2[k++];
				if (k == size3) {
					size3 = readBlock(fin3, inPutBlock2, 16384);
					k = 0;
				}
			}
			if (valid == -1)
				break;

			if (++count >= 16384) {
				writeBlock(fout, outPutBlock, 16384);
				count = 0;
			}

			
		}
		if (count > 0)
			writeBlock(fout, outPutBlock, count);
	}

	void mergeSort2(std::ifstream &fin1, std::ifstream &fin2, std::ofstream &fout) {
		vector<item> outPutBlock(16384);
		vector<item> inPutBlock0(16384);
		vector<item> inPutBlock1(16384);


		int size1 = readBlock(fin1, inPutBlock0, 16384);
		int size2 = readBlock(fin2, inPutBlock1, 16384);


		int i = 0;
		int j = 0;
		int k = 0;
		int count = 0;
		while (i < size1 || j < size2 )
		{
			int tmp = INT_MAX;
			int valid = -1;
			if (i < size1) {
				tmp = inPutBlock0[i].seq;
				valid = 0;
			}
			if (j < size2 && tmp >= inPutBlock1[j].seq) {
				tmp = inPutBlock1[j].seq;
				valid = 1;
			}
			

			if (valid == 0) {
				outPutBlock[count] = inPutBlock0[i++];
				if (i == size1) {
					size1 = readBlock(fin1, inPutBlock0, 16384);
					i = 0;
				}
			}
			else if (valid == 1) {
				outPutBlock[count] = inPutBlock1[j++];
				if (j == size2) {
					size2 = readBlock(fin2, inPutBlock1, 16384);
					j = 0;
				}
			}
			
			if (valid == -1)
				break;

			if (++count >= 16384) {
				writeBlock(fout, outPutBlock, 16384);
				count = 0;
			}


		}
		if (count > 0)
			writeBlock(fout, outPutBlock, count);
	}
	struct item
	{
		int seq;
		char data[13]{0};
	};
	static bool cmp(const item a, const item b) {
		return a.seq < b.seq;
	}
	int readBlock(std::ifstream &fin, vector<lab4::item> &oneBlock, int size) {
		int i = 0;
		for (; i < size; i++) {
			fin.read((char*)&oneBlock[i].seq, sizeof(int));
			if (!fin)
				break;
			fin.read(oneBlock[i].data, sizeof(char) * 12);
			
		}
		return i<size?i:size;
	}
	int writeBlock(std::ofstream &fout, vector<lab4::item> &oneBlock, int size) {
		for (int i = 0; i < size; i++) {
			fout.write((char*)&oneBlock[i].seq, sizeof(int));
			fout.write(oneBlock[i].data, sizeof(char) * (12));
		}
		return size;
	}
private:
};

static	int DEBUG = 0;

class Btree
{
public:
	Btree(int m,string recoredFileName);
	~Btree();
	
	struct BTreeNode
	{
		int fatherIndex;
		int count;
		int key[510]{ -1 };
		int childIndex[511]{ -1 };
		int isLeafNode;
		BTreeNode(int newKey,int index) {
			childIndex[0] = index;
			key[0] = newKey;
			fatherIndex = -1;  
			count = 1; //键数目
			isLeafNode = true;
		}
	};
	void readPage(std::ifstream &fin, BTreeNode &page) {
		fin.read((char*)&page.fatherIndex, sizeof(int));
		fin.read((char*)&page.count, sizeof(int));
		
		for (int i = 0; i < 510; i++) {
			fin.read((char*)&page.key[i], sizeof(int));
		}
		for (int i = 0; i < 511; i++) {
			fin.read((char*)&page.childIndex[i], sizeof(int));
		}
		fin.read((char*)&page.isLeafNode, sizeof(int));
	}
	void writePage(std::ofstream &fout, BTreeNode &page) {
		fout.write((char*)&page.fatherIndex, sizeof(int));
		fout.write((char*)&page.count, sizeof(int));
		for (int i = 0; i < 510; i++) {
			fout.write((char*)&page.key[i], sizeof(int));
		}
		for (int i = 0; i < 511; i++) {
			fout.write((char*)&page.childIndex[i], sizeof(int));
		}
		fout.write((char*)&page.isLeafNode, sizeof(int));
	}
	int writeToRecordFile(int key, string value) {
		ofstream recordFile("index\\recordBtree", ios::binary|ios::app);

		recordFile.seekp(0, recordFile.end);
		int length = recordFile.tellp();
		recordFile.write((char*)&key, sizeof(int));
		recordFile.write((char*)&value, 8);
		recordFile.close();
		return length;
	}

	int adaptForInsert(BTreeNode &cur, int key, int index,int curFileIndex,int recurCurFileIndex) {
		if (cur.count < max) {//插入不分裂
			/*cur.key[cur.count] = key;
			cur.childIndex[cur.count] = index;*/
			cur.count++;
			//int firstFlag=t
			for (int i = cur.count - 2; i >= 0;i--) {
				int j = i;
				if (!cur.isLeafNode)
					j++;
				if (cur.key[i] > key) {
					cur.key[i + 1] = cur.key[i];
					cur.childIndex[j + 1] = cur.childIndex[i];
				}
				else {
					cur.key[i + 1] = key;
					cur.childIndex[j + 1] = index;
					break;
				}
			}
			std::ofstream curPage("index\\"+lexical_cast<string>(curFileIndex), std::ios::binary);
			writePage(curPage, cur);
			curPage.close();
		}
		else {// 需要分裂,
			if (cur.fatherIndex == -1) {//如果父节点为空,分裂,更新根节点
	
				std::ofstream newPage("index\\" + lexical_cast<string>(++count), std::ios::binary);
				
				BTreeNode nPage(0,0);
			
				for (int i = cur.count - 2; i >= 0; i--) {
					int j = i;
					if (!cur.isLeafNode)
						j++;
					if (cur.key[i] > key) {
						cur.key[i + 1] = cur.key[i];
						cur.childIndex[j + 1] = cur.childIndex[i];
					}
					else {
						cur.key[i + 1] = key;
						cur.childIndex[j + 1] = index;
						break;
					}
				}
				
				memcpy(nPage.key, cur.key + sidx , (cur.count - sidx+1) * sizeof(int));
				memcpy(nPage.childIndex, cur.childIndex + sidx , (cur.count - sidx+2) * sizeof(int));
				nPage.count = cur.count - sidx+1;
				cur.count = sidx;
				if (recurCurFileIndex != -1) {
					cur.key[cur.count - 2] = cur.key[cur.count - 1];
					cur.childIndex[cur.count - 1] = cur.childIndex[cur.count];
					cur.count--;
				}
				
				
				std::ofstream newRootPage("index\\" + lexical_cast<string>(++count), std::ios::binary);

				BTreeNode nRoot(nPage.key[0],root);
				nRoot.childIndex[1] = count - 1;
				nRoot.isLeafNode = false;
				root = count;
				cur.fatherIndex = count;
				nPage.fatherIndex = count ;

				writePage(newRootPage, nRoot);
				writePage(newPage, nPage);
				newPage.close();
				newRootPage.close();

				int iindex=curFileIndex;
				/*if (recurCurFileIndex != -1)
					iindex = recurCurFileIndex;*/
		
				std::ofstream curPage("index\\" + lexical_cast<string>(iindex), std::ios::binary);
				writePage(curPage, cur);
				curPage.close();
			}
			else {//分裂,然后把溢出键和索引传递到上层节点
				std::ofstream newPage("index\\" + lexical_cast<string>(++count), std::ios::binary);
				BTreeNode nPage(0, 0);
				for (int i = cur.count - 1; i >= 0; i--) {
					if (cur.key[i] > key) {
						cur.key[i + 1] = cur.key[i];
						cur.childIndex[i + 1] = cur.childIndex[i];
					}
					else {
						cur.key[i + 1] = key;
						cur.childIndex[i + 1] = index;
						break;
					}
				}
				memcpy(nPage.key, cur.key + sidx, (cur.count - sidx + 1) * sizeof(int));
				memcpy(nPage.childIndex, cur.childIndex + sidx, (cur.count - sidx + 2) * sizeof(int));
				nPage.count = cur.count - sidx + 1;
				cur.count = sidx;
				nPage.fatherIndex = cur.fatherIndex;

				writePage(newPage, nPage);
				newPage.close();

				std::ofstream curPage("index\\" + lexical_cast<string>(curFileIndex), std::ios::binary);
				writePage(curPage, cur);
				curPage.close();

				int nKey = nPage.key[0];
				int fIndex = cur.fatherIndex;
				std::ifstream fPage("index\\" + lexical_cast<string>(fIndex), std::ios::binary);
				readPage(fPage, cur);				

				adaptForInsert(cur, nKey, count,fIndex,curFileIndex);
			}

		}
		return 0;

	}
	int insertInfo(int key,string value) {
		int index = writeToRecordFile(key, value);
		if (root == -1) {
			root = 0;
			//this->pageNum++;
			this->count++;
			BTreeNode r(key,index);

			std::ofstream rootIndex("index\\" + lexical_cast<string>(root), std::ios::binary);
			writePage(rootIndex, r);
			return 0;
		}

		std::ifstream rootIndex("index\\" + lexical_cast<string>(root), std::ios::binary);

		int preIndexFile = root;

		BTreeNode  cur(0,0);
		
		readPage(rootIndex, cur);
		rootIndex.close();
		while (!cur.isLeafNode)
		{
			bool inFlag = false;
			for (int i = 0; i < cur.count; i++) {
				if (cur.key[i] > key)
				{

					rootIndex.open("index\\" + lexical_cast<string>(cur.childIndex[i]), std::ios::binary);
					preIndexFile = cur.childIndex[i];
					readPage(rootIndex, cur);
					inFlag = true;
					break;
				}
			}
			if (!inFlag) {

				rootIndex.open("index\\" + lexical_cast<string>(cur.childIndex[cur.count]), std::ios::binary);
				preIndexFile = cur.childIndex[cur.count];
				readPage(rootIndex, cur);
				rootIndex.close();
			}
		}
		/*for (int i = 0; i < cur.count; i++) {
			if (cur.key[i] == key) {
				return -1;
			}
		}*/
		return adaptForInsert(cur, key, index,preIndexFile,-1);
	}
	int searchByKey(int key) {  //成功返回文件块号，失败返回-1
		if (this->root == -1)
			return -1;
		std::ifstream rootIndex("index\\" + lexical_cast<string>(root), std::ios::binary);

		//int preIndexFile = 0;
	
		BTreeNode  cur(0,0);
		readPage(rootIndex, cur);
		while (!cur.isLeafNode)
		{
			bool inFlag = false;
			for (int i = 0; i < cur.count; i++) {
				if (cur.key[i] > key)
				{
					rootIndex.close();
					rootIndex.open("index\\" + lexical_cast<string>(cur.childIndex[i]), std::ios::binary);
					//preIndexFile = cur.childIndex[i];
					readPage(rootIndex, cur);
					inFlag = true;
					break;
				}
			}
			if (!inFlag) {
				rootIndex.close();
				rootIndex.open("index\\" + lexical_cast<string>(cur.childIndex[cur.count]), std::ios::binary);
				//preIndexFile = cur.childIndex[cur.count];
				readPage(rootIndex, cur);
			}
		}
		for (int i = 0; i < cur.count; i++) {
			if (cur.key[i] == key) {
				return cur.childIndex[i];
			}
		}
		
		return -1;
	}
	int builtIndex() {
		std::ifstream fin(recoredFileName,std::ios::binary);
		int key;
		char value[12];

		int i_debug = 0;
		/*vector<int> keys;
		vector<string> values;*/
	
		while(true) {
			fin.read((char*)&key, sizeof(int));
			if (!fin)
				break;
			fin.read(value, sizeof(char) * 12);
			//insertInfo(key, value);
			//cout << i_debug++ << endl;;
			insertInfo(key, value);
			/*if (i_debug++ == 499) {
				BTreeNode t(0, 0);
				std::ifstream fining("0", std::ios::binary);
				readPage(fining, t);
				t = t;
			}*/
			//cout << i_debug++ << endl;

			
		}
		/*for (int i = 0; i < keys.size(); i++) {
			insertInfo(keys[i], values[i]);
			if (i == 499) {
				BTreeNode t(0, 0);
				std::ifstream fining("0", std::ios::binary);
				readPage(fining,t);
				t = t;
			}
			cout << i << endl;
		}*/
		return 0;
	}
	void test() {
		//BTreeNode t;

		BTreeNode t(1,1);
		t.count = 1;
		ofstream ou("11", ios::binary);
		writePage(ou, t);
		ou.close();
		t.count = 0;
		ifstream in("11", ios::binary);
		readPage(in, t);
		t = t;
	}





	
protected:
	
private:
	int max;
	int min;
	int sidx;
	int root;
	int count;
	//map<int, vector<int>> graph;
	//int pageNum;
	string recoredFileName;
};

Btree::Btree(int m, string recoredFileName)
{
	this->recoredFileName = recoredFileName;
	//this->pageNum = 0;
	this->max = m -1;
	this->min = m / 2;
	this->count = -1;
	if (m % 2 == 0)
		this->min--;
	this->sidx = m / 2;
	this->root = -1; /* 空树 */
}

Btree::~Btree()
{
}