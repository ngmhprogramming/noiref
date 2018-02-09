struct node {
	int start, end, middle, value = 0, lazy = 0;
	node *left, *right;
	node(int _start, int _end){
		start = _start, end = _end; middle = (start+end)/2;
		if(start != end){
			left = new node(start, middle);
			right = new node(middle+1, end);
		}
	}
	void point_update(int P, int V){ //single update
		if(start == end){ value = V; return;}
		if(P > middle) right->point_update(P, V);
		if(P <= middle) left->point_update(P, V);
		value = min(left->value, right->value);
	}
	void range_update(int X, int Y, int change){ //lazy propogation only
		if(start == X && end == Y) lazy += change;
		else {
			if(X > middle) right->range_update(X, Y, change);
			else if(Y <= middle) left->range_update(X, Y, change);
			value = min(left->point_query(), right->point_query());
		}
	}
	int point_query(){ //lazy propogation only
		if(start == end){ value += lazy; lazy = 0; return value;}
		value += lazy;
		right->lazy += lazy; left->lazy += lazy;
		lazy = 0;
		return value;
	}
	int range_query(int A, int B){ //query range from A to B inclusive
		point_query(); //lazy propogation only
		if(start == A && end == B) return value;
		if(A > middle) return right->range_query(A, B);
		if(B <= middle) return left->range_query(A, B);
		return min(left->range_query(A, middle), right->range_query(middle+1, B)); //in this case this segment tree stores the minimum
	}
} *root;
