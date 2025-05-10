// /**
//  * Example:
//  * var ti = TreeNode(5)
//  * var v = ti.`val`
//  * Definition for a binary tree node.
//  * class TreeNode(var `val`: Int) {
//  *     var left: TreeNode? = null
//  *     var right: TreeNode? = null
//  * }
//  */
class Solution1 {
    fun invertTree(root: TreeNode?): TreeNode? {
        if (root == null) {
            return null
        }

        val left = invertTree(root.left)
        val right = invertTree(root.right)
        root.left = right
        root.right = left

        return root
    }
}

class Solution2 {
    fun invertTree(root: TreeNode?): TreeNode? {
        if (root != null) {
            val queue: Queue<TreeNode> = LinkedList()
            queue.add(root)

            while (queue.isNotEmpty()) {
                val currentNode = queue.poll()
                val temp = currentNode.left
                currentNode.left = currentNode.right
                currentNode.right = temp

                if (currentNode.left != null) { queue.add(currentNode.left) }
                if (currentNode.right != null) { queue.add(currentNode.right) }
            }

        }

        return root
    }
}