#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    list<string> palins;

    for (int i = 1; i <= str.size(); i++)
    {
        //to each size() of sub string
        for (int start = 0; start < str.size(); start++)
        {
            //to each initial position in string
            bool error = false;
            int end = start + i - 1;
            if (end < str.size())
            {
                for (int k = 0; k < (int)(i / 2); k++)
                {
                    if (str[k + start] != str[end - k])
                    {
                        error = true;
                        break;
                    }
                }
            }
            else
            {
                error = true;
            }
            //extract sub string [start, end] of str
            if (!error)
            {
                palins.push_back(str.substr(start, i));
            }
        }
    }
    list<string>::iterator ptr;
    cout << palins.size() << ' -';
    for (ptr = palins.begin(); ptr != palins.end(); ptr++)
    {
        cout << ' "' << *ptr << '"';
    }
    cout << endl;
    return 0;
}