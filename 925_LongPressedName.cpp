//Solution from : https://zxi.mytechroad.com/blog/two-pointers/leetcode-925-long-pressed-name/
// Difficulty: 5/10
// trick:
//  - compare typed[j] with typed[j-1] when typed have long pressed case
//  - return using check of both string's size to validate they have been both entirely processed

// 925. Long Pressed Name
// Easy

// Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

// You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

// Example 1:

// Input: name = "alex", typed = "aaleex"
// Output: true
// Explanation: 'a' and 'e' in 'alex' were long pressed.
// Example 2:

// Input: name = "saeed", typed = "ssaaedd"
// Output: false
// Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
// Example 3:

// Input: name = "leelee", typed = "lleeelee"
// Output: true
// Example 4:

// Input: name = "laiden", typed = "laiden"
// Output: true
// Explanation: It's not necessary to long press any character.

// Constraints:

// 1 <= name.length <= 1000
// 1 <= typed.length <= 1000
// name and typed contain only lowercase English letters.

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0;
        int j = 0;
        while (i < name.length() && j < typed.length())
        {
            if (name[i] == typed[j])
            {
                ++i;
                ++j;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                ++j;
            }
            else
                return false;
        }

        while (j < typed.length() && typed[j] == typed[j - 1])
            ++j;
        return i == name.length() && j == typed.length();
    }
};