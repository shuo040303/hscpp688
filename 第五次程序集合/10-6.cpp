#include<bits/stdc++.h>
using namespace std;

const int N = 6;

template<class T>
void exchange(list<T>& l1, typename list<T>::iterator p1, list<T>& l2, typename list<T>::iterator p2)
{
    list<T> temp;
    temp.splice(temp.begin(), l1, p1, l1.end());
    l1.splice(l1.end(), l2, p2, l2.end());
    l2.splice(l2.end(), temp, temp.begin(), temp.end());
}

int main()
{
    list<int> a, b;
    int i;
    for(i=0; i<N; i++)
    {
        a.push_back(2*i+1);
        b.push_back(3*i+1);
    }
    cout<<"a: ";
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    cout<<"b: ";
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    
    cout<<"after exchanging..."<<endl;
    list<int>::iterator p1 = a.begin();
    list<int>::iterator p2 = b.begin();
    exchange(a, p1, b, p2);

    cout<<"a: ";
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    cout<<"b: ";
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;

    return 0;
}