#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
class FoodRatings {
public:
  struct comp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
      if (a.first != b.first)
        return a.first > b.first;
      return a.second < b.second;
    }
  };

  map<string, set<pair<int,string>, comp>> mpq;
  map<string, string> foodMp;
  map<string, int> ratingMp;

  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = foods.size();
    for (int i = 0; i < n; ++i) {
      mpq[cuisines[i]].insert(make_pair(ratings[i], foods[i]));
    }
    for (int i = 0; i < n; ++i) {
      foodMp[foods[i]] = cuisines[i];
      ratingMp[foods[i]] = ratings[i];
    }
  }
  
  void changeRating(string food, int newRating) {
    auto& pq = mpq[foodMp[food]];
    auto nh = pq.extract(make_pair(ratingMp[food], food));
    nh.value().first = newRating;
    pq.insert(std::move(nh));
    ratingMp[food] = newRating;
  }
  
  string highestRated(string cuisine) {
    auto& pq = mpq[cuisine];
    return pq.begin()->second;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end

