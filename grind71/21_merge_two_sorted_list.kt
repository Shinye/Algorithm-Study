/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

/*
* solution1: 재귀 / 시간복잡도 O(N+M) / 공간복잡도 O(N+M)
- LinkedList의 특성상, head의 값만 알면 나머지 배열을 모두 알 수 있다.
- 따라서 각 ListNode의 head만을 비교하며 둘 중 무엇이 작은지 판단하며 작은것부터 list에 추가하고, 
l1, l2 둘 중 하나가 null이 될 때 까지 반복한다. -> 예를 들어 l1이 null이 되면 l2의 head만 넣으면 끝
*/
class Solution1 {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        if (list1 == null) { // 만약 list1이 null이면 list2를 반환한다
            return list2
        } else if (list2 == null) { // 만약 list2가 null이면 list1를 반환한다
            return list1
        } else if (list1.`val` < list2.`val`) { // list1.val < list2.val 인 경우, list1.val이 선정. list1.next는 (list1.next, list2)와 비교해서 작은 값이 될 것.
            list1.next = mergeTwoLists(list1.next, list2)
            return list1
        } else { // list1.val >= list2.val 인 경우, list2.val이 선정. list2.next는 (list1, list2.next)와 비교해서 작은 값이 될 것
            list2.next = mergeTwoLists(list1, list2.next)
            return list2
        }
    }
}

/*
* solution2: iteration / 시간복잡도 O(N+M) / 공간복잡도 O(1)
- LinkedList의 특성상, head의 값만 알면 나머지 배열을 모두 알 수 있다. 그리고 tail은 가장 마지막이다.
- 따라서 각 ListNode의 head만을 비교하며 둘 중 무엇이 작은지 판단하고, 그 값을 해당 linkedList의 tail에 집어넣는다.
l1과 l2 모두 null이 될 때 까지 반복한다.
    */
class Solution2 {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        // prehead는 병합 리스트의 시작점을 고정해두기 위한 더미 노드
        var prehead = ListNode(-1)
        // prev는 현재의 노드 위치를 저장하기 위한 포인터. prev는 prehead에서 시작해서, 병합된 노드들을 하나씩 연결해 나감
        // prev는 prehead와 동일한 head 노드를 바라보고있다.
        var prev = prehead
        var l1 = list1
        var l2 = list2

        // list1과 list2가 모두 null이 아닐 때 까지 loop를 돈다
        while (l1 != null && l2 != null) {
            if (l1.`val` < l2.`val`) {
                prev.next = l1
                l1 = l1.next
            } else {
                prev.next = l2
                l2 = l2.next
            }
            // 새로운 노드를 연결할 때마다 prev = prev.next 해서 한 칸 앞으로 이동
            prev = prev.next
        }

        if (list1 != null) {
            prev.next = l1
        } else {
            prev.next = l2
        }
        // prehead 첫번째 노드는 초기값이 들어있으므로 무시하고 그 다음걸 줘야한다. 따라서 prehead.next를 반환한다. 
        return prehead.next
    }
}