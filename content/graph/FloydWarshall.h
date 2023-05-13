/**
 * Author: Fakhoury
 * Date: 2023
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
 * Description: Calcula a distsancia minima entre todos os pares de vertices em um grafo direcionado e ponderado (suporta tambem arestas negativas).
 * A matriz de input $m$ possui o valor das arestas $i,j$ em $m[i][j]$, e $m[i][j] = \texttt{inf}$ se $i$ e $j$ nao sao adjacentes.
 * Como output, $m[i][j]$ possui a distancia minima entre $i$ e $j$, e \texttt{inf} se nao ha caminho.
 * Time: O(N^3)
 * Status: slightly tested
 */
#pragma once

ll m[MAXN][MAXN];

void floydWarshal() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (m[i][j] > m[i][k] + m[k][j])
					m[i][j] = m[i][k] + m[k][j];
}
