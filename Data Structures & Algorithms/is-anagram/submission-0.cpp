class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        for (char cs : s) {
            bool found = false;

            for (int i = 0; i < t.size(); i++) {
                if (t[i] == cs) {
                    t.erase(i, 1);
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }
};