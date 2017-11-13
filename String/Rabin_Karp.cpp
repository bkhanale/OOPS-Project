#include <bits/stdc++.h>
using namespace std;

// Here q is any prime number. This is required for the Hash function
int q = 101; 

// Function that calculates hash value for pattern that we are searching for and the first 
// substring of the main text
long long cal_hash(string s)
{
	// Returning hash value initialized to 0
	long long hash = 0;

	// Hash function: Could be anything
	for(int i=0; i<s.length(); i++)
	{
		hash += s[i] * pow(q, i);
	}
	// Return hash value calculated
	return hash;
}

// Calculate the hash value optimally
long long cal_rehash(char rem, char add, long long old_hash, int m)
{
	return (long long) ( ( (old_hash - rem) / q) + add * pow(q, m-1));
} 

// Rabin Karp Algorithm
void Rabin_Karp(string pat, string txt)
{
	// m = length of pattern 
	// n = length of text
	int m = pat.length();
	int n = txt.length();

	// initially calculate the hash for first substring and the pattern itself
	long long pat_hash = cal_hash(pat);
	long long txt_hash = cal_hash(txt.substr(0, m));

	// i here denotes the index where we found the pattern matching to the substring
	int i = -1;
	for(i=0; i<=n-m; i++)
	{
		// First check if the hash value matches 
		// If hash value matches then compare both strings
		if(txt_hash == pat_hash && pat == txt.substr(i, m))
		{
			// Found a matching pattern
			break;
			// We can find multiple occurences, we need to store the index for that
		}
		else
		{
			// Until the last substring where we have nothing to add
			if(i <= n-m-1)
			{
				// calculte the hash for the new substrings optimally
				txt_hash = cal_rehash(txt[i], txt[i+m], txt_hash, m);
			}
		}
	}

	if(i == -1) // No pattern found
	{
		cout << "Pattern not found\n";
	}else{      // Pattern found at i
		cout << "Pattern found at index " << i << endl;
	}
}

// Main function
int main()
{
	// Main text
	string txt = "dddcodechefcodeforces";

	// Pattern that needs to be searched
	string pat = "code";

	// Function call
	Rabin_Karp(pat, txt);

	return 0;
}