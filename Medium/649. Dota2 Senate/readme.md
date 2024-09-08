# 649. Dota2 Senate

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

- **Ban one senator's right**: A senator can make another senator lose all his rights in this and all the following rounds.
- **Announce the victory**: If this senator finds that the remaining senators who still have rights to vote are all from the same party, they can announce the victory and decide on the change in the game.

Given a string `senate` representing each senator's party affiliation, the character 'R' represents the Radiant party and 'D' represents the Dire party. The length of the given string will be the number of senators, `n`.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for their own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be **"Radiant"** or **"Dire"**.

### Example 1:

- **Input**: `senate = "RD"`
- **Output**: `"Radiant"`
- **Explanation**:  
  The first senator comes from Radiant and bans the next senator's right in round 1.  
  The second senator (Dire) can't exercise any rights anymore since they have been banned.  
  In round 2, the first senator can announce the victory as they are the only senator left with the right to vote.

### Example 2:

- **Input**: `senate = "RDD"`
- **Output**: `"Dire"`
- **Explanation**:  
  The first senator comes from Radiant and bans the next senator's right in round 1.  
  The second senator (Dire) can't exercise any rights anymore since they have been banned.  
  The third senator (Dire) bans the first senator's right in round 1.  
  In round 2, the third senator can announce the victory as they are the only senator left with the right to vote.

### Constraints:

- `n == senate.length`
- `1 <= n <= 10^4`
- `senate[i]` is either 'R' or 'D'.
