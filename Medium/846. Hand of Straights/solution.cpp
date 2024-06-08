class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::map<int, int> nums;

        for (int num : hand) {
            nums[num]++;
        }

        auto it = nums.begin();
        while(it != nums.end()) {
            int prev = -1;
            int count = 0;
            while (count < groupSize) {
                it->second--;
                if (prev != -1) {
                    if(it->first != prev + 1) return false;
                }
                prev = it->first;
                if (it->second == 0) nums.erase(it);
                it++;
                count++;
            }
            it = nums.begin();
        }

        return true;
    }
};
