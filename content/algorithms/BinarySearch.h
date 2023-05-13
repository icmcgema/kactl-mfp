/**
 * Author: Andre Fakhoury
 * Date: 2023
 * License: CC0
 * Source: ?
 * Description: Binary search on the answer
 * Time: $O(\log (hi - lo))$
 */
#pragma once

bool check(int k) { // int ou double
   // check se pode realizar a operacao com K
}

// dada uma funcao que retorna 0 0 0 0 0 1 1 1 1..
// retorna a posicao que ocorre o primeiro 1
int binary_search1(int n) {
	// trocar o LO e HI por valores limite
	int lo = 0, hi = n - 1, mi; 
	while(lo < hi) {
		mi = (lo + hi) / 2;
		if (check(mi)) hi = mi;
		else lo = mi + 1;
	}
	return lo;
}


// dada uma funcao que retorna 1 1 1 1 1 0 0 0 0...
// retorna a posicao que ocorre o ultimo 1
int binary_search2(int n) {
	// trocar o LO e HI por valores limite
	int lo = 0, hi = n - 1, mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(mi)) lo = mi;
		else hi = mi - 1;
	}
	return lo;
}

// codigo para double
double binary_search() {
	const double EPS = 1e-9; // limiar de erro aceitavel

	double lo = 0, hi = 1e9, mi;
	while(hi - lo > EPS) {
		mi = (lo + hi) / 2;
		// nao esqueca de trocar tipo do check para double
		if (check(mi)) lo = mi;
		else hi = mi;
	}
	return lo;
}
