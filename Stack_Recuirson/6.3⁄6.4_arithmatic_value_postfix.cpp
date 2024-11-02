#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
map<string, int> prcdnc;
bool check(stack<string>st,string s)
{
 return (prcdnc[st.top()] >= prcdnc[s]);
}

vector<string> _con_postfix(vector<string> s)
{
    s.push_back(")");
    vector<string> p;
    stack<string> st;
    st.push("(");
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=="*" || s[i]=="/" || s[i]=="^" || s[i]=="+" || s[i]=="-")
            {while (check(st,s[i]))
            {
                p.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
            }
        else if (s[i] == "(")
        {
            st.push("(");
        }
        else if (s[i] == ")")
        {
            while (1)
            {
                if (st.top() == "(")
                {
                    st.pop();
                    break;
                }
                p.push_back(st.top());
                st.pop();
            }
        }
        else
        {
            p.push_back(s[i]);
        }
    }
    return p;
}
vector<string> _con_prefix(vector<string> s)
{

    vector<string>ss=_con_postfix(s);
    reverse(all(ss));
    return ss;
}
int _determine(vector<string> s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == "*")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a * b);
        }
        else if (s[i] == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a / b);
        }
        else if (s[i] == "+")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a + b);
        }
        else if (s[i] == "-")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a - b);
        }
        else if (s[i] == "^")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(pow(a, b));
        }
        else
        {
            st.push(stoi(s[i]));
        }
    }
    return st.top();
}
int main()
{
    prcdnc["^"] = 6;
    prcdnc["*"] = 5;
    prcdnc["/"] = 5;
    prcdnc["+"] = 2;
    prcdnc["-"] = 2;
    prcdnc["("] = 1;
    prcdnc[")"] = 1;
    vector<string> s;
    string ss;
    while (cin >> ss)
    {
        s.push_back(ss);
    }
    cout << "Before Postfix conversion :";
    for (auto it : s)
        cout << it << " ";
    cout << endl;
    // converting it to postfix
    vector<string> p = _con_postfix(s);
    vector<string> pre=_con_prefix(s);
     cout << "After Pretfix conversion :";
    for (auto it : pre)
        cout << it << " ";
    cout << endl;
    cout << "After Postfix conversion :";
    for (auto it : p)
        cout << it << " ";
    cout << endl;
    
    int val = _determine(p);
    cout << "Expression result is :";
    cout << val;
    return 0;
}