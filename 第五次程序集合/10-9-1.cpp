#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a1[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int a2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    vector<int> v1(a1, a1+sizeof(a1)/sizeof(int));
    vector<int> v2(a2, a2+sizeof(a2)/sizeof(int));
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    assert(v1.size()==v2.size());
    vector<int>::iterator it1, it2;
    for(it1=v1.begin(), it2=v2.begin(); it1!=v1.end(), it2!=v2.end(); it1++, it2++)
        iter_swap(it1, it2);
    cout<<"after exchange..."<<endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    return 0;
}