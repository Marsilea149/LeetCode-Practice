
/** Difficulty: 4/10
 *  Key: string, unordered_set
 * Solution from https://zxi.mytechroad.com/blog/string/leetcode-648-replace-words/ 
 */
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> d(dictionary.begin(), dictionary.end());
        sentence.push_back(' ');
        string output;
        string word;
        bool found = false;
        for (char c : sentence)
        {
            if (c == ' ')
            {
                if (!output.empty())
                {
                    output += ' ';
                }
                output += word;
                // reset variables
                word = "";
                found = false;
                continue;
            }
            if (found)
            {
                continue;
            }
            word += c;
            if (d.count(word))
            {
                found = true;
            }
        }
        return output;
    }
};

/** My first attempt: failed...*/

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string item;
        string res;
        while (splitSentence(' ', sentence, item))
        {
            string root;
            if (isRootWord(item, dictionary, root))
            {
                for (char c : root)
                {
                    res.push_back(c);
                }
            }
            else
            {
                for (char c : item)
                {
                    res.push_back(c);
                }
            }
            res.push_back(' ');
        }
        return res;
    }

private:
    /** Method used to split sentence into words 
    * @param[in] delim: delimiter used to split
    * @param[in/out] sentence: the sentence to split
    * @param[out] item: the word extracted after one function call 
    * return true if there is still sentence to split
    * return false if not*/
    bool splitSentence(char const &delim, string &sentence, string &item)
    {
        for (int i = 0; i < sentence.size(); ++i)
        {
            if (sentence.at(i) == delim)
            {
                for (int j = 0; j < i; ++j)
                    item.push_back(sentence.at(j));
                sentence.erase(sentence.begin(), sentence.begin() + i);
                return true;
            }
        }
        return false;
    }

    /** Method used to verify if the item contains root 
    * @param[in] item: the word to check if it contains root
    * @param[in] disctionary: vector containing all the root words
    * @param[out] root: the root of item 
    * return true if the item contain root
    * return false if not*/
    bool isRootWord(string const &item, vector<string> const &dictionary, string &root)
    {
        for (int i = 0; i < dictionary.size(); ++i)
        {
            for (int j = 0; j < dictionary[i].size(); ++j)
            {
                if (dictionary[i].at(j) == item.at(j))
                {
                    root.push_back(item.at(j));
                }
            }

            if (root.size() == dictionary[i].size())
                return true;
            else
            {
                for (char c : root)
                {
                    root.pop_back();
                }
            }
        }
        return false;
    }
};