#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std; 

class Solution{
public: 
      vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end()); 
        vector<vector<int>> res; 
        for(auto vec:intervals){
          if(res.empty() || res.back()[1]<vec[0]) res.push_back(vec); 
          else res.back()[1] = max(res.back()[1], vec[1]); 
        }
        return res; 
      }
};
int main(){
  vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
  Solution sol; 
  vector<vector<int>> res = sol.mergeInterval(intervals); 
  cout << "["; 
  for(auto vec:res){
    cout << "[" ;
    cout << vec[0] << "," << vec[1] << "],";
  }
  cout << "]" << endl; 
  return 0; 
}
