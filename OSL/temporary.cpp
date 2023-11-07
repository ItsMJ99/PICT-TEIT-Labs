#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int tracks = 200;

void sstf(vector<int> req, int n, int dhl)
{
	vector<int> ans;
	int cur = dhl;
	int seek_time = 0;
	vector<int> temp = req;
	ans.push_back(dhl);
	while (!temp.empty())
	{
		int min_val = 99999;
		int min_ind = -1;
		for (int i = 0; i < temp.size(); i++)
		{
			if (min_val > abs(cur - temp[i]))
			{
				min_val = abs(cur - temp[i]);
				min_ind = i;
			}
		}
		cur = temp[min_ind];
		seek_time += min_val;
		ans.push_back(cur);
		temp.erase(temp.begin() + min_ind);
	}
	cout << "Seek Sequence : ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i < ans.size() - 1)
		{
			cout << "->";
		}
	}
	cout << "\n\nTotal Seek Time = " << seek_time << endl;
}

void scan(vector<int> req, int n, int dhl)
{
	string dir;
	cout << "Enter the direction : ";
	cin >> dir;
	vector<int> ans;
	vector<int> left, right;
	ans.push_back(dhl);
	int seek_time = 0;
	if (dir == "left")
	{
		left.push_back(0);
	}
	else
	{
		right.push_back(tracks - 1);
	}
	for (int i = 0; i < req.size(); i++)
	{
		if (req[i] > dhl)
		{
			right.push_back(req[i]);
		}
		else
		{
			left.push_back(req[i]);
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int run = 2;
	while (run--)
	{
		if (dir == "left")
		{
			for (int i = left.size() - 1; i >= 0; i--)
			{
				ans.push_back(left[i]);
				seek_time += abs(dhl - left[i]);
				dhl = left[i];
			}
			dir = "right";
		}
		else
		{
			for (int i = 0; i < right.size(); i++)
			{
				ans.push_back(right[i]);
				seek_time += abs(dhl - right[i]);
				dhl = right[i];
			}
			dir = "left";
		}
	}
	cout << "Seek Sequence : ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i < ans.size() - 1)
		{
			cout << "->";
		}
	}
	cout << "\n\nTotal Seek Time : " << seek_time << endl;
}

void clook(vector<int> req, int n, int dhl)
{
	vector<int> ans;
	int seek_time = 0;
	vector<int> left, right;
	string dir;
	cout << "Enter Direction : ";
	cin >> dir;
	ans.push_back(dhl);
	for (int i = 0; i < req.size(); i++)
	{
		if (req[i] > dhl)
		{
			right.push_back(req[i]);
		}
		else
		{
			left.push_back(req[i]);
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	if (dir == "left")
	{
		for (int i = left.size() - 1; i >= 0; i--)
		{
			ans.push_back(left[i]);
			seek_time += abs(dhl - left[i]);
			dhl = left[i];
		}
		for (int i = right.size() - 1; i >= 0; i--)
		{
			ans.push_back(right[i]);
			seek_time += abs(dhl - right[i]);
			dhl = right[i];
		}
	}
	else
	{
		for (int i = 0; i < right.size(); i++)
		{
			ans.push_back(right[i]);
			seek_time += abs(dhl - right[i]);
			dhl = right[i];
		}
		for (int i = 0; i < left.size(); i++)
		{
			ans.push_back(left[i]);
			seek_time += abs(dhl - left[i]);
			dhl = left[i];
		}
	}

	cout << "Seek Sequence : ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i < ans.size() - 1)
		{
			cout << "->";
		}
	}
	cout << "\n\nTotal Seek Time : " << seek_time << endl;
}

int main()
{
	int n, dhl;
	cout << "Enter the Number of Requests : ";
	cin >> n;
	cout << "Enter the Initial Disk Head Location : ";
	cin >> dhl;
	vector<int> req(n);
	cout << "Enter the Requests : ";
	for (int i = 0; i < n; i++)
	{
		cin >> req[i];
	}
	int c = 0, ch;
	while (c == 0)
	{
		cout << "----------MENU----------" << endl;
		cout << "0.Exit\n1.SSTF\n2.SCAN\n3.C-LOOK\n"
			 << endl;
		cout << "Enter your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 0:
			c = 1;
			break;

		case 1:
			sstf(req, n, dhl);
			break;
		case 2:
			scan(req, n, dhl);
			break;
		case 3:
			clook(req, n, dhl);
			break;
		default:
			cout << "Invalid Input !!!" << endl;
			break;
		}
	}
	return 0;
}