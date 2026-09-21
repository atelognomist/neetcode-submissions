class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for (string& s : strs) {
            for (char c : s) {
                int x = (unsigned char)c;

                if (x < 10)
                    encoded += "00" + to_string(x);
                else if (x < 100)
                    encoded += "0" + to_string(x);
                else
                    encoded += to_string(x);
            }

            encoded += "256"; // end of string
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string current;

        for (int i = 0; i < s.size(); i += 3) {
            int x = stoi(s.substr(i, 3));

            if (x == 256) {
                result.push_back(current);
                current.clear();
            } else {
                current += char(x);
            }
        }

        return result;
    }
};