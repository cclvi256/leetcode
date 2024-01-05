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
	int rows = matrix.size();
	int cols = matrix[0].size();

	if (rows == 0)
	{
		return 0;
	}

	if (cols == 0)
	{
		return 0;
	}

	
}
