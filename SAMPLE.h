#pragma once
#include "R32M.h"
#include "PROBDIST.h"
class SAMPLE
{
public:
	SAMPLE() {};
	virtual ~SAMPLE() {};
	virtual int* simulate(int a, int b, int k, int n) = 0;
};

class HGB :
	public SAMPLE
{
public:
	HGB(){};
	~HGB() override {};
	int* simulate(int a, int b, int k, int N) override {
		int* s = new int[N];
		for (int i = 0; i < N; ++i) {
			s[i] = sHGB(a, b, k);
		}
		return s;
	};

	int sHGB(int a, int b, int k) {
		int j = 0;
		int n = a + b;
		for (int i = 0; i < k; ++i) {
			double alpha = rnunif();
			if (alpha < double((a - j)) / (n - i)) ++j;
		}
		return j;
	}
};


