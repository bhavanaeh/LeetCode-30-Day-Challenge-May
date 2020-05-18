/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        if(p.length()>s.length())
            return result;
        vector<int>pchars(26,0);
        for(char c:p)
            pchars[c-'a']+=1;
        int start =0;
        for(int i=0;i<p.length();i++)
            pchars[s[i]-'a']-=1;
        bool match = true;
        for(int pc:pchars)
        {
            if(pc!=0)
            {
                match=false;
                break;
            }
        }
        if(match)
            result.push_back(start);
        start++;
        
        while(start<=s.length()-p.length())
        {
           int index1=s[start-1]-'a';
            int index2=s[start+p.length()-1]-'a';
            pchars[index1]+=1;
            pchars[index2]-=1;
            
            match = true;
        for(int pc:pchars)
        {
            if(pc!=0)
            {
                match=false;
                break;
            }
        }
        if(match)
            result.push_back(start);
        start++;
                
        }
        return result;
        
    }
};