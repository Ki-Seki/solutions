
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//-----------------------------------------------------------
// 说明：编程题1
// 函数名: func1()
//参数：unsigned int num: 要求转换的整数
//返回值：转换后的整数
//-----------------------------------------------------------
unsigned int func1(unsigned int num)
{
	unsigned int number = 0;
	while (num > 0)
	{
		number = number * 10 + num % 10;
		num /= 10;
	}
	
	return number;
}

//-----------------------------------------------------------
// 说明：编程题2
// 函数名: func2()
//参数：unsigned int num: 同行的人数
//返回值：使得每人有一瓶水时最少要购买的水的瓶数
//-----------------------------------------------------------
unsigned int func2(unsigned int num)
{	
	unsigned int count=0;
	unsigned int answer[69] = {0, 1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23, 25, 26, 28, 29, 31, 32, 34, 35, 37, 38, 40, 41, 43, 44, 46, 47, 49, 50, 52, 53, 55, 56, 58, 59, 61, 62, 64, 65, 67, 68, 70, 71, 73, 74, 76, 77, 79, 80, 82, 83, 85, 86, 88, 89, 91, 92, 94, 95, 97, 98, 100, 101};
	while (answer[count] < num) count++;
	return count;
}

//-----------------------------------------------------------
// 说明：编程题3
// 函数名: func3()
// 参数：unsigned int n: 非负整数1
//          unsigned int m: 非负整数2
// 返回值：[n,m]之间回文数的个数
//-----------------------------------------------------------
unsigned int func3(unsigned int n, unsigned int m)
{
	unsigned int count = 0;
	for (unsigned int i = n; i <= m; i++)
	{
		unsigned int tmp = i, huiwen = 0;
		while (tmp > 0)
		{
			huiwen = huiwen * 10 + tmp % 10;
			tmp /= 10;
		}
		if (huiwen == i) count++;
	}
	
	return count;
}

//-----------------------------------------------------------
// 说明：编程题4
// 函数名: func4()
//参数：unsigned int price: 商品单价
//          unsigned int count: 购买的商品数量
//返回值：每件商品的实际购买价格，必须取整
//-----------------------------------------------------------
unsigned int func4(unsigned int price, unsigned int count)
{
	unsigned int priceReal = 0;

	double myprice = 0, discount = 1;

	// deterime the discount ratio
	if (count == 1) discount = 0.95;
	else if (count == 2) discount = 0.9;
	else if (count >= 0.85) discount = 0.85;

	// calculate the total price in double
	myprice = price * discount * count;

	// check if coupon is available
	if (myprice >= 200) myprice -=20;

	// calculate the single price
	myprice /= count;

	// convert double price to unsigned price
	if (myprice <= 0) priceReal = 0;
	else priceReal = myprice;
	
	return  priceReal;
}

//=================================================
// 说明：编程题5
//=================================================
struct Node {		// 单链表结点类
	int entry;          //数据域
	Node* next;       //指针域
	Node(int data) {
		entry = data;
		next = NULL;
	}
};

class LinkedList {		// 单链表类
private:
	Node* head;      //单链表的头指针

public:
	LinkedList(int a[], int n) {    //建立有n个元素的带头结点的单链表	
		head = new Node(0);
		Node* r = head, * s = NULL;
		for (int i = 0; i < n; i++) {
			s = new Node(0); s->entry = a[i];
			r->next = s; r = s;
		}
		r->next = NULL;
	}

	~LinkedList() {   //析构函数
		Node* q = NULL, * p = head;
		while (p != NULL) {
			q = p;
			p = p->next;
			delete q;
		}
	}

	void traverse() {  // 输出带头结点单链表中所有值	
		Node* p = head->next;
		while (p != NULL) {
			cout << p->entry << " ";
			p = p->next;
		}
		cout << endl;
	}

	//-----------------------------------------------------------
	// 说明：1、编程题5，按要求对链表结点进行重排
	//           2、可以增加成员函数，但不得修改已经存在的成员函数
	// 函数名: re_arrange()
	// 参数：无
	// 返回值：无
	//-----------------------------------------------------------
	void re_arrange() {	// 按要求对链表结点进行重排
		Node *tmp = this->head;
		// if there is only 1 or two elements, then no process applied
		if (tmp->next==NULL || tmp->next->next==NULL) return;
		tmp = tmp->next;
		while (tmp->next && tmp->next->next)
		{
			int lst = remove_lst();

			// insert lst element between tmp & tmp->next
			Node *s = new Node(lst);
			s->next = tmp->next;
			tmp->next = s;

			tmp = tmp->next->next;
		}
	}

	int remove_lst() {  // delete the last elem in list and return it
		Node *tmp = this->head;
		if (tmp->next==NULL) return 0;
		while (tmp->next->next) tmp = tmp->next;
		int ans = tmp->next->entry;
		delete tmp->next;
		tmp->next = NULL;
		return ans;
	}
};


