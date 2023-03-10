/*
Rafid Mirza
rm2jgk
10/19/21
hashTable.cpp
*/

#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

#include <string>

using namespace std;




unsigned int hashTable::newHash(string s){
	int sum = 0;
	for (int i = 0; i <  s.length(); i++){
		sum += s[i] * powers[i];
	}
	return (sum);
}

void hashTable::insert(string s){
	vec[newHash(s)%size].push_back(s);

}

bool hashTable::find(string s){
	for (string r: vec[newHash(s)%size]){
		if (s==r)
			return true;
	}

return false;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

void hashTable::newSize(unsigned int o){
	vec.resize(getNextPrime(o));
	size = vec.size();
}





