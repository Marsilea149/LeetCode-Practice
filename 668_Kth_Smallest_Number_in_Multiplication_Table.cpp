#include <iostream>
#include <vector>
#include <algorithm>

int findKthNumber(int m, int n, int k)
{
    std::vector<int> table;
    for (unsigned i = 1; i < m + 1; ++i)
    {
        for (unsigned j = 1; j < n + 1; ++j)
        {
            table.push_back(i * j);
        }
    }
    sort(table.begin(), table.end());

    for (unsigned s = 0; s < m * n; ++s)
        std::cout << "table " << s << " " << table[s] << std::endl;
    return table[k - 1];
}

int main()
{
    int m = 2;
    int n = 3;
    int k = 2;
    int res = findKthNumber(m, n, k);

    return 0;
}