#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

vector<int> nums;

// 注意这题神坑，仔细审题的话会发现题目是要求你在初始化为空的小顶堆
// 里插入结点，而不是在输入完成后进行堆排序，两者的顺序是不一样的
// 下面的注释是堆排序,输入完成后调用heap_sort(n)，就可以对数组进行
// 堆排序 ，先看怎么向下调整再看怎么向上调整，这样好理解
/* void siftdown(int i,int n)  //向下调整
{
    int t=nums[i],j;
    while((j=2*i+1)<n)
    {
        if(j<n-1&&nums[j]<nums[j+1]) ++j;
        if(t<nums[j])
        {
            nums[i]=nums[j];
            i=j;
        }
        else break;
    }
    nums[i]=t;
}

 void heap_sort(int n)       //堆排序
{
    for(int i=(n-2)/2;i>=0;--i) 
        siftdown(i,n);
    for(int i=n-1;i>0;--i)
    {
        swap(nums[0],nums[i]);
        siftdown(0,i);
    }
} */

void siftup(int k) //向上调整，结点插入的位置为k
{
    int j = k, i = (j - 1) / 2; //i是k的父亲节点
    int t = nums[j];
    while (j > 0) //j不是根节点时
    {
        if (nums[i] < t)
            break;
        else
        {
            nums[j] = nums[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    nums[j] = t;
}

int main()
{
    int n, m;
    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        siftup(i);
    }
    string str;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; ++i)
        hash[nums[i]] = i;
    for (int i = 0; i < m; ++i)
    {
        int x, y, index_x, index_y;
        cin >> x;
        cin >> str;
        index_x = hash[x];
        if (str[0] == 'a')
        {
            cin >> y;
            getline(cin, str);
            index_y = hash[y];
            if ((index_x - 1) / 2 == (index_y - 1) / 2)
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
        else
        {
            cin >> str;
            cin >> str;
            if (str[0] == 'r')
            {
                if (index_x == 0)
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }
            else if (str[0] == 'p')
            {
                cin >> str;
                cin >> y;
                index_y = hash[y];
                if ((index_y - 1) / 2 == index_x)
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }
            else
            {
                cin >> str;
                cin >> y;
                index_y = hash[y];
                if ((index_x - 1) / 2 == index_y)
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            }
        }
    }
    return 0;
}