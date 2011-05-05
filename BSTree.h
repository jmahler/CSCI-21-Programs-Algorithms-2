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
		void _print(BSTNode<T>*& treeRoot, stringstream& ss) {
			if (NULL == treeRoot) {
				// done
			} else {

				_print(treeRoot->getLeft(), ss);

				ss << " " << treeRoot->getData();

				_print(treeRoot->getRight(), ss);
			}
		}
	public:
		/**
		 * Convert the tree to string format suitable for printing.
		 * Values will be in ascending order.
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

		// {{{ clear();
	private:
		void _clear(BSTNode<T>*& treeRoot) {
			if (NULL == treeRoot) {
				// end of branch, DONE
			} else {
				_clear(treeRoot->getLeft());

				_clear(treeRoot->getRight());

				delete treeRoot;
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
			} else if (newData < treeRoot->getData())
					_insert(newData, treeRoot->getLeft());
			else if (newData > treeRoot->getData())
					_insert(newData, treeRoot->getRight());
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

		bool remove();

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
