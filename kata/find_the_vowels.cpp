#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word)
{
    std::vector<int> res;
    char charArray[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < static_cast<int>(word.size()); ++i)
    {
        for (const auto& c : charArray)
        {
            if (tolower(word[i]) == c)
            {
                res.push_back(i + 1);
            }
        }
    }

    return res;
}
