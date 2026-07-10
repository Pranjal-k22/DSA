/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        map<ListNode*, int> mpp;
        while(temp!=NULL){
            mpp[temp] = 1;
            temp=temp->next;
        }
        ListNode* tempB=headB;
        while(tempB!=NULL){
            if(mpp.find(tempB)!=mpp.end()){
                return tempB;
            }
            mpp[tempB]=1;
            tempB=tempB->next;
        }
        return NULL;

    }
};