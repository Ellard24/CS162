  /*
   2   * FibonacciClass1.cpp
   3   *
   4   *  Created on: Sep 10, 2010
   5   *      Author: julian
   6   */
   

#include <iostream>
#include "FibonacciR.h"
using namespace std;

FibonacciR::FibonacciR() {
	
}

FibonacciR::FibonacciR(const int &n) :n_(&n){
	
}

FibonacciR::~FibonacciR() {
	
}


int FibonacciR::Fibonacci(const int &n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
	
}


void FibonacciR::PrintFibonacci(){
	int FibonaciNum = Fibonacci(*n_);
	//cout << *n_ << "th fibonaci number: " << FibonaciNum << endl;
	
}