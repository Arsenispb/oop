#pragma once
class DIST
{
protected:
	int a_, b_, k_;
public:
    DIST(int a, int b, int k) : a_(a), b_(b), k_(k) {};
    ~DIST(){};
    int get_a() { return a_; };
    int get_b() { return b_; };
    int get_k() { return k_; };
    double* th_HG(int a, int b, int k, int N) {
        double* th = new double[k + 1];
        double p = 1;
        for (int j = 0; j < k; ++j) {
            p *= double((b - k + 1 + j)) / (a + b - k + 1 + j);
        }
        th[0] = N * p;

        for (int i = 0; i < k - 1; ++i) {
            p *= double((a - i)) / (i + 1) * double((k - i)) / (b - k + i + 1);
            th[i + 1] = N * p;
        }
        th[k] = N * p * double((a - k + 1)) / k / b;
        return th;
    }
};

