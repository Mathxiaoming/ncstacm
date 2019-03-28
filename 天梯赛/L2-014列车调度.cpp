#include <set>
#include <vector>
#include <iostream>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
// 对于样例所需要的四条轨道：
// 1 2 4 8
// 3 5
// 6 9
// 7
// 所有的轨道必定是增序排序的，新进列车时找有没有比当前元素大的，有就把大的元素替换掉
// 被替换的列车是必定可以按照某种顺序递减离开
const int maxn = 100005;
int nums[maxn];

int main()
{
    int n, a, cnt = 0; //n辆车，a是输入的编号，cnt为轨道数
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (i == 0 || a > nums[cnt])
            nums[++cnt] = a;
        //这里不能cnt++，因为数组初始化为0，必定满足大于条件
        else
        {
            int l = 1, r = cnt;
            while (l < r) //lower_bound查找第一个大于等于当前数的下标(轨道)
            {
                int mid = l + (r - l) / 2;
                if (nums[mid] > a)
                    r = mid;
                else
                    l = mid + 1;
            }
            nums[l] = a;
        }
    }
    cout << cnt;
    return 0;
}

//用set，不建议，很慢
/* int main()
{
    int n,a;
    cin>>n;
    set<int> nums;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        if(nums.empty())
            nums.insert(a);
        else
        {
            if(nums.lower_bound(a)!=nums.end())
            {
                nums.erase(nums.lower_bound(a));
                nums.insert(a);
            }
            else
                nums.insert(a);
        }
    }
    cout<<nums.size();
    return 0;
} */