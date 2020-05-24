/* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters. */


class Solution {
public:
    string frequencySort(string s) {
        pair<int,int> frequency[128];
         for(int i=0;i<128;i++)
        {
            frequency[i]=make_pair(0,i);
            
        }
        
        for(int i=0;i<s.size();i++)
        {
            frequency[int(s[i])].first++;
            
        }
        sort(frequency,frequency+128,greater<pair<int,int>>());
        string sorted;
        int i=0;
        while(frequency[i].first>0)
        {
            
            while(frequency[i].first>0)
            {
                
                // dont use + for adding in string because it increase time complexity 
                // time complexity of + operation =len(string1)+len(string2) so total become n^2
                //push_back() is O(1) time complexity
                sorted.push_back(char(frequency[i].second));
                frequency[i].first--;
            }
            i++;
        }
        return sorted;
        
    }
};