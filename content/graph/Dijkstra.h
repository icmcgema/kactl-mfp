/**
 * Author: Fakhoury
 * Date: 2023
 * License: CC0
 * Source: -
 * Description: Caminho mínimo a partir de um vértice para todos os outros em um grafo ponderado.
 * Time: $O((N+M)\log n)$
 * Status: stress-tested
 */
#pragma once

const int MAXN = 1e5 + 5;

vector<pair<int, int>> edges[MAXN]; // edges[u] = {pair(v, w)}
ll dist[MAXN];

void dijkstra(int s) { // vertice para iniciar a busca
   memset(dist, 0x3f, sizeof dist); // inicializa todo mundo com INF

   dist[s] = 0;
   priority_queue<pair<ll, int>> pq;
   pq.emplace(0, 0);
   while(!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (-d > dist[u]) continue;

      for (auto [v, w] : edges[u]) if (dist[v] > dist[u] + w) {
         dist[v] = dist[u] + w;
         pq.emplace(-dist[v], v);
      }
   }
}