// 328. Odd Even Linked List @ 2022/12/06

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* evenHead = head->next, *oddTail = head, *evenTail = evenHead, *next = evenTail->next;
        bool isOdd = true;
        while (next){
            if (isOdd)
                oddTail->next = next, oddTail = next;
            else
                evenTail->next = next, evenTail = next;
            next = next->next;
            isOdd = !isOdd;
        }

        oddTail->next = evenHead, evenTail->next = nullptr;
        return head;
    }
};
