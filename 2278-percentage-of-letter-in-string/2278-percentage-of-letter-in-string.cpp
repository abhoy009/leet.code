class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0; 
        int totalChars = 0; 

        for (char c : s) {
            if (isalpha(c)) {
                totalChars++; 
                if (tolower(c) == tolower(letter)) {
                    count++;   }
            }
        }

        if (totalChars == 0) {
            return 0; 
        }

        int percentage = static_cast<int>(count * 100 / totalChars);
        return percentage;
    }
};
