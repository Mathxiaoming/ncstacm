#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Num
{
    string name;  //账号 
    int score;   //评分
    bool operator<(const Num x) const //对学生评分按从大到小排序，对学生账号按从小到大排序
    {
        if (score == x.score)
        {
            return name < x.name;
        }
        return score > x.score;
    }
};
Num nums[10010];
int main()
{
    int N, G, K;
    cin >> N >> G >> K;
    int sum = 0; //PAT代金券的总面值
    for (int i = 1; i <= N; i++)
    {
        cin >> nums[i].name >> nums[i].score;
        if (nums[i].score >= G)
            sum += 50;
        else if (nums[i].score >= 60)
            sum += 20;
    }
    cout << sum << endl;
    sort(nums + 1, nums + N + 1);
    int t = 1; //代表当前学生的名次，首先初始化第一名
    cout << t << " " << nums[1].name << " " << nums[1].score << endl;
    for (int i = 2; i <= N; i++) //从第二名开始，如果当前评分与前一名相同，则名次不变，否则名次等于自己的编号
    {
        if (nums[i].score == nums[i - 1].score)
        {
            cout << t << " " << nums[i].name << " " << nums[i].score << endl;
        }
        else
        {
            t = i;
            if (t > K)
                break;
            cout << i << " " << nums[i].name << " " << nums[i].score << endl;
        }
    }
    return 0;
}