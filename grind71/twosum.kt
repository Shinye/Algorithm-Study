// solution 1: brute force - time complexity: O(n^2)
// class Solution {
//     fun twoSum(nums: IntArray, target: Int): IntArray {
//         for (i in 0 until nums.size) {
//             for (j in i+1 until nums.size) {
//                 if (nums[i] + nums[j] == target) {
//                     return intArrayOf(i,j)
//                 }
//             }
//         }
//         return intArrayOf()
//     }
// }

// solution 2: hash map - time complexity: O(n)
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val hashMap = HashMap<Int, Int>()

        for (i in nums.indices) {
            val complement = target - nums[i]
            if (hashMap[complement] != null) {
                return intArrayOf(i, hashMap[complement]!!)
            }
            hashMap[nums[i]] = i
        }

        return intArrayOf()
    }
}
