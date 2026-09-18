class Solution 
{
    public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {        
        // get the size of the LL
        int size = getSizeOfLL(head);

        // LL size: 10, k = 3
        // standardSize = 10 / 3 = 3
        int standardSize = size / k;
        // number of groups that have (standardSize + 1 ) node
        int plusOneCount = size % k;

        // walk to the end of each LL chunk and memorize the starting node for the next chunk
        // cut it off and push to res
        vector<ListNode*> res;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = head;

        int currSize = 0;
        while (curr && plusOneCount > 0) {
            currSize++;

            if (currSize == standardSize+1) {
                plusOneCount--;
                ListNode* nextStart = curr->next;
                curr->next = nullptr; // cut off
                res.push_back(dummy->next);
                dummy->next = nextStart;
                curr = nextStart;
                currSize = 0;
                continue;
            }
            curr = curr->next;
        }
        // done pushing all the plusOne groups
        currSize = 0;
        while (curr && standardSize > 0) {
            currSize++;
            
            if (currSize == standardSize) {
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
        while (res.size() < k) {
            res.push_back(nullptr);
        }
        return res;
    }

    private:
    int getSizeOfLL(ListNode* head)
    {
        ListNode* curr = head;
        int res = 0;
        while (curr) {
            res++;
            curr = curr->next;
        }
        return res;
    }
};