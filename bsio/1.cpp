// Find a linked list in a binary tree

const int mxn = 1e5+1;
int lps[mxn];

bool dfs(Tree* root, int len, vector<int>& lst) {
    if(!root) return false;
    while(len > 0 && lst[len] != root->val) len = lps[len-1];
    if(root->val == lst[len]) ++len;
    if(len == (int)lst.size()) return true;
    return dfs(root->left, len, lst) || dfs(root->right, len, lst);
}

bool solve(Tree* root, LLNode* head) {
    vector<int> lst;
    for(LLNode* t_head = head; t_head; t_head = t_head->next)
        lst.push_back(t_head->val);
    
    const int m = lst.size();
    if(m == 0) return true;
    memset(lps, 0, sizeof(int) * (m + 1));

    int len = 0;
    for(int i=1; i<m; ++i) {
        while(len > 0 && lst[i] != lst[len]) len = lps[len-1];
        if(lst[i] == lst[len]) ++len;
        lps[i] = len;
    }

    return dfs(root, 0, lst);
}
