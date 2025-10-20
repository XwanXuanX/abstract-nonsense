#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */
// Definition for Employee.
class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};

// @lc code=start
class Solution {
public:
  unordered_map<int,int> idmp;

  int dfs(int nodeId, vector<Employee*> employees) {
    int idx = idmp[nodeId];
    auto emp = *employees[idx];
    if (emp.subordinates.empty()) {
      return emp.importance;
    }
    int total = 0;
    for (int i = 0; i < emp.subordinates.size(); ++i) {
      total += dfs(emp.subordinates[i], employees);
    }
    return total + emp.importance;
  }

  int getImportance(vector<Employee*> employees, int id) {
    for (int i = 0; i < employees.size(); ++i) {
      idmp[employees[i]->id] = i;
    }
    return dfs(id, employees);
  }
};
// @lc code=end

