class Solution {
public:
    string reverseVowels(string s) {
        int front=0, rear=s.size()-1;
        string vowels="aeiouAEIOU";
        while (front<rear) {
            if(vowels.find(s[front])!=string::npos && vowels.find(s[rear])!=string::npos) {
                char temp=s[front];
                s[front]=s[rear];
                s[rear]=temp;
                front++;
                rear--;
            }

            if(vowels.find(s[front])==string::npos) front++;
            if(vowels.find(s[rear])==string::npos) rear--;
        }

        return s;
    }
};