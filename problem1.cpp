/*
// Time Complexity : O(N)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach
Each substring in the target would occur atleast once in order of the source target until source is finished
So if the subset is not found then we can say that the element doesnt occur in the set and return -1;
*/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
    const int arr_size{26};
public:
    int shortestWay(string source, string target) {
        //base condition check if they contain same set of characters.
        // i.e subset of characters in target occur in source
        // if (target == "") return 1;
        // vector<bool> src(arr_size,false);
        // vector<bool> trg(arr_size,false);
        // for(const char c:source){
        //     src.at(c-'a') = true;
        // }
        // for(const char c:target){
        //     if(src.at(c-'a') == false) return -1;
        // }
        int res{};
        //loop through the string and loop through the source string
        int src_size = source.size();
        int trg_size = target.size();
        for(int i{};i<trg_size;){
            int temp{};
            for(int j{};j<src_size && i<trg_size;++j){
                if(source.at(j) == target.at(i)){
                    temp++;
                    i++;
                }
            }
            if(temp>0){
                res++;
            }
            else{
                return -1;
            }
        }
        return res;
        
    }
};