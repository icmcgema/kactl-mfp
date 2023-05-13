/**
 * Author: Andre Fakhoury
 * Date: 2023
 * License: CC0
 * Source: ?
 * Description: Divide and Conquer pseudocode
 * Time: $O(n \log n)$
 */
#pragma once

// Estrutura basica (pseudocodigo)
int solve(vector<int> a) {
   int n = a.size();
   if (n == 1) return solucao(a);
   
   // divide
   vector<int> vl = a[0..n/2];
   vector<int> vr = a[n/2..n];

   // pega a resposta pra cada metade
   solucao_left = solve(vl);
   solucao_right = solve(vr);

   // "conquista"
   return merge(solucao_left, solucao_right);   
}
