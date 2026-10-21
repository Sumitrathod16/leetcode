class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);

        for(char c:word){
            if(islower(c))
               lower[c -'a'] = true;
            else
               upper[c -'A'] = true;

        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(lower[i] && upper[i])
                 count++;
        }
        return count;
    }
};