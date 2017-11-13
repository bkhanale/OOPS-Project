/* 
	The longest common subsequence (LCS) problem is the problem of finding the longest subsequence common to all sequences in a set of sequences (often just two sequences). 
The longest common subsequence problem is a classic computer science problem, the basis of data comparison programs such as the diff utility, and has applications in bioinformatics. It is also widely used by revision control systems such as Git for reconciling multiple changes made to a revision-controlled collection of files.

*/

#include <bits/stdc++.h>
using namespace std;



//Function to print Longest Common Subsequence
void LCS_display(vector<vector<char> > b, string X, int i, int j)
{
	// first row or column means end of sequence
	if(i == 0 || j == 0)
	{
		return;
	}
	
	if(b[i][j] == '@')
	{	//diagonal arrow, MATCH!!!
		LCS_display(b, X, i - 1, j - 1);
		cout << X[i];
	}
	else if(b[i][j] == '#')
	{	//up arrow
		LCS_display(b, X, i - 1, j);
	}
	else
	{	//left arrow
		LCS_display(b, X, i, j - 1);
	}
}
// Function finds the longest common subsequence in the given string.
int longestCommonSubsequence(string X, string Y)
{
	int m = X.length();
	int n = Y.length();
	
	
	//b stores direction of subsequence
	vector<vector<char> > d_LCS(m+1, vector<char>(n+1, 0));
	//c stores the length of subsequence
	vector<vector<char> > l_LCS(m+1, vector<char>(n+1, 0));
	
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			//X[i] -> subsequence with last character as X[i]
			//Y[j] -> subsequence with last character as Y[j]
			if(i == 0 || j == 0)
			{			
				//if the cursor is at first row or column, length of subsequence
				//is zero and direction is denoted by '/'
				l_LCS[i][j] = 0;
				d_LCS[i][j] = '/';
			}
			else if(X[i] == Y[j])
			{
				// if the X[i] = Y[j], i.e. the last character is same, 
				// therfore new_length = prev_length(diagonal element) + 1;
				l_LCS[i][j] = c[i-1][j-1] + 1;
				d_LCS[i][j] = '@'; //using @ to represent diagonal(up/left) arrow.
			}
			else
			// if last element doesn't match, then the max(left, upper) is considered
			// at c[i][j].
			{ 
				if(l_LCS[i-1][j] >= l_LCS[i][j-1])
				{
					l_LCS[i][j] = l_LCS[i-1][j];
					d_LCS[i][j] = '#'; //using # to represent the up arrow.
				}
				else
				{
					l_LCS[i][j] = l_LCS[i][j-1];
					d_LCS[i][j] = '!'; //using ! to represent the left arrow.
				}
			}
		}
	}
	LCS_display(d_LCS, X, m, n);
	// At c[m][n] is then length of the longest common subsequence		
	return c[m][n];
}	

int main()
{	
		string DNA1;
		string DNA2;
		cin>>DNA1>>DNA2;
		string space = " ";
		DNA1.insert(0, space);
		DNA2.insert(0, space);
		cout << endl << longestCommonSubsequence(DNA1, DNA2) - 1 << endl;
		return 0;
}
