class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string st : strs){
            s += to_string(st.size()) + "#" + st; 
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string> res; 
        int i = 0; 
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            string len = s.substr(i, j);
            int sz = stoi(len);
            res.push_back(s.substr(j+1, sz));
            i = sz + j + 1;
        }
        return res;
    }
};
