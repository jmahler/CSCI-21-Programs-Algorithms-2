#pragma once

/**
 * BSTNode is a node used with the BSTree structure.
 */
template <class T>
class BSTNode
{
	private:

		T data;
		BSTNode* left;
		BSTNode* right;

		/* A data value must always be defined.
		 * To prevent it from deing undefined the
		 * default constructor is made private.
		 */
		BSTNode() {};

	public:

		/**
		 * Construct a new BSTNode.
		 * A value must be given to initialize the node.
		 *
		 * @arg new data value
		 */
		BSTNode(T newData)
		{
			data = newData;

			left = NULL;
			right = NULL;
		}

		~BSTNode() {}

		/**
		 * Set the stored data value.
		 *
		 * @arg data value
		 */
		void setData(T& newData)
		{
			data = newData;
		}

		/**
		 * Get the stored data value.
		 *
		 * This version of getData() returns a reference which can 
		 * be modified to alter the stored value.
		 *
		 * @returns data value
		 */
		T& getData()
		{
			return data;
		}

		/**
		 * Get the stored data value.
		 *
		 * @returns data value
		 */
		T getData() const
		{
			return data;
		}

		/**
		 * Set the LEFT BSTNode of this object.
		 * Can be set to NULL if there is no node on the LEFT.
		 *
		 * @arg BSTNode
		 */
		void setLeft(BSTNode* newLeft)
		{
			left = newLeft;
		}

		/**
		 * Get the left BSTNode.
		 * This version returns a reference which can be modified.
		 *
		 * @returns BSTNode
		 */
		BSTNode*& getLeft()
		{
			return left;
		}

		/**
		 * Get the left BSTNode.
		 *
		 * @returns BSTNode
		 */
		BSTNode* getLeft() const
		{
			return left;
		}

		/**
		 * Get the right BSTNode.
		 * This version returns a reference which can be modified.
		 *
		 * @returns BSTNode
		 */
		BSTNode*& getRight()
		{
			return right;
		}

		/**
		 * Get the right BSTNode.
		 *
		 * @returns BSTNode
		 */
		BSTNode* getRight() const
		{
			return right;
		}

		/**
		 * Test whether one BSTNode is LESS than another by comparing
		 * their data values.
		 *
		 * @arg BSTNode a
		 * @arg BSTNode b
		 *
		 * @returns true if a < b, false otherwise
		 */
		friend bool operator<(const BSTNode<T>& a, const BSTNode<T> b) {
			return (a.getData() < b.getData());
		}

		/**
		 * Test whether one BSTNode is GREATER than another by comparing
		 * their data values.
		 *
		 * @arg BSTNode a
		 * @arg BSTNode b
		 *
		 * @returns true if a > b, false otherwise
		 */
		friend bool operator>(const BSTNode<T>& a, const BSTNode<T> b) {
			return (b > a);
		}

		/**
		 * Test whether one BSTNode is EQUAL to another by comparing
		 * their data values.
		 *
		 * @arg BSTNode a
		 * @arg BSTNode b
		 *
		 * @returns true if a == b, false otherwise
		 */
		friend bool operator==(const BSTNode<T>& a, const BSTNode<T> b) {
			return (a.getData() == b.getData());
		}

		/**
		 * Test whether one BSTNode is less than or equal to another by comparing
		 * their data values.
		 *
		 * @arg BSTNode a
		 * @arg BSTNode b
		 *
		 * @returns true if a <= b, false otherwise
		 */
		friend bool operator<=(const BSTNode<T>& a, const BSTNode<T> b) {
			return ((a < b) || (a == b)) ;
		}

		/**
		 * Test whether one BSTNode is greater than or equal to another
		 * by comparing their data values.
		 *
		 * @arg BSTNode a
		 * @arg BSTNode b
		 *
		 * @returns true if a >= b, false otherwise
		 */
		friend bool operator>=(const BSTNode<T>& a, const BSTNode<T> b) {
			return (b <= a);
		}

};

