/**

	KMP Algorithm is a searching algorithm used to find a specific pattern in a given text.
	Naive way of doing this would cost in O(n^2) which can be optimized using KMP Search.
	The basic idea behind KMP is to not search we know would match anyway. If we know somwthing
	would match then we don't need to rematch the same text.

	To do this, we construct an lps[] array which basically stores the the values for the proper
	prefixes which are also suffixes in the given pattern. 

	lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 

    This helps in finding out which part we can skip matching whenever we find a mismatch.
	
	Time Complexity: O(m+n)

    Video help: https://www.youtube.com/watch?v=GTJr8OvyEVQ

**/
#include <bits/stdc++.h>
using namespace std;

int lps[1001];
int m, n;

// Construction of lps[] array
void LPSArray(string pat)
{
	// Here len and i are used as index to go through the pattern
	// Searching starts from 0 and 1, hence len=0 and i=1
	int len=0, i=1;

	// lps[0] is always 0
	lps[0] = 0;

	// Go through all characters
	while(i < m)
	{
		// Found matching char
		if(pat[i] == pat[len])
		{
			// lps[i] will be len+1 and increment i and len both
			len++;
			lps[i] = len;
			i++;
		}
		else // Found a mismatch
		{
			// We basically go to len as lps[len-1] and do not increment i but not if len is 0
			if(len != 0)
			{
				len = lps[len-1];
			}
			else // len=0, increment i
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Searching Algorithm
void KMPSearch(string pat, string txt)
{
	// Lengths of both strings
	m = pat.length();
	n = txt.length();

	// Construct lps array first, its size would be m
	LPSArray(pat);

	// i --> txt[] and j --> pat[]
	int i=0, j=0;

	// Go through the text
	while(i < n)
	{
		// Char matches, increment both
		if(pat[j] == txt[i])
		{
			j++; i++;
		}

		// j=m, i.e all the pattern has been matched
		if(j == m)
		{
			// The starting index would be i-j or i-m 
			cout << "Pattern found at index " << i-j << endl;

			// Continue searching
			j = lps[j-1];
		}

		// mismatch after j matches
		else if(i < n && pat[j] != txt[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
			if(j != 0)
			{
				j = lps[j-1];
			}
			else // only for j=0
			{
				i++;
			}
		}
	}

}

int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";

	KMPSearch(pat, txt);
}