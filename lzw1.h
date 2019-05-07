#include<bits/stdc++.h>
using namespace std;
string LZW(string input, int option)
{
	if (option == 1)
	{
		Node *dictionary = new Node;
		string result;
		int length, last_seen, index = 128;

		st_Node(dictionary, 32, " ");
		for (int i = 33; i < 128; i++)
		{
			string data;
			data = i;
			insert_Node(dictionary, i, data);
		}

		length = (int)input.length();

		for (int i = 0; i < length; i++)
		{
			Node *searched;
			string search;
			search = input[i];

		re_search:
			searched = search_Node(dictionary, search);
			if (searched)
			{
				i++;
				search += input[i];
				last_seen = searched->index;
				if (i != length)
					goto re_search;
				else
					goto print;
			}
			else
			{
				insert_Node(dictionary, index, search);
				index++;
			print:
				result += to_string(last_seen) + " ";
				i--;
			}
		}

		return result;
	}
	if (option == 2)
	{
		Node *dictionary = new Node;
		string result;
		int index = 128;

		st_Node(dictionary, 32, " ");
		for (int i = 33; i < 128; i++)
		{
			string data;
			data = i;
			insert_Node(dictionary, i, data);
		}

		vector <string> s_input = split(input, ' ');
		for (int i = 0; i < s_input.size(); i++)
		{
			Node *searched;
			int search;
			search = stoi(s_input[i]);

			searched = search_Node(dictionary, search);

			string cur, prev, data;
			if (searched)
				cur = search_Node(dictionary, stoi(s_input[i]))->data;
			if (i != 0)
				prev = search_Node(dictionary, stoi(s_input[i - 1]))->data;
			else
				prev = cur;

			int show = 0;
			if (searched)
			{
				result += searched->data;

				if (i != 0)
				{
					data = prev + cur[0];
					if (show != 1)
					{
						insert_Node(dictionary, index, data);
						index++;
					}
				}
				show = 0;
			}
			else
			{
				data = prev + prev[0];
				insert_Node(dictionary, index, data);
				index++;
				show = 1;
				result += data;
			}
		}

		return result;
	}
}
