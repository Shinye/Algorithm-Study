// s와 t가 anagram인지 확인하는 것의 핵심은, 둘의 알파벳 구성이 모두 같아야 한다는 것이다.
class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        // 소팅이 왜 nLogn인지 잘 모르겠음.
        /* 
        // ㅋㅋㅋ O(NLogN+MLogM)
        val foo = s.toList().sorted()
        val bar = t.toList().sorted()

        return foo == bar
        */

        // Approach2: Frequency counter - hash table 자료구조 사용
        // hash table 자료구조를 사용하여, 각 문자열 별로 나오는 알파벳을 키로, 등장 빈도(?)를 숫자로 저장한다.
        // 이 때, 하나 등장하면 하나 빼는 구조임..??
        // 즉, 알파벳 별 0이 아닌 값이 하나라도 존재하면 다른 것.
        // val map: MutableMap<Char, Int> = mutableMapOf()
        // s.forEach { map[it] = map.getOrDefault(it, 0) + 1 }
        // t.forEach { map[it] = map.getOrDefault(it, 0) - 1 }

        // return map.all { it.value == 0 }

        // Approach 2-2: Frequency counter - IntArray를 생성 & 각 문자열의 char을 숫자로 변환
        // char - 'a' 를 하면 숫자로 변환됨

        val array = IntArray(26) // 총 알파벳 개수는 26개. IntArray를 생성하면 26개의 0 원소를 가진 배열로 초기화됨
        s.forEach { array[it - 'a']++ }
        t.forEach { array[it - 'a']-- }
        return array.all { it == 0 }

    }
}