#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int ds = 200;

void scan(int n, int head, vector<int> &req, string dir)
{
	vector<int> ans;
	int seek_time = 0;
	vector<int> left, right;
	if (dir == "left")
	{
		left.push_back(0);
	}
	else
	{
		right.push_back(ds - 1);
	}

	for (int i = 0; i < n; i++)
	{
		if (req[i] < head)
		{
			left.push_back(req[i]);
		}
		else
		{
			right.push_back(req[i]);
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
				int cur = left[i];
				ans.push_back(left[i]);
				int dis = abs(cur - head);
				seek_time += dis;
				head = cur;
			}
			dir = "right";
		}
		else
		{
			for (int i = 0; i < right.size(); i++)
			{
				int cur = right[i];
				ans.push_back(right[i]);
				int dis = abs(cur - head);
				seek_time += dis;
				head = cur;
			}
			dir = "left";
		}
	}
	cout << "Seek sequence: ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	cout << "Total seek time: " << seek_time << endl;
}

void clook(int n, int head, vector<int> &req)
{
	vector<int> ans;
	int seek_time = 0;
	vector<int> left, right;
	for (int i = 0; i < n; i++)
	{
		if (req[i] < head)
		{
			left.push_back(req[i]);
		}
		else
		{
			right.push_back(req[i]);
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	for (int i = 0; i < right.size(); i++)
	{
		int cur = right[i];
		ans.push_back(cur);
		int dis = abs(cur - head);
		seek_time += dis;
		head = cur;
	}
	seek_time += abs(head - left[0]);
	head = left[0];
	for (int i = 0; i < left.size(); i++)
	{
		int cur = left[i];
		ans.push_back(cur);
		int dis = abs(cur - head);
		seek_time += dis;
		head = cur;
	}

	cout << "Seek sequence: ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	cout << "Total seek time: " << seek_time << endl;
}

void sstf(int n, int head, vector<int> &req)
{
	vector<int> ans;
	int cur = head;
	int seek_time = 0;
	vector<int> temp = req;
	ans.push_back(head);
	while (!temp.empty())
	{
		int mini = INT_MAX;
		int min_ind = -1;
		for (int i = 0; i < temp.size(); i++)
		{
			int seekt = abs(cur - temp[i]);
			if (seekt < mini)
			{
				mini = seekt;
				min_ind = i;
			}
		}
		seek_time += mini;
		cur = temp[min_ind];
		ans.push_back(cur);
		temp.erase(temp.begin() + min_ind);
	}
	cout << "Seek Sequence: ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	cout << "Total seek time: " << seek_time << endl;
}
int main()
{
	int n;
	cout << "Enter the number of requests: ";
	cin >> n;
	int head;
	cout << "Enter the initial disk head: ";
	cin >> head;
	vector<int> req(n);
	cout << "Enter the request: ";
	for (int i = 0; i < n; i++)
	{
		cin >> req[i];
	}
	int flag = 1;
	while (flag)
	{
		cout << "**************MENU****************\n";
		cout << "1.SSTF\n";
		cout << "2.SCAN\n";
		cout << "3.C-LOOK\n";
		cout << "4.Exit\n";
		cout << "************************************\n";
		int ch;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			sstf(n, head, req);
			break;
		}
		case 2:
		{
			string dir;
			cout << "Enter the direction in which we have to process: ";
			cin >> dir;
			scan(n, head, req, dir);
			break;
		}
		case 3:
		{
			clook(n, head, req);
			break;
		}
		case 4:
		{
			flag = 0;
			break;
		}
		}
	}
	return 0;
}