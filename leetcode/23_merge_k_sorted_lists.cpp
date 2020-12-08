// O(kN)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *sorted = new ListNode(0);
        ListNode *head = sorted;
        while(true){
            int minIndx = -1;
            int minVal = 10001;
            for(int i=0;i<k;i++){
                // update
                if(lists[i] && lists[i]->val < minVal){
                    minIndx = i;
                    minVal = lists[i]->val;
                }
            }
            if(minIndx==-1)break;
            head -> next = new ListNode(minVal);
            head = head -> next;
            lists[minIndx] = lists[minIndx] -> next;
        }
        return sorted->next;
    }
};

// O(Nlogk)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *sorted = new ListNode(0);
        ListNode *head = sorted;
        
        priority_queue<pair<int, ListNode*>>pq;
        for(int i=0;i<k;i++){
            if(lists[i])
                pq.push(make_pair(-lists[i]->val, lists[i]));
        }
        while(!pq.empty()){
            pair<int, ListNode*> pi = pq.top();
            pq.pop();
            
            head->next = new ListNode(-pi.first);
            head = head->next;
            pi.second = pi.second->next;
            if(pi.second)
                pq.push(make_pair(-pi.second->val, pi.second));
        }
        return sorted->next;
    }
};
