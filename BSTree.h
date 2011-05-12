#pragma once

#include <sstream>
#include <string>

#include "BSTNode.h"

using namespace std;

/**
 * EmptyTreeError may be thrown by a function that
 * is given an empty tree but requires a populated one.
 * Currently min() and max() use this exception.
 */
struct EmptyTreeError {};

/**
 * A Binary Search Tree (BST) structure.
 */
template <class T>
class BSTree
{
	private:
		BSTNode<T>* root;

		unsigned int count;
	public:
		
		// {{{ BSTree()
		/**
		 * Construct a new empty tree.
		 */
		BSTree() {
			root = NULL;
			count = 0;
		}
		// }}}

		// {{{ ~BSTree()
		virtual ~BSTree() {
			clear();
		};
		// }}}

		// {{{ print()
	private:
		// inorder traversal
		void _print(BSTNode<T>*& treeRoot, stringstream& ss) {
			if (NULL != treeRoot) {
				_print(treeRoot->getLeft(), ss);
				ss << " " << treeRoot->getData();
				_print(treeRoot->getRight(), ss);
			}
		}
	public:
		/**
		 * Traverse the tree in order and produce a string representing
		 * it as a list.
		 *
		 * @returns string
		 */
		string print() {
			stringstream ss;
			ss << " (";
			_print(root, ss);
			ss << " ) ";

			return ss.str();
		}
		// }}}

		// {{{ printr()
	private:
		// reverse order traversal
		void _printr(BSTNode<T>*& treeRoot, stringstream& ss) {
			if (NULL != treeRoot) {
				_printr(treeRoot->getRight(), ss);
				ss << " " << treeRoot->getData();
				_printr(treeRoot->getLeft(), ss);
			}
		}
	public:
		/**
		 * Traverse the tree in REVERSE order and produce a string representing
		 * it as a list.
		 *
		 * @returns string
		 */
		string printr() {
			stringstream ss;
			ss << " (";
			_printr(root, ss);
			ss << " ) ";

			return ss.str();
		}
		// }}}

		// {{{ printp()
	private:
		// pre-order traversal
		void _printp(BSTNode<T>*& treeRoot, stringstream& ss) {
			if (NULL != treeRoot) {
				ss << " " << treeRoot->getData();
				_printp(treeRoot->getLeft(), ss);
				_printp(treeRoot->getRight(), ss);
			}
		}
	public:
		/**
		 * Perform a pre-order traversal of the tree and produce
		 * a string representing it as a list.
		 *
		 * @returns string
		 */
		string printp() {
			stringstream ss;
			ss << " (";
			_printp(root, ss);
			ss << " ) ";

			return ss.str();
		}
		// }}}

		// {{{ printe()
	private:
		// post-order traversal
		void _printe(BSTNode<T>*& treeRoot, stringstream& ss) {
			if (NULL != treeRoot) {
				_printe(treeRoot->getLeft(), ss);
				_printe(treeRoot->getRight(), ss);
				ss << " " << treeRoot->getData();
			}
		}
	public:
		/**
		 * Perform a post-order traversal of the tree and produce
		 * a string representing it as a list.
		 *
		 * @returns string
		 */
		string printe() {
			stringstream ss;
			ss << " (";
			_printe(root, ss);
			ss << " ) ";

			return ss.str();
		}
		// }}}

		// {{{ clear();
	private:
		void _clear(BSTNode<T>*& treeRoot) {
			if (NULL != treeRoot) {
				_clear(treeRoot->getLeft());
				_clear(treeRoot->getRight());

				delete treeRoot;
				treeRoot = NULL;
				count--;
			}
		}	
	public:
		/**
		 * Clear all values from the tree.
		 */
		void clear() {
			_clear(root);
			//count = 0;
		}
		// }}}

		// {{{ insert()
	private:
		void _insert(const T& newData, BSTNode<T>*& treeRoot) {
			if (NULL == treeRoot) {
				treeRoot = new BSTNode<T>(newData);
				count++;
			} else if (newData < treeRoot->getData()) {
				_insert(newData, treeRoot->getLeft());
			} else if (newData > treeRoot->getData()) {
				_insert(newData, treeRoot->getRight());
			}
		}

	public:
		/**
		 * Insert a new value in to the tree.
		 *
		 * @arg T new data
		 */
		void insert(const T& newData) {
			_insert(newData, root);
		}
		// }}}

		// {{{  remove(T&)

	private:

