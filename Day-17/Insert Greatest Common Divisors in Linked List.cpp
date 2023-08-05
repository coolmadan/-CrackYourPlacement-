class Solution {
public:
    int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*node=head;
        while(node!=NULL){
            int a=node->val;
            if(node->next!=NULL){
                ListNode*node2=node->next;
                int b=node2->val;
                int g=gcd(a,b);
                ListNode*newNode =new ListNode(g);
                node->next=newNode;
                newNode->next=node2;
                node=node2;
            }else
                node=node->next;
            
            
        }
        return head;
    }
};
