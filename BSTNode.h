#pragma once

template <class T>
class BSTNode
{
	private:

		T data;
		BSTNode* left;
		BSTNode* right;

		/* A data value must always be defined for
		 * a node, no the default constructor is made
		 * private to prevent this situation.
		 */
		BSTNode() {};

	public:

		BSTNode(T newData)
		{
			data = newData;

			left = NULL;
			right = NULL;
		}

		~BSTNode() {}

		void setData(T& newData)
		{
			data = newData;
		}

		T& getData()
		{
			return data;
		}

		T getData() const
		{
			return data;
		}

		void setLeft(BSTNode* newLeft)
		{
			left = newLeft;
		}

		BSTNode*& getLeft()
		{
			return left;
		}

		BSTNode* getLeft() const
		{
			return left;
		}

		BSTNode*& getRight()
		{
			return right;
		}

		BSTNode* getRight() const
		{
			return right;
		}

		friend bool operator<(const BSTNode<T>& a, const BSTNode<T> b) {
			return (a.getData() < b.getData());
		}

		friend bool operator>(const BSTNode<T>& a, const BSTNode<T> b) {
			return (b > a);
		}

		friend bool operator==(const BSTNode<T>& a, const BSTNode<T> b) {
			return (a.getData() == b.getData());
		}

		friend bool operator<=(const BSTNode<T>& a, const BSTNode<T> b) {
			return ((a < b) || (a == b)) ;
		}

		friend bool operator>=(const BSTNode<T>& a, const BSTNode<T> b) {
			return (b <= a);
		}

};

