/**
 * Author: Fakhoury
 * Date: 2023
 * License: CC0
 * Source: -
 * Description: Busca em largura, com implementacao com fila.
 * Time: $O(N + M)$
 * Status: stress-tested
 */
#pragma once

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
int dist[MAXN];

void bfs(int s) { // vertice para iniciar a busca
   dist[s] = 1;
   queue<int> qu;
   qu.emplace(s);
   while(!qu.empty()) {
      int u = qu.front();
      qu.pop();
      for (int v : edges[u]) if (!dist[u]) {
         dist[v] = dist[u] + 1;
         qu.emplace(v);
      }
   }
}