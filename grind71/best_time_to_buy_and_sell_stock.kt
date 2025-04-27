class Solution {
    // time complexity: O(N^2) / space complexity: O(1)
    fun maxProfitBruteForce(prices: IntArray): Int {
        val list = prices.toList()
        val size = list.size
        var result: Int? = null

        // until은 0 <= N < size 다!
        for (i in 0 until size) {
            for (j in i+1 until size) {
                val profit = list[j] - list[i]
                if (profit > 0) {
                    if (result == null || profit > result ?: 0) {
                        result = profit
                    }
                }
            }
        }

        return result ?: 0
    }

    // time complexity: O(N) / space complexity: O(1)
    fun maxProfitOnWay(prices: IntArray): Int {
        var minPrice = Int.MAX_VALUE
        var maxProfit = 0

        for (price in prices) {
            if (price < minPrice) {
                minPrice = price
            } else {
                if ((price - minPrice) > maxProfit) {
                    maxProfit = price - minPrice
                }
            }
        }

        return maxProfit
    }
}

