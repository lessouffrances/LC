

// math intuition
// larger sizes first
// 
class Solution 
{
    public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        // get the size of the LL
        int size = getSizeOfLL(head);

        // LL size 
        int standardSize = size / k;
        // number of groups that have (standardSize+1) elements
        int plusOneCount = size % k;

        vector<ListNode*> res;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = head;

        int currSize = 0;
        while (curr && plusOneCount > 0) {
            currSize++;
            if (currSize == standardSize+1) {
                plusOneCount--;
                // memorize nextStart 
                ListNode* nextStart = curr->next;
                curr->next = nullptr; 
                res.push_back(dummy->next);
                dummy->next = nextStart;
                curr = nextStart;
                currSize = 0;
                continue;
            }
            curr = curr->next;
        }

        currSize = 0;
        while (curr) {
            currSize++;
            if (currSize == standardSize) {
                // memorize nextStart 
                ListNode* nextStart = curr->next;
                curr->next = nullptr; 
                res.push_back(dummy->next);
                dummy->next = nextStart;
                curr = nextStart;
                currSize = 0;
                continue;
            }
            curr = curr->next;
        }

        while (res.size() < k)
        {
            res.push_back(nullptr);
        }
        return res;
    }

    private:
    int getSizeOfLL(ListNode* head)
    {
        if (!head) return 0;
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        return size;
    }
};
