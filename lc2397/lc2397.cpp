#include <iostream>
#include <vector>

using namespace std;

int maximumRows(vector<vector<int>> &matrix, int numSelect);

int main(int argc, char **argv)
{

	return 0;
}

int maximumRows(vector<vector<int>> &matrix, int numSelect)
{
	vector<int> sum;
	int rowsCovered = 0;

	for (vector<int> i : matrix)
	{
		int rowSum = 0;
		for (int j : i)
		{
			rowSum += j;
		}
		sum.push_back(rowSum);
	}

	int maxRowSum = 0;
	for (int i : sum)
	{
		if(i > maxRowSum)
		{
			maxRowSum = i;
		}
		
		if (i == 0)
		{
			++rowsCovered;
		}
	}
}
