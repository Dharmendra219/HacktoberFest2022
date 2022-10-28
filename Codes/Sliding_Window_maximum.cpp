#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        vector<int> ans;

        int i = 0, j = 0;
        int n = nums.size();
        int mx, pm;
        deque<int> q;

        while (j < n)
        {

            while (!q.empty() && q.back() < nums[j])
            {
                q.pop_back();
            }
            q.push_back(nums[j]);

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                ans.push_back(q.front());

                if (nums[i] == q.front())
                {

                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};