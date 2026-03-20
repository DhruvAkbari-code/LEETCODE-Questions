// TODO: Given an array of characters chars, compress it using the following algorithm:
// TODO: Begin with an empty string s. For each group of consecutive repeating characters in chars:
// TODO: If the group's length is 1, append the character to s.
// TODO: Otherwise, append the character followed by the group's length.
// TODO: The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
// TODO: After you are done modifying the input array, return the new length of the array.
// TODO: You must write an algorithm that uses only constant extra space.
// TODO: Note: The characters in the array beyond the returned length do not matter and should be ignored.

// *Example 1:
// Input: chars = ["a","a","b","b","c","c","c"]
// Output: 6
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

// *Example 2:
// Input: chars = ["a"]
// Output: 1
// Explanation: The only group is "a", which remains uncompressed since it's a single character.

// *Example 3:
// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: 4
// Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

// ? Constraints:
// 1 <= chars.length <= 2000
// chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int n = chars.size();
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int cnt = 0;

        while (i < n && chars[i] == ch)
        {
            cnt++;
            i++;
        }

        if (cnt == 1)
        {
            chars[idx++] = ch;
        }
        else
        {
            chars[idx++] = ch;
            string st = to_string(cnt);
            for (char dig : st)
            {
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);

    for (char st : chars)
    {
        cout << st;
    }

    return 0;
}