#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,1,2,3,4,4,5};
    int s = 3;
    sort(v.begin(),v.end());
    vector<int> :: iterator p ;
    for(p = v.begin();p!=v.end();p++)
        cout<<*p;
    vector<int> v1= {1,1};
    p = search(v.begin(),v.end(),v1.begin(),v1.end());
    if (p != v.end()) {
        cout << "\nvector1 is present at index " << (p - v.begin());
    } else {
        cout << "\nvector1 is not present in V";
    }

    p = find (v.begin(), v.end(), s);
    if (p != v.end())
    {
        cout << "\nElement " << s <<" found at position : " ;
        cout << p - v.begin() + 1 << "\n" ;
    }
    else
         cout << "\nElement not found.\n";

    cout<<count(v.begin(),v.end(),3)<<"\n";

    reverse(v.begin(),v.end());

     cout << "\nMax Element = \n"<< *max_element(v.begin(), v.end());
     cout << "\nMin Element = \n"<< *min_element(v.begin(), v.end());
     vector<int> v2 = {1,2,3,3,3,3,3,4};

     v.swap(v2);

      for(p = v.begin();p!=v.end();p++)
        cout<<*p;

        cout<<"\n";

         for(p = v2.begin();p!=v2.end();p++)
        cout<<*p;

        is_partitioned(v.begin(), v.end(), [](int x)
        {
            return x%2==0;
        })?cout << "\nVector is partitioned":cout << "\nVector is not partitioned";
         cout << endl;
}
