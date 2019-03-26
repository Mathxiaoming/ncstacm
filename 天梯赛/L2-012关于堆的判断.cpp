#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

vector<int> nums;

// ע��������ӣ���ϸ����Ļ��ᷢ����Ŀ��Ҫ�����ڳ�ʼ��Ϊ�յ�С����
// ������㣬��������������ɺ���ж��������ߵ�˳���ǲ�һ���� 
// �����ע���Ƕ�����,������ɺ����heap_sort(n)���Ϳ��Զ��������
// ������ ���ȿ���ô���µ����ٿ���ô���ϵ��������������
/* void siftdown(int i,int n)  //���µ���
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

 void heap_sort(int n)       //������
{
    for(int i=(n-2)/2;i>=0;--i) 
        siftdown(i,n);
    for(int i=n-1;i>0;--i)
    {
        swap(nums[0],nums[i]);
        siftdown(0,i);
    }
} */ 

void siftup(int k)  //���ϵ������������λ��Ϊk
{
    int j=k,i=(j-1)/2;  //i��k�ĸ��׽ڵ�
    int t=nums[j];
    while(j>0)          //j���Ǹ��ڵ�ʱ
    {
        if(nums[i]<t) break;
        else
        {
            nums[j]=nums[i];
            j=i;
            i=(i-1)/2;
        }
    }
    nums[j]=t;
}

int main()
{
    int n,m;
    cin>>n>>m;
    nums.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>nums[i];
        siftup(i);
    }
    string str;
    unordered_map<int,int> hash;
    for(int i=0;i<n;++i)
        hash[nums[i]]=i;
    for(int i=0;i<m;++i)
    {
        int x,y,index_x,index_y;
        cin>>x;cin>>str;
        index_x=hash[x];
        if(str[0]=='a')
        {
            cin>>y;
            getline(cin,str);
            index_y=hash[y];
            if((index_x-1)/2==(index_y-1)/2)
                cout<<"T"<<endl;
            else
                cout<<"F"<<endl;
        }
        else
        {
            cin>>str;cin>>str;
            if(str[0]=='r')
            {
                if(index_x==0)
                    cout<<"T"<<endl;
                else
                    cout<<"F"<<endl;
            }
            else if(str[0]=='p')
            {
                cin>>str;cin>>y;
                index_y=hash[y];
                if((index_y-1)/2==index_x)
                    cout<<"T"<<endl;
                else
                    cout<<"F"<<endl;
            }
            else
            {
                cin>>str;cin>>y;
                index_y=hash[y];
                if((index_x-1)/2==index_y)
                    cout<<"T"<<endl;
                else
                    cout<<"F"<<endl;
            }
        }
    }
    return 0;
}