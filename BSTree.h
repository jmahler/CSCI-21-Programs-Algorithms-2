#pragma once

#include <sstream>
#include <string>

#include "BSTNode.h"

using namespace std;

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

		// {{{ prints()
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
			if (NULL == treeRoot) {
				// end of branch, DONE
			} else {
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
		bool _remove(BSTNode<T>*& treeRoot, const T& rmValue) {
			if (NULL == treeRoot) {
				return false;  // value not found
			} else {
				if (rmValue == treeRoot->getData()) {
					// value to remove found!
					BSTNode<T>* left = treeRoot->getLeft();	
					BSTNode<T>* right = treeRoot->getRight();	

					delete treeRoot;
					treeRoot = NULL;
					count--;

					if (NULL == left && NULL == right) {
						// nothing to reconnect
					} else if (NULL == left) {
						treeRoot = right;
					} else if (NULL == right) {
						treeRoot = left;
					}

					return true;
				} else if (rmValue < treeRoot->getData()) {
					return _remove(treeRoot->getLeft(), rmValue);
				} else { // rmValue > data
					return _remove(treeRoot->getRight(), rmValue);
				}
			}
		}
	public:	
		/**
		 * Remove a value from the tree.
		 *
		 * @returns true if value was found and removed, false otherwise
		 */
		bool remove(const T& rmValue) {
			return _remove(root, rmValue);
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
		 *
		 */
		bool find(const T& data) {
			return _find(root, data);
			return true;
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
		 * Works like find() except it returns the value instead of true/false.
		 *
		 * @arg data value to find
		 *
		 * @returns true if found, false otherwise.
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
