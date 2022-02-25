#pragma once
#include "DIST.h"
#include "SAMPLE.h"
class HI_SQUARE
{
protected:
	int* c_;
    int fr_deg_;
    double stat_;
    double p_val_;
public:
	HI_SQUARE(DIST *d, SAMPLE *S, int N):stat_(0) {
		c_ = new int[d->get_k() + 1]{};
		for (int i = 0; i < N; ++i) {
			++c_[S->simulate(d->get_a(), d->get_b(), d->get_k(), N)[i]];
		}
	};
    virtual ~HI_SQUARE() {delete[] c_; };
    int* get_c() { return c_; };

    void hi_sq(double* th, int k) {
        double* c_m = new double[k + 1]{};
        double* th_m = new double[k + 1]{};
        double c_s = 0, th_s = 0;
        int i = 0, j = 0;
        while (j < k + 1) {
            while (j < k + 1 && (c_s < 5 || th_s < 5)) {
                c_s += c_[j];
                th_s += th[j];
                ++j;
            }
            c_m[i] = c_s;
            th_m[i] = th_s;
            c_s = 0;
            th_s = 0;
            ++i;
        }
        if (c_m[i - 1] < 5 || th_m[i - 1] < 5) {
            --i;
            c_m[i - 1] += c_m[i];
            th_m[i - 1] += th_m[i];
        }
        /*
        for (int m = 0; m < i; ++m) {
            printf("%f \n", c_m[m]);
        }
        */
        for (int k = 0; k < i; ++k) {
            stat_ += (th_m[k] - c_m[k]) * (th_m[k] - c_m[k]) / c_m[k];
        }
        fr_deg_ = i - 1;
        p_val_ = 1 - pChi(stat_, fr_deg_);
    }
};

