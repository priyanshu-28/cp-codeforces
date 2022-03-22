#define V_SUM_MAX 1000
#define N_MAX 1000
#define W_MAX 1000000
 
// To store the states of DP
int dp[V_SUM_MAX + 1][N_MAX];
bool v[V_SUM_MAX + 1][N_MAX];

int solveDp(int r, int i, vector<int>& w, vector<int>& val, int n)
{
    // Base cases
    if (r <= 0)
        return 0;
    if (i == n)
        return W_MAX;
    if (v[r][i])
        return dp[r][i];
 
    // Marking state as solved
    v[r][i] = 1;
 
    // Recurrence relation
    dp[r][i]
        = min(solveDp(r, i + 1, w, val, n),
              w[i] + solveDp(r - val[i],
                             i + 1, w, val, n));
    return dp[r][i];
}
 
// Function to return the maximum weight
int maxWeight(vector<int>& w, vector<int>& val, int n, int c)
{
 
    // Iterating through all possible values
    // to find the the largest value that can
    // be represented by the given weights
    for (int i = V_SUM_MAX; i >= 0; i--) {
        if (solveDp(i, 0, w, val, n) <= c) {
            return i;
        }
    }
    return 0;
}