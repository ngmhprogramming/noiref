vector<int> v;
v.push_back(0);
v.front(); //0
v.back(); //0
v.pop_back();

queue<int> q;
q.push(0);
q.front(); //0
q.pop();

priority_queue<int> pq;
pq.push(0)
pq.top(); //0
pq.pop();

deque<int> dq;
dq.push_front(0);
dq.front(); //0
dq.push_back(1);
dq.back(); //1
dq.pop_front();
dq.pop_back();

set<int> s;
s.insert(0);
s.find(0); // Pointer to 0's position
s.erase(0);

multiset<int> ms;
ms.insert(0);
ms.insert(0);
ms.count(0); //2
ms.find(0); //Pointer to a 0's position
ms.erase(ms.find(0)); //Erase a 0
ms.erase(0); //Erase all 0s

map<int, int> m;
m[0] = 1;
m[1] = 2;

typedef tree<pi, null_type, less<pi>, //User a pair to simulate multisets
		     rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set os;
os.insert(1);
os.insert(2);
os.insert(4);
os.insert(8);
os.insert(16);
//Find by order - Kth largest (starting from 0)
os.find_by_order(1)<<endl; // 2
os.find_by_order(2)<<endl; // 4
os.find_by_order(4)<<endl; // 16
//Order of key - How many are < K
os.order_of_key(-5)<<endl;  // 0
os.order_of_key(1)<<endl;   // 0
os.order_of_key(3)<<endl;   // 2
os.order_of_key(4)<<endl;   // 2
os.order_of_key(400)<<endl; // 5