/**
 * Author: Fakhoury
 * Date: 2023
 * License: CC0
 * Source: -
 * Description: Busca em profundidade, com implementacao recursiva.
 * Time: $O(N + M)$
 * Status: stress-tested
 */
#pragma once

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
bool vis[MAXN];

void dfs(int u) {
   vis[u] = true;
   for (int v : edges[u]) if (!vis[v]) {
      dfs(v);
   }
}