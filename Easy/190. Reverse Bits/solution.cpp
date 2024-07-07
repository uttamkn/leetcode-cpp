class Solution {
public:
    uint32_t reverseBits(uint32_t n) { return reverseBitsRecursively(n, 32); }

private:
    uint32_t reverseBitsRecursively(uint32_t n, int bitCount) {
        if (bitCount == 1) {
            return n;
        }
        uint32_t leftPart = n >> (bitCount / 2);
        uint32_t rightPart = n & ((1 << (bitCount / 2)) - 1);

        leftPart = reverseBitsRecursively(leftPart, bitCount / 2);
        rightPart = reverseBitsRecursively(rightPart, bitCount / 2);

        return (rightPart << (bitCount / 2)) | leftPart;
    }
};
