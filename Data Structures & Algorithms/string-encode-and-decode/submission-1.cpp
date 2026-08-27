class Solution {
    vector<int> arr;
    string total =""; 
public:
    string encode(vector<string>& strs) {
        for(string s : strs){
            total += s;
            arr.push_back(s.size()); 
        }
        return total;
    }

    vector<string> decode(string total) {
        vector<string> res; 
        int start = 0;
        for(int i : arr){
            res.push_back(total.substr(start, i));
            start += i;
        }
        return res;
    }
};
