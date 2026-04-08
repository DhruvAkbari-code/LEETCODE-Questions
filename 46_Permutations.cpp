#include <iostream>
#include <vector>
using namespace std;

void getPermutations(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getPermutations(nums, idx + 1, ans);
        swap(nums[idx], nums[i]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;

    getPermutations(nums, 0, ans);

    cout << "All permutations:\n";
    for (auto &perm : ans)
    {
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> ans;

//     sort(nums.begin(), nums.end());

//     do
//     {
//         ans.push_back(nums);
//     } while (next_permutation(nums.begin(), nums.end()));

//     // Print results
//     cout << "All permutations:\n";
//     for (auto &perm : ans)
//     {
//         for (int num : perm)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }