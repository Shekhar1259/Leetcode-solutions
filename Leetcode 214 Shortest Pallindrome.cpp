void f(vector<int> &lps,string &s)
{
    lps[0]=0;
    int len=0;
    int i=1;
    int n=s.size();
    while(i<n)
    {
        if(s[i]==s[len])
        {
          
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

class Solution {
public:
    string shortestPalindrome(string s) {

     
        string s3=s;
        int m=s.size();
         string s1=s;
        reverse(s1.begin(),s1.end());
        s+='#';
        s+=s1;
           int n=s.size();
         vector<int> lps(n);
        f(lps,s);
        int ind=(lps[n-1]);
        string s2="";
        for(int i=ind;i<m;++i)
        {
            s2+=s3[i];
        }
       reverse(s2.begin(),s2.end());
       s2+=s3;
        return s2;

    }
};