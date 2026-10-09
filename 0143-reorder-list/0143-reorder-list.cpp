/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int l=0;
        int r=arr.size()-1;
        
        while(l<=r){
            if (l == r) {
                temp->val = arr[l];
                break;
            }
            temp->val=arr[l];
            temp=temp->next;
            
            temp->val=arr[r];
            temp=temp->next;
            l++;
            r--;
        }
    }
};