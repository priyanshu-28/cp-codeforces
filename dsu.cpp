vector<long long> parent(2e5 + 1);
vector<long long> siz(2e5 + 1);

int find_set(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]);

}

void make_set(int n)
{
    For(i, 1, n + 1)
    {
        parent[i] = i;
        siz[i] = 1;

    }

}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);

        parent[b] = a;
        siz[a] += siz[b];

    }

}
