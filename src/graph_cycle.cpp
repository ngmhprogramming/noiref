// detect cycle
int slow = s, fast = s;
do {
	slow = nxt[slow];
	fast = nxt[nxt[fast]];
} while (slow != fast);
// find start of cycle
slow = start;
while (slow != fast) {
	slow = nxt[slow];
	fast = nxt[fast];
}
// collect all nodes in cycle
vector<int> cycle;
int cur = slow;
do {
	cycle.push_back(cur);
	cur = nxt[cur];
} while (cur != slow);