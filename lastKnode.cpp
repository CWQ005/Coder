/**
*Problem:
*输入一个链表，输出该链表中倒数第k个结点。
*
*struct ListNode {
*	int val;
*	struct ListNode *next;
*	ListNode(int x) :
*			val(x), next(NULL) {
*	}
*};
*Note:
*① 输入的pListHead可能为空指针；
*② 输入的以pListHead为头结点的链表的节点总数小于k；
*③ 输入的k可能为0；
*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k==0)return NULL;
        ListNode* p1 = pListHead;
        ListNode* p2 = pListHead;
        for(int i=0;i<k-1;i++){
            if(p2->next!=NULL)p2=p2->next;
            else return NULL;
        }
        while(p2->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};