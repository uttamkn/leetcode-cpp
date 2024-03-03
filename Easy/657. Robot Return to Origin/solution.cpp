class Solution {
public:
    bool judgeCircle(string moves) {

        int x=0, y=0;
        for(char move : moves) {
            switch(move) {
                case 'U': y++;
                break;
                case 'D': y--;
                break;
                case 'R': x++;
                break;
                case 'L': x--;
            }
        }

        return ((y==0)&&(x==0))?true:false; 
    }
};