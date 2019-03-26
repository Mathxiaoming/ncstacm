#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    int mi = accumulate(nums.begin(), nums.begin() + (n / 2), 0); //就是求和
    int ma = accumulate(nums.begin() + (n / 2), nums.end(), 0);
    cout << "Outgoing #: " << (n + 1) / 2 << endl;
    cout << "Introverted #: " << (n / 2) << endl;
    cout << "Diff = " << (ma - mi);
    return 0;
}