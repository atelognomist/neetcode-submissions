class Solution {
public:
    bool isAnagram(string s, string t) {

        // this solution time complexity is O(m + n) and space complexity is also O(m + n) 

        // unordered_map<char , int> mp1;
        // unordered_map<char , int> mp2;

        // for(auto &c : s){
        //     mp1[c]++;
        // }

        // for(auto &c : t){
        //     mp2[c]++;
        // }
        
        // bool ans1 = true;

        // for(auto &m : mp1){
        //     if(mp2[m.first] != m.second){
        //         ans1 = false;
        //     }
        // }

        // bool ans2 = true;

        // for(auto &m : mp2){
        //     if(mp1[m.first] != m.second){
        //         ans2 = false;
        //     }
        // }

        // if(ans1 && ans2) return true;

        // return false;

        // can we optimise 
        // yes how? by reducing space 


        // unordered_map<char , int> mp;
        // for(auto &c : s){
        //     mp[c]++;
        // }

        // for(auto &c : t){
        //     mp[c]--;
        // }

        // for(auto &m : mp){
        //     if(m.second != 0) return false;
        // }

        // return true;

        // if lowercase letters only

        vector<int> freq(26 , 0);
        for(auto &c : s){
            freq[c - 'a']++;
        }
        for(auto &c : t){
            freq[c - 'a']--;
        }
        for(auto &f : freq){
            if(f != 0) return false;
        }
        return true;
    }
};
