/*
Rafid Mirza
rm2jgk
10/19/21
hashTable.h
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

#include <string>
using namespace std;

class hashTable {
public:
	vector<list<string> > vec;
	unsigned int powers [22] = {1};
	int size = 0;

    hashTable(){
    	vec.resize(size);
    	unsigned int x = 1;
    	for (int i =1; i < 22; i++){
			x *= 37U;
			powers[i] = x;

	}
    	
    }           
	void insert(string s);
	bool find(string s);
	unsigned int newHash(string s);
	bool checkprime(unsigned int p);
	int getNextPrime(unsigned int n);
	void newSize(unsigned int o);

};

#endif
