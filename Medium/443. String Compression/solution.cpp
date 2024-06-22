class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        int i = 0, j = 0;
        while (i < chars.size()) {
            int count = 0;
            while (j < chars.size() && chars[i] == chars[j]) {
                j++;
                count++;
            }
            if (count > 1) {
                chars.erase(chars.begin()+i+1, chars.begin()+j);
                i = i + insertDigits(chars, count, i) + 1;
            }
            else {
                i++;
            }
            j=i;
        }
        return chars.size();
    }
private:
    int insertDigits(std::vector<char>& chars, int num, int pos) {
        int numOfDigits = 0;
        while (num > 0) {
            chars.insert(chars.begin() + pos + 1, '0'+(num % 10));
            num/=10;
            numOfDigits++;
        }
        return numOfDigits;
    }
};
