#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    map<string, vector<string>> mappedStrings;
    queue<pair<string, int>> pq;
    map<string, int> visited;

    if (beginWord == endWord)
    {
        return 0;
    }

    //Since beginWord may or may not be included in the wordList
    // we separately map the possibilities :
    for (int i = 0; i < beginWord.size(); i++)
    {
        string temp = beginWord.substr(0, i) + "*" + beginWord.substr(i + 1);
        mappedStrings[temp].push_back(beginWord);
    }

    // For the rest of the words there in the wordList
    for (int i = 0; i < wordList.size(); i++)
    {
        string current = wordList[i];

        for (int j = 0; j < current.length(); j++)
        {

            string temp = current.substr(0, j) + "*" + current.substr(j + 1);
            mappedStrings[temp].push_back(current);
        }
    }

    pq.push(make_pair(beginWord, 1));
    visited[beginWord] = 1;

    while (!pq.empty())
    {
        pair<string, int> current = pq.front();
        pq.pop();

        string currentWord = current.first;
        int currentDistance = current.second;

        if (currentWord == endWord)
        {
            return currentDistance;
        }

        for (int i = 0; i < currentWord.length(); i++)
        {
            string temp = currentWord.substr(0, i) + "*" + currentWord.substr(i + 1);

            vector<string> mapped = mappedStrings[temp];
            for (int j = 0; j < mapped.size(); j++)
            {

                if (visited[mapped[j]] == 0)
                {
                    visited[mapped[j]] = 1;
                    pq.push(make_pair(mapped[j], currentDistance + 1));
                }
            }
        }
    }
    return 0;
}