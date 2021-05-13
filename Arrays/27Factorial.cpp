#include <iostream>
#include <vector>
using namespace std;

void factorial(int n)
{
    //4
    /*
     * Overview : 
     * n = 4;
     * result[] = [1]
     * 4 * 3 * 2 * 1   (n ! )
     * 
     * 5! 120
     * 6! 720
     * 10! 3628800
     * int 10 ---> 20 limit exceeded
     *  long long int --> c++ --> not suffiecient store the fact(n > 50) + overhead(factorial(i))
     * Java -> BIG INTEGER --> handles the pain :)
     * C++ --> No such class --> put your brains to work !!
     * 20! -->
     */

    /**
     * Analysis :
     * n=4 --> 24
     * 4 * 3 * 2 * 1 --> [ amount of digits ] --> 1.declare arr[VERY_LARGE_SIZE]  2.vector<int> -->dynamic
     * int arr[100000] n!, 4! = 24 [2 ,4] 0 to 9
    */
    void factorial(int n)
    {
        /**
        * n = 5;
        * 4 * 3 * 2 * 1
        * res = 2 ; prod = 2 carr = 0
        * res = 2*3; prod = 6 carr = 0
        * res = 6*4; prod = 4 carr = 2
        * res = 24*5; prod = 0 carr = 12
        * [0 2] [0 6] [4 2] [0 2 1]
        * 
        * 0 | 2 | 7
        * 
        * mul(i,res){
        * 
        * carr = 0
        * k = 0; k < res.size(); k++
        *   prod = a[k] * i + carr // 6 * 4 = 24 ,24 * 5 = 120, 120 * 6 = 720, 6 * 2 = 12, 6 * 1 + 1 = 7
        *   res[k] = prod%10; //2,7
        *   carr = carr / 10; // carr = 2, carr = 12, carr = 1, carr=1, carr=0
        * 
        * while(carr){
        *   res.push_back(carr % 10);
        *   carr = carr/10;
        * }
        *   
        * }
        * 
        * i = 2,3,4,5,6
        * i = 2; i <= n; i++
        *   mul(i,res);
        */
    }
}

void multiply(vector<int> &fact, int i)
{

    //[ ]
    int carr = 0;
    for (int k = 0; k < fact.size(); k++)
    {
        int prod = fact[k] * i + carr;
        fact[k] = prod % 10;
        carr = carr / 10;
    }

    while (carr)
    {
        res.push_back(carr % 10);
        carr = carr / 10;
    }
}

vector<int> factorial(int n)
{

    vector<int> fact;
    fact.push_back(1); // Fact(1) = 1
    for (int i = 2; i <= n; i++)
        multiply(fact, i);

    cout << "Factorial of " << n << " is " << endl;
    for (int i = 0; i < fact.size(); i++)
        cout << fact[i];
}

int main()
{
    int n;
    cin >> n;
    factorial(n);
    return 0;
}
