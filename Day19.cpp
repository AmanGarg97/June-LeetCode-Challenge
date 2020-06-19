// Question -   Longest Duplicate Substring

/*

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)



Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""


Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.

*/

// Solution

class Solution
{
    public:
    string result="";
    long long int powmod(long long int a,long long int b,long long int m)
    {
        long long int result=1;
        long long int base=a;
        while(b)
        {
            if(b%2==1)
            {
                result=(result*base)%m;
            }
            base=(base*base)%m;
            b>>=1;
        }
        return result;
    }
    bool check(string& S,long long int l)
    {
        long long int m=1000000007;
        unordered_map<int,vector<int>> v;
        long long int current=0;
        for(int i=0;i<l;i++)
        {
            current=(current+powmod(26,l-i-1,m)*(S[i]-'a'))%m;
            current=(current+2*m)%m;
        }
        v[current].push_back(0);
        for(int i=0;i<(int)S.length()-l;i++)
        {
            current=(current-powmod(26,l-1,m)*(S[i]-'a')+m)%m;
            current=(current*26)%m;
            current=(current+(S[i+l]-'a'))%m;
            current=(current+2*m)%m;
            if(v.find(current)!=v.end())
            {
                for(int j=0;j<v[current].size();j++)
                {
                    if(S.substr(i+1,l)==S.substr(v[current][j],l))
                    {
                        if(l>result.length())
                        {
                            result=S.substr(i+1,l);
                        }
                        return true;
                    }
                }
            }
            v[current].push_back(i+1);
        }
        return false;
    }
    string longestDupSubstring(string S)
    {
        int p1=1;
        int p2=(int)S.length()-1;
        while(p1<p2)
        {
            int middle=(p1+p2)/2;
            if(check(S,(long long int)middle)==true)
            {
                p1=middle+1;
            }
            else
            {
                p2=middle-1;
            }
        }
        bool r;
        if(p1-1>0)
        {
            r=check(S,(long long int)p1-1);
        }
        r=check(S,(long long int)p1);
        r=check(S,(long long int)p1+1);
        return result;
    }
};
