#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <string>
#include <algorithm>

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

int min(int a, int b)
{
    return (a < b)? a : b;
}

// Returns Minimum among a, b, c
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
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

int minEditDistance(const string& x1, const string& x2)
{
   vector<vector<int> > D;

   int m = x1.length();
   int n = x2.length();

   for(int i = 0; i <= m; i++)
   {
    vector<int> temp;
    for(int j = 0; j <= n; j++)
    {
      temp.push_back(0);
    }
    D.push_back(temp);
   }

   for(int i = 1; i <= m ; i++)
   {
    D[i][0] = i;
   }

   for(int j = 1; j <= n ; j++)
   {
    D[0][j] = j;
   }


   int insertionCost = 0, deletionCost = 0, replacementCost = 0;
   for(int i = 1; i <= m; i++)
   {
    for(int j = 1; j <= n; j++)
    {
      replacementCost = D[i-1][j-1] + (x1[i-1] == x2[j-1] ? 0 : 1);
      insertionCost   = D[i-1][j] + 1;
      deletionCost    = D[i][j-1] + 1; 
 
      D[i][j]         = Minimum(replacementCost, insertionCost, deletionCost);

    }
   }

   return D[m][n];
}

void reverseStr(const string& input, string& output)
{
  char temp[input.length()+1];

  for(int i = input.length()-1, j = 0; i>=0 ; i--, j++)
  {
    temp[j] = input[i];
  }
  temp[input.length()]   = '\0';

  output    = temp;
}

void longestPalindromeSubsequence(const string& s1)
{

    
    string s2;
    reverseStr(s1, s2);

    longestCommonSubsequence(s1, s2);
    

    int palindomLen[s1.length()][s1.length()];

    for(int i = 0; i < s1.length(); i++)
    {
      palindomLen[i][i] = 1;
    }


    for(int len = 1; len < s1.length(); len++)
    {
      for(int j = 0; (j+len) < s1.length(); j++)
      {
        if(len == 1 && s1[j] == s1[j+len])
        {
          palindomLen[j][j+len] = 2;
        }
        else if (len > 1) 
        {
           if(s1[j] == s1[j+len])
           {
             palindomLen[j][j+len] = 2 + palindomLen[j+1][j+len-1];
           } 
           else if (len == 2)
           {
            palindomLen[j][j+len] = 1;
           }
           else
           { 
            palindomLen[j][j+len] = max(palindomLen[j+1][j+len], palindomLen[j][j+len-1]);
           }
        }
      }
    }

    cout << "\nLCS is " << palindomLen[0][s1.length()-1] << endl;


}

int main()
{
    vector<int> v {-1, -1, -1, -10, -10, -10, -2};

    //findNoAppearingOnce(v);

    string s ("GEEKSFORGEEKS");
    //stringPermuations(s, 0, s.length());
    //longestCommonSubsequence("AGGTAB", "GXTXAYB");

    //cout << minEditDistance("ABC", "ABD");

    longestPalindromeSubsequence(s);
  	return 0;
}