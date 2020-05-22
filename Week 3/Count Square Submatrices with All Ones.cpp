/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

Hint #1  
Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).
Hint #2  
Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.
*/


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
      int n = matrix.size();//rows
      int m = matrix[0].size();//columns
      for(int i = 0; i < m; i++)
          ans += matrix[n-1][i];
      for(int i = 0; i < n; i++)
          ans += matrix[i][m-1];
      ans -= matrix[n-1][m-1];
      for(int i = n - 2;i >= 0; i--){
         for(int j = m-2 ;j >= 0; j--){
            matrix[i][j] = matrix[i][j] == 1? 1 + min({matrix[i+1][j+1],matrix[i] [j+1],matrix[i+1][j]}) : 0;
            ans += matrix[i][j];
         }
      }
      return ans;      
        
    }
};