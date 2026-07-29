#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            // If already mapped, check consistency
            if (s_to_t.find(a) != s_to_t.end() && s_to_t[a] != b)
                return false;

            if (t_to_s.find(b) != t_to_s.end() && t_to_s[b] != a)
                return false;

            // Create mapping
            s_to_t[a] = b;
            t_to_s[b] = a;
        }

        return true;
    }
};
