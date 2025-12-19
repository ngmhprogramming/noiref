struct node {
	int start, end, middle, value = 0, lazy = 0;
	node *left, *right;
	node(int _start, int _end){
		start = _start, end = _end; middle = (start+end)/2;
		if(start != end){ //if node is not a leaf, create child nodes
			left = new node(start, middle);
			right = new node(middle+1, end);
		}
	}
	void point_update(int P, int V){ //single update
		if(start == end){ value = V; return;} //if leaf node, just change current node
		if(P > middle) right->point_update(P, V); //right child
		if(P <= middle) left->point_update(P, V); //left childe
		value = min(left->value, right->value); //node should be minimum of children
	}
	void range_update(int X, int Y, int change){ //lazy propogation only
		if(start == X && end == Y) lazy += change; //update current lazy value
		else {
			if(X > middle) right->range_update(X, Y, change); //if right child is affected
			else if(Y <= middle) left->range_update(X, Y, change); // if left child is affected
			value = min(left->point_query(), right->point_query()); //node should be minimum of children
		}
	}
	int point_query(){ //lazy propogation only
		if(start == end){ value += lazy; lazy = 0; return value;} //update own value
		value += lazy; //update own value
		right->lazy += lazy; left->lazy += lazy; //propogate update to children
		lazy = 0; //rest lazy value
		return value;
	}
	int range_query(int A, int B){ //query range from A to B inclusive
		point_query(); //lazy propogation only
		if(start == A && end == B) return value;
		if(A > middle) return right->range_query(A, B); //if right child is affected
		if(B <= middle) return left->range_query(A, B); //if left child is affected
		return min(left->range_query(A, middle), right->range_query(middle+1, B)); //return overall minimum
	}
} *root;

//int main()
root = new node(0, n-1) //this means it will have n nodes
