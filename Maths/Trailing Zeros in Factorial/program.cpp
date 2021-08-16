public class Solution {
    public int trailingZeroes(int A) {
        int count = 0;
        for (int i = 5; A / i >= 1; i = i * 5) {
            count += A / i;
        }
        return count;
    }
}

//  5 25 50 75 
