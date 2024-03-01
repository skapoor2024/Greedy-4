/*
// Time Complexity : O(N)
// Space Complexity : O(N )
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    void display(vector<int>& vec){
        for(auto const& v:vec){
            cout<<v<<" ";
        }
        cout<<endl;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //frist check most frequeny number in both , check if they match 
        //then check each row has that number
        int sz = tops.size();
        vector<int> tarr(6,0);
        vector<int> barr(6,0);
        for(int i{};i<sz;++i){
            tarr.at(tops.at(i)-1)++;
            barr.at(bottoms.at(i)-1)++;
        }
        //display(tarr);
        //display(barr);
        vector<int> potential{};
        //atleast two pair must sum greater than equal to sz finding such potential
        for(int i{};i<6;++i){
            if(tarr.at(i)+barr.at(i)>=sz){
                potential.push_back(i);
            }
        }
        if(potential.size() == 0) return -1;
        //display(potential);
        int res{INT_MAX};

        //here we will work with the frequency of number 0 to 5 (1 to 6) to address the problem.
        for(const auto v:potential){
            //cout<<tarr.at(v)<<" "<<barr.at(v)<<endl;
            int temp{};
            bool flag = tarr.at(v)>=barr.at(v);//flag for which has higher number towards so that switch will be made from another end
            int min_switch = abs(max(tarr.at(v),barr.at(v))-sz); //minimum number of switches required. 
            //cout<<min_switch<<endl;
            for(int i{};i<sz;++i){
                
                // either of them should be equal to the potential number
                // and the number are not equal we need a switch
                if( (tops.at(i) == v+1 || bottoms.at(i) == v+1) && tops.at(i)!= bottoms.at(i)){
                    // if top has more number and bottom has the number increment
                    if(flag && bottoms.at(i) == v+1){
                        temp++;
                    }
                    // if bottom has more number  and top has number increment
                    else if(!flag && tops.at(i) == v+1){
                        temp++;
                    }
                }
            }
            //only if switches are more than the minimum required
            if(temp>=min_switch){
                res = min(res,temp);
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};