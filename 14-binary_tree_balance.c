#include "binary_trees.h"

/**
 * max - Returns the maximum of the two numbers
 * @a: First number
 * @b: Second number
 *
 * Return: Maximum of the two numbers
*/
size_t max(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = height(tree->left) + 1;
	right_height = height(tree->right) + 1;

	return (max(left_height, right_height));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (height(tree->left) - height(tree->right));
}
