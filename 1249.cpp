#include <iostream>
#include <string>
#include <set>


using namespace std;

string minRemoveToMakeValid(string s) 
{
    int N = s.length();
    //Declare an array arr to store the result of parenthese test
    int arr[N];
    //Initialize all values of the arr to be 0
    for(int i=0; i<N;i++)
    {
        arr[i]=0;
    }
    for(int l=0; l<N; l++)
    {//Loop starting for left side of string s
        int lastRight = N;
        if(s[l]=='(')
        {//If find '(', try to find ')'
            for(int r=lastRight; r>l; r--)
            {
                if(s[r]==')')
                {
                    s[r]=1;
                    s[l]=1;
                    continue;
                    // l++
                    // r--
                    // lastRight = r-1
                }
                
            }
        }

    }


    //Loop starting from right side of string s


}