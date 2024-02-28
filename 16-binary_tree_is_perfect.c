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
 * is_perfect_binary_tree - Recursively checks if the binary tree is perfect
 * @tree: Pointer to the node of the tree
 * @height: Height of the binary tree
 * @level: the level
 *
 * Return: 1 if the binary tree is perfect, otherwise 0
 */
int is_perfect_binary_tree(const binary_tree_t *tree, int height, int level)
{
	if (tree == NULL)
	{
		return (0);
	}

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (level == height);
	}

	return (is_perfect_binary_tree(tree->left, height, level + 1) &&
			is_perfect_binary_tree(tree->right, height, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_height = height(tree);

	return (is_perfect_binary_tree(tree, tree_height, 1));
}