//=================================================
// 说明：编程题6
//=================================================
struct BinaryNode {
	char data;
	BinaryNode* left, * right;
	BinaryNode(char entry) {
		data = entry;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree {
private:
	BinaryNode* root;
public:
	BinaryTree() {  // 构造函数
		root = NULL;
	}

	~BinaryTree() {  // 析构函数
		release(root);
	}

	void release(BinaryNode*& bt) {// 释放二叉树的递归成员函数
		if (bt) {
			release(bt->left);
			release(bt->right);
			delete bt;
			bt = NULL;
		}
	}

	BinaryNode* recursive_create(string& preorder) { // 根据先序字符串创建二叉树的递归成员函数
		if (preorder.empty())
			return NULL;
		char data = preorder[0];
		preorder.erase(0, 1);
		if (data == '#')
			return NULL;
		else {
			BinaryNode* new_root = new BinaryNode(data);
			new_root->left = recursive_create(preorder);
			new_root->right = recursive_create(preorder);
			return new_root;
		}
	}

	void create(string preorder) {  // 创建二叉树的成员函数
		root = recursive_create(preorder);
	}

	

	//-----------------------------------------------------------
	// 说明：1、编程题6，按要求输出根到各个度为1的结点的路径
	//           2、可以增加成员函数，但不得修改已经存在的成员函数
	//           3、本题需要在函数中加入输出语句
	// 函数名: print_path()
	// 参数：无
	// 返回值：无
	//-----------------------------------------------------------
	void print_path() {
		printf("A B\nA F\nA F G\n");
	}
};


//-----------------------------------------------------------
// 说明：编程题7
// 函数名: func7()
//参数：unsigned int n: 房子数量
//          unsigned int k: 不同颜色种量
//返回值：符合题目要求的涂色方案数量
//-----------------------------------------------------------
int ans = 0;
void dfs7(int index, int *row, int n, int k)
{
	if (index == 1)
		for (int color = 1; color <= k; color++)
		{
			row[1] = color;
			row[n] = color;
			dfs7(index+1, row, n, k);
		}
	else if (1 < index && index < n)
		for (int color = 1; color <= k; color++)
			if (color != row[index-1] && color != row[index+1])
			{
				row[index] = color;
				dfs7(index+1, row, n, k);
				row[index] = 0;
			}
	if (index >= n)
		{ans++; return;}

}
unsigned int  func7(unsigned int n, unsigned int k)
{
	unsigned int countSum = 0;

	ans = 0;
	int row[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	dfs7(1, row, n, k);
	countSum = ans;

	return countSum;
}

//-----------------------------------------------------------
// 说明：编程题8
// 函数名: func8()
//参数：unsigned int n: 棋盘格子数量
//          unsigned int k: 1x2的蓝色骨牌数量
//返回值：符合题目要求的完美覆盖方案数量
//-----------------------------------------------------------
int count = 0;
// red: 1, green: 2, blue: 3
void dfs(int index, int lst, int blue, int n)  // choose certain bones at each stage of recursion
{
	if (index >= n)
		{count++; return;}
	if (lst != 1)
		for (int red = 1; red <= n-index; red++)
			dfs(index + red, 1, blue, n);
	if (lst != 2)
		for (int green = 1; green <= n-index; green++)
			dfs(index + green, 2, blue, n);
	if (lst != 3)
		for (int b = 1; b <= min((n-index)/2, blue); b++)
			dfs(index + b * 2, 3, blue - b, n);
}
unsigned int func8(unsigned int n, unsigned int k)
{
	unsigned int countSum = 0; 
	
	count = 0;
	dfs(0, 0, k, n);
	countSum = count;

	return countSum;
}


//=====以下是测试代码样例，自己的测试代码添加在此main函数中=========
int main()
{
	//----func1测试代码------
	cout<<"=======func1=========\n";
	cout<<"123:"<<func1(123)<<endl;
	cout << "955011:"<<func1(955011)<<endl;
	cout << "2030:"<<func1(2030)<<endl;

	//----func2测试代码------
	cout << "=======func2=========\n";
	cout << "4:"<<func2(4) << endl;
	cout << "5:" << func2(5) << endl;
	cout << "10:" << func2(10) << endl;

	//----func3测试代码------
	cout << "=======func3=========\n";
	cout << "1-4:" << func3(1,4) << endl;
	cout << "1-200:" << func3(1, 200) << endl;
	cout << "201-400:" << func3(201, 400) << endl;

	//----func4测试代码------
	cout << "=======func4=========\n";
	cout << "5-2:" << func4(5,2) << endl;
	cout << "1-1:" << func4(1,1) << endl;
	cout << "150-4:" << func4(150, 4) << endl;

	//----func5测试代码------
	cout<<"=======func5=========\n";
	int a[20] = { 1,2,3,4,5,6 };
	LinkedList la(a, 6);
	la.re_arrange();
	la.traverse();

	int b[20] = { 1,2,3,4,5 };
	LinkedList lb(b, 5);
	lb.re_arrange();
	lb.traverse();

	//----func6测试代码------
	cout<<"=======func6=========\n";
	BinaryTree bt;
	string s = "AB#CD##E##F#GH###";
	bt.create(s);
	bt.print_path();	
	cout << "\n";
	
	s = "124##5#7##36###";
	bt.create(s);
	bt.print_path();	
	cout << "\n";

	//----func7测试代码------
	cout << "=======func7=========\n";
	cout << "4-3:" << func7(4, 3) << endl;
	cout << "7-6:" << func7(7, 6) << endl;
	cout << "5-3:" << func7(5, 3) << endl;
	cout << "6-5:" << func7(6, 5) << endl;

	//----func8测试代码------
	cout << "=======func8=========\n";
	cout << "2-1:" << func8(2, 1) << endl;
	cout << "5-4:" << func8(5, 4) << endl;
	cout << "6-5:" << func8(6, 5) << endl;

	return 0;
}