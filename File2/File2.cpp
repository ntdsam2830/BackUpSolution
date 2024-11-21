#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

char findTheDifference(string s, string t) {
    int n = s.length();
    int m = t.length();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            return t[i];

        }
    }
    return t.back();
};

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> numMap; //kh?i t?o hashmap
	int n = nums.size(); 

	for (int i = 0; i < n; ++i) {
		int temp = target - nums[i]; //t�m ph?n t? c?n t�m b?ng c�ch duy?t qua m?ng, l?y ph?n t? trong m?ng tr? ?i target
		if (numMap.count(temp)) { //t�m xem temp ?� c� trong hashmap ch?a
			return { numMap[temp],i }; //n?u c� t?c l� ?� t?n t?i ch? s? t?o n�n target
		}
		numMap[nums[i]] = i; //n?u ch?a, l?u v�o hashmap v� ti?p t?c t�m ki?m ph?n c�n l?i
	}
	return {};//tr? v? r?ng n?u kh t�m ?c 
}

vector<int> twoSumII(vector<int>& arr, int target) {
    vector<pair<int, int>>res;
    for (int i = 0; i < arr.size(); i++)
    {
        int l = i, r = arr.size() - 1;
        while (l < r)
        {
            int sum = arr[l] + arr[r];
            if (sum == target)
            {
                res.push_back({ l,r });
                break;
            }
            else if (sum < target)
            {
                l++;
            }
            else {
                r--;
            }
        }
        break;
    }
    vector<int>ans;
    for (auto i : res)
    {
        ans.push_back(i.first + 1);
        ans.push_back(i.second + 1);
    }
    return ans;
}

int findTiles(int N, int M) {
	int x = sqrt(4 * M + N);
	if (x % 2 == 0) {
		return x;
	}
	else {

	}
}

bool isValid(string s) {
	stack<char> stack;
	for (char c : s) {
		if (c == '(' || c == '{' || c == '[') {
			stack.push(c);
		}
		else {
			if (stack.empty()) return false;
			char top = stack.top();
			stack.pop();
			if ((c == ')' && top != '(') ||
				(c == '}' && top != '{') ||
				(c == ']' && top != '[')) {
				return false;
			}
		}
	}
	return stack.empty();

}

bool isPalindrome(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (start <= end) {
		if (!isalnum(s[start])) {
			start++;
		}
		else if (!isalnum(s[end])) {
			end--;
		}
		else if (tolower(s[start]) != tolower(s[end])) return false;
		else {
			start++;
			end--;
		}
	}
	return true;
}

bool isAnagram(string s, string t) {
	int count[26] = { 0 };

	if (s.size() != t.size()) return false;

	for (char x : s) {
		count[x - 'a']++;
	}

	for (char x : t) {
		count[x - 'a']--;
	}

	for (int val : count) {
		if (val != 0)return false;
	}

	return true;
}


vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> mp;

	for (auto x : strs) {
		string word = x;
		sort(word.begin(), word.end());
		mp[word].push_back(x);
	}

	vector<vector<string>> ans;
	for (auto x : mp) {
		ans.push_back(x.second);
	}
	return ans;
}


int orangesRotting(vector<vector<int>>& grid)
{
	vector<int> dir = { -1,0,1,0,-1 }; //used for finding all 4 adjacent coordinates

	int m = grid.size();
	int n = grid[0].size();

	queue<pair<int, int>> q;
	int fresh = 0; //To keep track of all fresh oranges left
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 2)
				q.push({ i,j });
			if (grid[i][j] == 1)
				fresh++;
		}
	int ans = -1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
	while (!q.empty())
	{
		int sz = q.size();
		while (sz--)
		{
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int r = p.first + dir[i];
				int c = p.second + dir[i + 1];
				if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
				{
					grid[r][c] = 2;
					q.push({ r,c });
					fresh--; // decrement by 1 foreach fresh orange that now is rotten
				}

			}
		}
		ans++; //incremented after each minute passes
	}
	if (fresh > 0) return -1; //if fresh>0 that means there are fresh oranges left
	if (ans == -1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
	return ans;

}

int countDistinct(vector<int>& A) {
	unordered_map<int, bool> element_map; // Map to store unique elements
	for (int num : A) {
		element_map[num] = true; // Insert the element into the map
	}
	return element_map.size(); // Return the number of unique keys
}


long long maximumSubarraySum(vector<int>& nums, int k) {
	long long res = 0;
	unordered_map<int, int> prev_index;
	long long cur_sum = 0;

	int temp = 0;

	for (int i = 0; i < nums.size(); i++) {
		cur_sum += nums[i];

		int j = -1;
		if (prev_index.find(nums[i]) != prev_index.end()) {
			j = prev_index[nums[i]];
		}

		while (temp <= j || i - temp + 1 > k) {
			cur_sum -= nums[temp];
			temp++;
		}

		if (i - temp + 1 == k) {
			res = max(res, cur_sum);
		}

		prev_index[nums[i]] = i;
	}
	return res;
}

int takeCharacters(string s, int k) {
	vector<int> count(3, 0);
	int n = s.length();

	for (char c : s) {
		count[c - 'a']++;
	}

	if (count[0] < k || count[1] < k || count[2] < k) return -1;

	vector<int> curr(3, 0);
	int maxLen = 0;
	int left = 0;

	for (int right = 0; right < n; right++) {
		curr[s[right] - 'a']++;

		while (left <= right && (curr[0] > count[0] - k || curr[1] > count[1] - k || curr[2] > count[2] - k)) {
			curr[s[left] - 'a']--;
			left++;
		}

		maxLen = max(maxLen, right - left + 1);
	}
	return n - maxLen;
}

int brackets(string& S) {
	// Implement your solution here
	stack<char> brackets;

	unordered_map<char, char> matching = {
		{')','('},
		{'}','{'},
		{']','['}
	};

	for (char c : S) {
		if (c == '(' || c == '{' || c == '[') {
			brackets.push(c);
		}
		else {
			if (brackets.empty() || brackets.top() != matching[c]) return 0;
			brackets.pop();
		}
	}

	return brackets.empty() ? 1 : 0;
}

int maxNonoverlappingSegments(vector<int>& A, vector<int>& B) {
	// Implement your solution here
	int N = A.size();
	if (N == 0) return 0;

	int count = 1; //at least 1 segment is choosen
	int lastEnd = B[0]; //the ending point of the last choosen segment

	for (int i = 0; i < N; i++) {
		if (A[i] > lastEnd) {
			count++;
			lastEnd = B[i];
		}
	}

	return count;
}

int main() {
	vector<int> nums = { 1,5,4,2,9,9,9 };
	string S = "aabaaaacaabc";
	string a = "([)()]";
	string s = "anagram";
	string t = "nagaram";
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<int>> grid = { {2, 1, 1},{1, 2, 0},{0, 1, 1} };
	cout << brackets(a);
	//groupAnagrams(strs);
	//cout << isValid(a);
	//vector<int> nums{ 2,4,6,7,11,15 };
	//int target = 9;
	//auto v=twoSumII(nums, target);
	/*for (int i = 0; i < strs.size(); i++)
		cout << strs[i] << " ";
	return 0;*/

}