// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



template<typename T>
class binary_tree
{
public:
	binary_tree();
	~binary_tree();
	int size();
	void in_order();
	void insert(T _data);

private:
	class Node
	{
	public:
		Node(T _data = T(), Node* _left = nullptr, Node* _right = nullptr);
		~Node();
		T data;
		Node* left;
		Node* right;

	private:

	};
	Node* root; 
	int Size;
	void in_order_rec(Node* node);
	Node* insert_rec(Node* node, T _data)
	{
		if (node == nullptr)
			return new Node(_data);
		else if (node->data > _data)
		{
			node->left = insert_rec(node->left, _data);
		}
		else
		{
			node->right = insert_rec(node->right, _data);
		}
		return node;
	}


};

template<typename T>
binary_tree<T>::binary_tree()
{
	this->root = nullptr;
	this->Size = 0;
}

template<typename T>
binary_tree<T>::~binary_tree()
{
}

template<typename T>
int binary_tree<T>::size()
{
	return this->Size;
}

template<typename T>
void binary_tree<T>::in_order()
{
	in_order_rec(root);
}

template<typename T>
void binary_tree<T>::insert(T _data)
{
	root = insert_rec(root, _data);
}

template<typename T>
void binary_tree<T>::in_order_rec(Node* node)
{
	if (node != nullptr)
	{
		in_order_rec(node->left);
		std::cout << node->data << ' ';
		in_order_rec(node->right);
	}
}






template<typename T>
binary_tree<T>::Node::Node(T _data , Node* _left, Node* _right)
{
	this->data = _data;
	this->left = _left;
	this->right = _right;
}

template<typename T>
binary_tree<T>::Node::~Node()
{
}






int main()
{
	binary_tree<int> bt;
	std::cout << bt.size() << std::endl;
	bt.insert(5);
	bt.insert(6);
	bt.insert(4);
	bt.insert(3);
	bt.insert(5);
	bt.insert(5);
	bt.insert(7);
	bt.insert(7);
	bt.insert(8);
	bt.insert(8);
	bt.insert(9);
	bt.insert(9);
	bt.insert(0);
	bt.insert(2);
	bt.insert(2);
	bt.in_order();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
