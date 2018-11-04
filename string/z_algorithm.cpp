/*

	Z-Algorithm is used for patern matching in linear time.
	Total time taken is O(m+n) with linear space complexity
	m being the length of the pattern and n being the length of text.
	It basically constructs Z_Array which is used for pattern matching

	For a string str[0..n-1], Z array is of same length as string. An element Z[i]
	of Z array stores length of the longest substring starting from str[i]
	which is also a prefix of str[0..n-1].
	The first entry of Z array is meaning less as complete string is always prefix of itself.

*/

#include <bits/stdc++.h>
using namespace std;

// Z Array
int Z[1001];

// Calculate Z Array function
void
cal_Zarr (string s)
{
    int left = 0;
    int right = 0;

    // Working
    for (int k = 1; k < s.length (); k++)
      {
          if (k > right)
            {
                left = right = k;

                while (right < s.length () && s[right] == s[right - left])
                  {
                      right++;
                  }

                Z[k] = right - left;
                right--;
            }
          else
            {
                int k1 = k - left;

                if (Z[k1] < right - k + 1)
                  {
                      Z[k] = Z[k1];
                  }
                else
                  {
                      left = k;
                      while (right < s.length ()
                             && s[right] == s[right - left])
                        {
                            right++;
                        }
                      Z[k] = right - left;
                      right--;
                  }
            }
      }
}

vector < int >
Z_Algorithm (string txt, string pat)
{
    // m = lenght of pattern 
    // n = length of text
    int n = txt.length ();
    int m = pat.length ();

    // Creating a new string to calculate Z array
    string newString = "";
    newString += pat;

    // Adding a new char to differentiate between patten and text in new string
    newString += '$';
    newString += txt;

    // Initialize Z array to 0. Its size will be same as length of new string.
    for (int i = 0; i < n + m + 1; i++)
      {
          Z[i] = 0;
      }

    // Calculate Z array
    cal_Zarr (newString);

    // Creating a vector to store all index
    vector < int >result;

    for (int i = 0; i < n + m + 1; i++)
      {
          if (Z[i] == m)
            {
                // Pattern found, store the index
                result.push_back (i - m - 1);
            }
      }
    // Retuen the result
    return result;
}

int
main ()
{
    // Main text
    string txt = "aaabcxyzaaaabczaaczabbaaaaaabc";

    // Pattern to search for
    string pat = "aaabc";

    // Vector of the index where the pattern is found
    vector < int >result = Z_Algorithm (txt, pat);

    // Printing the index
    cout << "The pattern is found at index: ";
    for (int i = 0; i < result.size (); i++)
      {
          cout << result[i] << " ";
      }
    cout << endl;
    return 0;
}
