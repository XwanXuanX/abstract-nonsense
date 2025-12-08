#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class ProductOfNumbers {
public:
    using ll = long long;
    vector<ll> pfs;
    int size = 0;

    ProductOfNumbers() {
        pfs.push_back(1), size = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            pfs = {1}, size = 0;
        } else {
            pfs.push_back(pfs.back() * num), size++;
        }
    }
    
    int getProduct(int k) {
        if (k > size)
            return 0;
        return pfs.back() / pfs[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * ll param_2 = obj->getProduct(k);
 */
//IMPORTANT!! Submit Code Region End(Do not remove this line)