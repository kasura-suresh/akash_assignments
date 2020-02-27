#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<forward_list>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,1,2,3,4,4,5};
    list<int> l = {1,2,3,4,5,6,7,8,9,10};
    int s = 3;
    queue<int> myqueue;
    myqueue.push(0);
    myqueue.push(1);
    myqueue.push(2);
    myqueue.pop();
    while (!myqueue.empty()) {
        cout <<' '<< myqueue.front();
        myqueue.pop();
    }
    cout<<endl;
    sort(v.begin(),v.end());
    vector<int> :: iterator p ;
    for(p = v.begin();p!=v.end();p++)
        cout<<*p;
    cout<<endl;
    for(int &i :l)
        cout<<i;
    cout<<endl;

    forward_list<int> flist1;
    flist1.assign({1, 2, 3});
    cout << "The elements of first forward list are : ";
    for (int &i : flist1)
        cout << i << " ";
    cout << endl;
    return 0;
}
