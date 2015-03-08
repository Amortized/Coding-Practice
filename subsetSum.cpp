#include <iostream>
#include <vector>

using namespace std;

typedef struct subsetElements 
{
   vector<int> a;
   bool exists;
}subsetElements;


void subsetSum(const vector<int> &input, int sum)
{
	subsetElements lookup[sum+1][input.size()+1];

	for(int i = 0; i <= input.size(); i++)
	{
        for(int j = 0; j <= sum; j++)
        {
           if(j == 0)
           {
           	 lookup[j][i].exists = true; //Sum is zero
           }   
           else if (i == 0)
           {
           	 lookup[j][i].exists = false; //No elements in the set
           }	
        }
	}

	for(int j = 1; j <= sum; j++)
	{
		for(int i = 1; i <= input.size(); i++)
		{
           if(input[i-1] > j)
           {
           	 //Last Element is greater than sum; ignore it
           	 lookup[j][i].exists = lookup[j][i-1].exists;
           	 lookup[j][i].a      = lookup[j][i-1].a;
           }   
           else
           {
              if(lookup[j][i-1].exists == true)
              {
              	lookup[j][i].exists = true;
              	lookup[j][i].a = lookup[j][i-1].a;
              	continue;
              }
            
              if(lookup[j-input[i-1]][i-1].exists == true)
              {
                 lookup[j][i].exists = true;
                 lookup[j][i].a = lookup[j-input[i-1]][i-1].a;
                 lookup[j][i].a.push_back(input[i-1]);
                 continue;
              }

              lookup[j][i].exists = false;
           }
		}
	}

	cout << lookup[sum][input.size()].exists << endl;
	cout << "\nElements : ";

	for (auto &ele : lookup[sum][input.size()].a)
	{
		cout << ele << " ";
	}
	cout << endl;
}

int main()
{
    vector<int> v{3, 34, 4, 12, 5, 2};
    subsetSum(v, 50);
	return 0;
}