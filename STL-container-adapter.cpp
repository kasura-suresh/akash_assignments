#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    queue<int> my;
    my.push(0);
    my.push(1);
    my.push(2);
    my.push(0);
    my.push(1);
    my.push(2);
    my.pop();
    while (!my.empty()) {
        cout <<' '<< my.front();
        my.pop();
    }
    cout<<endl;


	priority_queue <int> g;
	g.push(10);
	g.push(30);
	g.push(20);
	g.push(5);
	g.push(1);
	g.push(10);
	g.push(30);
	g.push(20);
	g.push(5);
	g.push(1);

	cout << "The priority queue g is : ";
	while (!g.empty())
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
	cout << "\ngquiz.top() : " << g.top();

    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);

    cout << "The stack is : ";

	while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
	return 0;
}
