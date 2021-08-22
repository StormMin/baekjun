#include <iostream>
#include <vector>

using namespace std;

int n, from, to, parent[100001], check[100001];
vector<int> v[100001];

void DFS(int start) {
	check[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!check[next]) {
			parent[next] = start;
			DFS(next);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	DFS(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
}