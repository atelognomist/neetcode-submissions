class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (string& s : strs) {
            int n = s.size();

            // Store length first
            result += to_string(n) + '#';

            // Even positions
            for (int i = 0; i < n; i += 2)
                result += s[i];

            // Odd positions
            for (int i = 1; i < n; i += 2)
                result += s[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {

            // Read length
            int n = 0;
            while (s[i] != '#') {
                n = n * 10 + (s[i] - '0');
                i++;
            }

            i++; // skip '#'

            string encoded = s.substr(i, n);
            i += n;

            string original(n, ' ');

            // Number of even positions
            int evenCount = (n + 1) / 2;

            // Put even positions back
            for (int j = 0; j < evenCount; j++)
                original[j * 2] = encoded[j];

            // Put odd positions back
            for (int j = 0; j < n / 2; j++)
                original[j * 2 + 1] = encoded[evenCount + j];

            result.push_back(original);
        }

        return result;
    }
};