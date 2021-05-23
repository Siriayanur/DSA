#include <iostream>
#include <vector>
using namespace std;

bool checkIP(string ip)
{
    string curr = "";
    vector<string> ips;
    for (int i = 0; i < ip.size(); i++)
    {
        char c = ip[i];
        if (c == '.')
        {
            ips.push_back(curr);
            curr = "";
        }
        else
        {
            curr += ip[i];
        }
    }
    ips.push_back(curr);

    for (int i = 0; i < ips.size(); i++)
    {
        //For every segment check the bounds,and value

        // Length should be greater than 0 and less or equal to 3, value < 255
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
            return 0;

        //If first value is 0, length should be  1(it should be the only value in that segment)
        if (ips[i].length() > 1 && stoi(ips[i]) == 0)
            return 0;
        //LEading zeroes shouldnot be there
        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
            return 0;
    }
    return 1;
}

vector<string> validIpAddress(string str)
{
    int n = str.length();
    cout << "CAlled here" << endl;
    int i, j, k; // denote the possible positions of the 3 DOTS in Ipv4 address
    /**
     * eg : 1  9  0  2  4  2  6  --> Given str
     *       0  1  2  3  4  5    --> positions of dots that is VALID
     * 
     * length = 7
     * spacesForDots = 6 (0 .... 5) i.e (0... len-2)
     * Now,
     * The possibility of First Dot that is, i (we have assumed here) is,
     * 0 ... 3 (making sure we have space for the remaining two)
     * i --> 0 to n-4
     * 
     * Possibilty of Second and third dot similarly is,j and k,
     * j --> i+1 to n-3 (1...4)
     * k --> j+1 to n-2 (2...5)
     * 
     * Now check for all possibilities of DOTS and for each possibilty 
     * check if that forms a Valid IPv4 address using checkIP() 
    */
    string ip = str;
    vector<string> result;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                string newIp = "";
                newIp += (ip.substr(0, i + 1) + "." + ip.substr(i + 1, j - i) + "." + ip.substr(j + 1, k - j) + "." + ip.substr(k + 1, n - k));
                // cout << newIp << endl;
                if (checkIP(newIp))
                {
                    result.push_back(newIp);
                }
            }
        }
    }
    return result;
}
int main()
{
    string input;
    cin >> input;
    vector<string> result = validIpAddress(input);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}