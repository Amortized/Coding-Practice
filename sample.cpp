#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <string>

using namespace std;

void closestPair(vector<int> &v, int sum)
{
	int i = 0, j = v.size() - 1, diff = numeric_limits<int>::max(), x = 0, y = 0;
  
    
    while(i < j)
    {
    	if (fabs(v[i] + v[j] - sum) < diff)
    	{
    		diff = fabs(v[i] + v[j] - sum);
    		x = i;
    		y = j;
    	}

    	//Move
    	if ( (v[i] + v[j]) > sum)
    	{
           j--;
    	}
    	else
    	{
    		i++;
    	}
    }

    cout << " The closest Pair is " << v[x] << " and " << v[y] << " " << endl;

} 

void findNoAppearingOnce(vector<int> &v)
{
   int ones = 0, twos = 0, threes = 0;

   for(auto &i : v)
   {

     twos  |= (ones & i); 
   	 ones  ^= i;

   	 threes = ~(ones & twos);
   	 ones   &= threes;
   	 twos   &= threes;
   
   }

   cout << "No appearing once " << ones << endl;

}

void swap(string &x, int i, int j)
{
	char temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}

void stringPermuations(string x, int swapIndex, int len)
{
   if(swapIndex == len - 1)
   {
      cout << x << endl;   
   }

   for(int j = swapIndex; j < len; j++)
   {
      swap(x, swapIndex, j);
      stringPermuations(x, swapIndex+1, len);
      swap(x, j, swapIndex);
   }
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

void longestCommonSubsequence(string s1, string s2)
{
   int LCS[s1.length()+1][s2.length()+1];
   int backTrack[s1.length()+1][s2.length()+1]; //3 - indicates match; 1 - indicates left; 2 - indicates upwards

   int i,j;
   for(i = 0; i <= s1.length(); i++)
   {
    for(j = 0 ; j <= s2.length(); j++)
    {
      if (i == 0 or j == 0)
      {
        LCS[i][j] = 0;
        if(i == 0 and j == 0)
        {
          backTrack[i][j] = -1;
        }
        else if (i == 0) {
          backTrack[i][j] = 1;
        }
        else
        {
          backTrack[i][j] = 2; 
        }
      }
      else if(s1[i-1] == s2[j-1])
      {
        LCS[i][j] = LCS[i-1][j-1] + 1;
        backTrack[i][j] = 3;
      }
      else
      {
        if(LCS[i][j-1] >= LCS[i-1][j])
        {
          LCS[i][j]       =  LCS[i][j-1];
          backTrack[i][j] =  1;
        }
        else
        {
          LCS[i][j]       =  LCS[i-1][j];
          backTrack[i][j] =  2;
        }
      }    
    }    
   }


   i = s1.length();
   j = s2.length();

   cout << "LCS : ";
   while(i > 0 or j > 0)
   {
     if(backTrack[i][j] == 3)
     {
       cout << s1[i-1] << " ";
       i--;
       j--;
     } 
     else if (backTrack[i][j] == 2)
     {
       if (i > 0)
       {
        i--;
       }
     }
     else 
     {
       if (j > 0)
       {
        j--;
       }
     }
   }
  

}


int main()
{
    vector<int> v {-1, -1, -1, -10, -10, -10, -2};

    findNoAppearingOnce(v);

    string s ("ABC");
    //stringPermuations(s, 0, s.length());
    longestCommonSubsequence("AGGTAB", "GXTXAYB");

	return 0;
}