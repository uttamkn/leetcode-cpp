class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> pos = {0, 0};
        char cur_dir = 'N';
        for(int i=0;i<4;i++) {
            for(char instruction : instructions) {
                if(instruction!='G') {
                    switch(cur_dir) {
                        case 'N': cur_dir = (instruction=='L')?'W':'E';
                        break;
                        case 'S': cur_dir = (instruction=='L')?'E':'W';
                        break;
                        case 'E': cur_dir = (instruction=='L')?'N':'S';
                        break;
                        default: cur_dir = (instruction=='L')?'S':'N';
                    }
                }
                else move(pos, cur_dir);
            }
            if(pos[0]==0 && pos[1]==0) return true;
        }

        return false;
    }
private:
    void move(vector<int>& pos, char cur_dir) {
        switch(cur_dir) {
            case 'N': pos[1]++;
            break;
            case 'S': pos[1]--;
            break;
            case 'E': pos[0]++;
            break;
            default: pos[0]--;
        }
    }
};