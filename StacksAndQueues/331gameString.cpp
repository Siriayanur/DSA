#include <iostream>
#include <queue>

using namespace std;

int minValue(string s, int k)
{
    // code here
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            pq.push(make_pair(freq[i], 'a' + i));
        }
    }

    while (k > 0 && !pq.empty())
    {
        pair<int, char> current = pq.top();
        pq.pop();
        current.first--;
        pq.push(current);
        k--;
    }

    int ans = 0;
    while (!pq.empty())
    {
        pair<int, char> current = pq.top();
        ans += (current.first * current.first);
        pq.pop();
    }
    return ans;
}