#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        return fun(nums, 0, nums.size() - 1);
    }

  private:
    int fun(vector<int> &nums, int begin, int end)
    {
        if (end > begin)
        {
            int middle = (end + begin) / 2;
            int left = fun(nums, begin, middle);
            int right = fun(nums, middle + 1, end);
            int cross=MaxArrayCrossLeft(nums,begin,middle)
                +MaxArrayCrossRight(nums,middle+1,end);
            return max(max(left,right),cross);
        }
        if(end==begin)
        {
            return nums[begin];
        }
    }

    int MaxArrayCrossLeft(vector<int> &nums, int begin, int end)
    {
        int max = nums[end];
        int sum = max;
        while (end >= begin)
        {
            sum += nums[--end];
            if (sum > max)
                max = sum;
        }
        return max;
    }

    int MaxArrayCrossRight(vector<int> &nums, int begin, int end)
    {
        int max = nums[begin];
        int sum = max;
        while (begin <= end)
        {
            sum += nums[++begin];
            if (sum > max)
                max = sum;
        }

        return max;
    }
};



int main()
{
    Solution a;
    vector<int> nums;
    // nums.push_back(-2);
    // nums.push_back(1);
    // nums.push_back(-3);
    // nums.push_back(4);
    // nums.push_back(-1);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(-5);
    // nums.push_back(4);
    // nums.push_back(1);
    // nums.push_back(-1);
    // nums.push_back(1);

    int tmp;
    int number;

    cin>>number;

    for(int i=0;i<number;i++)
    {
        cin>>tmp;
        nums.push_back(tmp);
    }

    for(auto t:nums)
        cout<<t<<" ";
    cout<<endl;

    cout << a.maxSubArray(nums) << endl;
    return 0;
}