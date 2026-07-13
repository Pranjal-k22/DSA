class Solution {
public:
    bool isPalindrome(ListNode* head) {

        int count = 0;
        ListNode* temp = head;
        stack<int> st;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        temp = head;

        int n = count / 2;

        while(n--){
            st.push(temp->val);
            temp = temp->next;
        }

        if(count % 2 == 1)
            temp = temp->next;

        while(temp != NULL){
            if(temp->val != st.top())
                return false;

            st.pop();
            temp = temp->next;
        }

        return true;
    }
};