class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0, tens=0;
        for(int bill : bills) {
            if(bill==5) {
                fives++;
                continue;
            }

            if(bill==10) {
                tens++;
                if(fives==0) return false;
                else fives--;
                continue;
            }

            if(bill==20) {
                if(tens>0 && fives>0) {
                    tens--;
                    fives--;
                    continue;
                }
                else if(fives>=3) {
                    fives-=3;
                }
                else return false;
            }
        }
        return true;
    }
};