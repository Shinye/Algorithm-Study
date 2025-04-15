// https://leetcode.com/problems/valid-parentheses/

class Solution {
    // 12ms | time complexity: O(n) | space complexity: O(n)

    fun isValid(s: String): Boolean {
        // 각 close 괄호에 매핑되는 open괄호 map 생성
        val parenthesesMap = mapOf<String, String>(
            ")" to "(",
            "}" to "{",
            "]" to "["
        )
        // stack을 생성한다
        val stringStack: Stack<String> = Stack()
        // 문자열 loop 돈다
        s.forEach {
            val char = it.toString()
            // 주어진 차례의 문자가 close 타입이며 stack에서 pop되는 문자가 이에 상응하는 open타입이면 stack pop
            if (parenthesesMap[char] != null && stringStack.last() == parenthesesMap[char]) {
                stringStack.pop()
            } else {
                // 아닐경우 stack push
                stringStack.push(char)
            }
        }

        // stack이 비어있으면 true, 아니면 false
        if (stringStack.isEmpty()) {
            return true
        } else {
            return false
        }
    }
}

// 이하 장난.. 시간초과 남 ㅋㅋㅋ
// time complex O(n^2) / space complex O(n)
class Solution {
    fun isValid(s: String): Boolean {
        while (s.contains("()") || s.contains("[]") || s.contains("{}")) {
            if (s.contains("()")) {
                s.replace("()", "")
            }
            if (s.contains("[]")) {
                s.replace("[]", "")
            }
            if (s.contains("{}")) {
                s.replace("{}", "")
            }
        }

        return s == ""
    }
}