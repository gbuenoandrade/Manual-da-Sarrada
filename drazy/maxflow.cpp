const int NN = 250;
int cap[NN][NN], deg[NN], adj[NN][NN];
int q[NN], prv[NN];

int dinic(int n, int s, int t) {
    int flow = 0;
    CLR(deg);
    FOR0(u,n) FOR0(v,n) {
    	if(cap[u][v] || cap[v][u]) adj[u][deg[u]++] = v;
    }
    while(true) {
    	SET(prv);
        int qf = 0, qb = 0;
        prv[q[qb++] = s] = -2;
        while( qb > qf && prv[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prv[v = adj[u][i]] == -1 && cap[u][v] )
                    prv[q[qb++] = v] = u;
        if( prv[t] == -1 ) break;
        FOR0(z,n) if( cap[z][t] && prv[z] != -1 ) {
            int bot = cap[z][t];
            for(int v = z, u = prv[v]; u >= 0; v = u, u = prv[v])
                bot = min(bot, cap[u][v]);
            if(!bot) continue;
            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] ) {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }
    return flow;
}