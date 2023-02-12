class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> sol;
        string build;
        int left = 0;
        int right = left;
        int total = 0;
        int numSpaces = 0;
        double sizeSpaces = 0;
        while (left < words.size()) {
            numSpaces = 0;
            
            // 1: get first word
            build = words[left];
            total = words[left].length();

            // 2. get following words
            while (right + 1< words.size() && total + numSpaces + 1 + words[right + 1].length() <= maxWidth) {
                right++;
                total += words[right].length();
                numSpaces++;
            }

            /* 3.
            case 1: multiple words, non final line
            case 2: one word
            case 3: final line
            */

            // 31:
            if (left != right && right != words.size() - 1) {
                for (int i = left + 1; i <= right; i++) {
                    sizeSpaces = (double)(maxWidth - total) / (double)numSpaces;
                    for (int i = 0; i < ceil(sizeSpaces); i++) {
                        build += " ";
                        total++;
                    }
                    numSpaces--;
                    build += words[i];
                }
            } else {
                sizeSpaces = 1;
                for (int i = left + 1; i <= right; i++) {
                    for (int i = 0; i < sizeSpaces; i++) {
                        build += " ";
                        total++;
                    }
                    build += words[i];
                }
                for (int i = total; i < maxWidth; i++) {
                    build += " ";
                }
            }
            sol.push_back(build);
            left = right + 1;
            right = left;

        }
        return sol;
    }
};
