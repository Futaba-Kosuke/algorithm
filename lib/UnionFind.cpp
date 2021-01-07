struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int get_root (int x) {
        if (par[x] == x) return x;
        return par[x] = get_root(par[x]);
    }

    void unite (int x, int y) {
        int rx = get_root(x);
        int ry = get_root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool is_same (int x, int y) {
        int rx = get_root(x);
        int ry = get_root(y);
        return rx == ry;
    }
};
