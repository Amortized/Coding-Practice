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



int main()
{
    vector<int> v {-1, -1, -1, -10, -10, -10, -2};

    findNoAppearingOnce(v);

    string s ("ABC");
    stringPermuations(s, 0, s.length());

	return 0;
}