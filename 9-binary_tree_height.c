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
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (max(left_height, right_height) + 1);
}
