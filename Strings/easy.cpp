#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    string result;
    int balance = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (balance > 0)
                result += s[i];
            balance++;
        }
        else
        {
            balance--;
            if (balance > 0)
                result += s[i];
        }
    }
    return result;
}

string reverseWords(string s)
{
    string temp = "", ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        else if (s[i] == ' ' && temp != "")
        {
            ans = temp + " " + ans;
            temp = "";
        }
        else
        {
            continue;
        }
    }
    if (temp != "")
    {
        ans = temp + " " + ans;
    }
    return ans.substr(0, ans.size() - 1);
}

// largest odd number

string largestOddNumber(string num)
{
    for (int i = num.length() - 1; i >= 0; i--)
    {
        int digit = num[i] - '0';
        if (digit & 1)
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

bool isIsomorphic(string s, string t)
{
    int mp1[256] = {0};
    int mp2[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (mp1[s[i]] != mp2[t[i]])
            return false;
        mp1[s[i]] = i + 1;
        mp2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
}