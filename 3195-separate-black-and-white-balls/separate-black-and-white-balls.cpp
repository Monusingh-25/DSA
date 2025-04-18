class Solution {
public:
    long long minimumSteps(string s) {
 
    long long countWhite = 0;
    long long steps = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
             if (s[i] == '1') {
                steps += countWhite;
             }
             else {
                 countWhite++;
                }
        }
        return steps;
    }
};