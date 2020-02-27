#include<set>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    set<int> s = {4,5,5,1,2,3,4,5};
    for(const int &p : s)
    {
        cout<<p;
    }
    multiset<int, greater <int>> m;
    m.insert(10);
    m.insert(10);
    m.insert(20);
    m.insert(30);
    m.insert(40);
    m.insert(50);
    m.insert(10);

    cout << "\nThe multiset gquiz1 is : ";
    for (const int &p : m)
    {
        cout << '\t' << p;
    }
    cout << endl;
    cout << "s.lower_bound(4) : "
         << *s.lower_bound(4) << endl;
    cout << "s.upper_bound(4) : "
         << *s.upper_bound(4) << endl;

    map<int, int> f;

    f.insert(pair<int, int>(1, 40));
    f.insert(pair<int, int>(2, 30));
    f.insert(pair<int, int>(3, 60));
    f.insert(pair<int, int>(4, 20));
    f.insert(pair<int, int>(5, 50));

    map<int, int>::iterator itr;

    for (itr = f.begin(); itr != f.end(); ++itr) {
        cout<<'\t'<<itr->first<<'\t'<<itr->second <<'\n';
    }
    cout << endl;

    multimap <int, int> g;

    g.insert(pair <int, int> (1, 40));
    g.insert(pair <int, int> (2, 30));
    g.insert(pair <int, int> (3, 60));
    g.insert(pair <int, int> (4, 20));
    g.insert(pair <int, int> (5, 50));
    g.insert(pair <int, int> (6, 50));
    g.insert(pair <int, int> (6, 10));

    multimap <int, int> :: iterator it;

    for (it = g.begin(); it != g.end(); ++it)
    {
        cout<<'\t'<<it->first<<'\t'<<it->second<<'\n';
    }
    cout << endl;

}
