#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Cashier {
public:
    int nth = 0, ith = 0, disc = 0;
    unordered_map<int, int> prs;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        nth = n, ith = 0, disc = discount;
        for (int i = 0; i < products.size(); ++i) {
            prs[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double tot = 0;
        for (int i = 0; i < product.size(); ++i) {
            tot += prs[product[i]] * amount[i];
        }
        ith++;
        if (ith == nth) {
            ith = 0;
            return tot * ((100 - disc) / 100);
        }
        return tot;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
//IMPORTANT!! Submit Code Region End(Do not remove this line)