		/*
		 * Starting with the given non-NULL node, find and
		 * remove the maximum value.
		 * The value variable will be assigned the data value
		 * that was removed.
		 */
		void _remove_max(BSTNode<T>*& treeRoot, T& removed) {
			if (NULL == treeRoot->getRight()) {
				// found the maximum

				// save the original root pointer
				BSTNode<T>* oldRoot = treeRoot;

				// get the value
				removed = treeRoot->getData();

				// re-assign the original root pointer
				treeRoot = treeRoot->getLeft();

				// delete the original old pointer
				delete oldRoot;
				oldRoot = NULL;
				count--;
			} else {
				_remove_max(treeRoot->getRight(), removed);
			}
		}

		bool _remove(BSTNode<T>*& treeRoot, const T& target) {
			if (NULL == treeRoot) {
				return false;  // value not found
			} else if (target < treeRoot->getData()) {
				return _remove(treeRoot->getLeft(), target);
			} else if (target > treeRoot->getData()) {
				return _remove(treeRoot->getRight(), target);
			//} else if (target == treeRoot->getData()) {
			} else {
				BSTNode<T>*& left = treeRoot->getLeft();	

				if (NULL == left) {
					BSTNode<T>* oldRoot = treeRoot;

					treeRoot = treeRoot->getRight();

					delete oldRoot;
					oldRoot = NULL;
					count--;
				} else if (NULL != left) {
					T newVal = target;

					// starting with the left non-NULL node,
					// remove the maximum and get the value.
					_remove_max(left, newVal);

					treeRoot->setData(newVal);
				}

				return true;
			}
		}
	public:	
		/**
		 * Remove a value from the tree.
		 *
		 * @returns true if value was found and removed, false otherwise
		 */
		bool remove(const T& target) {
			return _remove(root, target);
		}
		// }}}

		// {{{ find()
	private:
		bool _find(BSTNode<T>*& treeRoot, const T& data) {

			if (NULL == treeRoot) {
				return false;
			} else if (data == treeRoot->getData()) {
				return true;
			} else if (data < treeRoot->getData()) {
				return (_find(treeRoot->getLeft(), data));
			}
			// else
			return (_find(treeRoot->getRight(), data));
		}
	public:
		/**
		 * Find a value in the tree.
		 *
		 * @arg data value to find
		 *
		 * @returns true if found, false otherwise.
		 */
		bool find(const T& data) {
			return _find(root, data);
			return true;
		}
		// }}}

		// {{{ min()
	private:
		T _min(BSTNode<T>*& treeRoot) {
			if (NULL == treeRoot) {
				throw EmptyTreeError();
			} else if (NULL == treeRoot->getLeft()) {
				return treeRoot->getData();
			}
			// else
			return (_min(treeRoot->getLeft()));
		}
	public:
		/**
		 * Find the minimum value in the tree.
		 * The tree must be non-empty otherwise the EmptyTreeError exception
		 * will be thrown.
		 *
		 * @returns value if found, throws EmptyTreeError on error
		 *
		 * @exception EmptyTreeError
		 */
		T min() {
			return _min(root);
		}
		// }}}

		// {{{ max()
	private:
		T _max(BSTNode<T>*& treeRoot) {
			if (NULL == treeRoot) {
				throw EmptyTreeError();
			} else if (NULL == treeRoot->getRight()) {
				return treeRoot->getData();
			}
			// else
			return (_max(treeRoot->getRight()));
		}
	public:
		/**
		 * Find the maximum value in the tree.
		 * The tree must be non-empty otherwise the EmptyTreeError exception
		 * will be thrown.
		 *
		 * @returns value if found, throws EmptyTreeError on error
		 *
		 * @exception EmptyTreeError
		 */
		T max() {
			return _max(root);
		}
		// }}}

		// {{{ getData()
	private:
		T* _getData(BSTNode<T>*& treeRoot, const T& data) {

			if (NULL == treeRoot) {
				return NULL;
			} else if (data == treeRoot->getData()) {
				return &(treeRoot->getData());
			} else if (data < treeRoot->getData()) {
				return (_getData(treeRoot->getLeft(), data));
			}
			// else
			return (_getData(treeRoot->getRight(), data));
		}
	public:
		/**
		 * Get a value in the tree.
		 * Works like find() except it returns a pointer to the
		 * value instead of true/false.
		 *
		 * @arg data value to find
		 *
		 * @returns non-NULL pointer if found, NULL otherwise
		 *
		 */
		T* getData(const T& data) {
			return _getData(root, data);
		}
		// }}}

		// {{{ getNodeCount()
		/**
		 * Get the count of the number of nodes in the tree.
		 *
		 * @returns int
		 */
		int getNodeCount() {
			return count;
		}
		// }}}

};

// vim:foldmethod=marker
