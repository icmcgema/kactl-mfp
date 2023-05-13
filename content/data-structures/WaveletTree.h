/**
 * Author: Andre Fakhoury
 * Date: 2022-10-11
 * License: CC0
 * Source: ?
 * Description: Various queries on range. Can also be used to toggle if add a BIT on each node. Change order of input array on constructor.
 * Usage:
 * waveletTree T(a+1, a+n+1, 0, all.size());
 * Time: $O(n \log |\Sigma|)$
 * Status: To be tested
 */
#pragma once

struct waveletTree {
	int lo, hi, mi;
	waveletTree *L, *R; // children
	vector<int> mp; // mapLeft

#define mapLeft(i) (mp[i])
#define mapRight(i) (i - mapLeft(i))
	// *beg points to the first element, *end points to after the last element (just like stl default functions).
	// Elements are in range [lo..hi], inclusive
	waveletTree(int *beg, int *end, int lo, int hi) {
		L = R = NULL;
		this->lo = lo, this->hi = hi;
		this->mi = (lo + hi) / 2;

		mp.reserve(end - beg + 1);
		mp.push_back(0);
		for (auto it = beg; it != end; it++)
			mp.push_back(mp.back() + ((*it) <= mi));

		if (lo != hi) {
			auto pivot = stable_partition(beg, end, [&](int x) {
				return x <= mi; }); // split the vector
			L = new waveletTree(beg, pivot, lo, mi);
			R = new waveletTree(pivot, end, mi + 1, hi);
		}
	}
	// K-th smallest element on range[l..r]
	int kthSmallest(int k, int l, int r) {
		if (l > r) return -1; // out of bounds
		if (lo == hi) return lo; // leaf node

		int inL = mapLeft(r) - mapLeft(l-1);
		if (k <= inL)
			return L->kthSmallest(k, mapLeft(l-1)+1, mapLeft(r));
		else
			return R->kthSmallest(k-inL, mapRight(l-1)+1, mapRight(r));
	}
	// Frequency of elements between [x..y] in array[l..r]
	int rngCnt(int x, int y, int l, int r) {
		if (l > r || lo > y || hi < x) return 0; // out of bounds
		if (lo >= x && hi <= y) return r - l + 1; // total fit

		if (mi >= y)
			return L->rngCnt(x, y, mapLeft(l-1)+1, mapLeft(r));
		else if (mi <= x)
			return R->rngCnt(x, y, mapRight(l-1)+1, mapRight(r));
		else return L->rngCnt(x, mi, mapLeft(l-1)+1, mapLeft(r)) +
			   R->rngCnt(mi+1, y, mapRight(l-1)+1, mapRight(r));
	}
	// Swap elements a[i] and a[i+1]
	void swapContiguous(int i) {
		if (lo == hi) return; // leaf node, no need to swap

		// iLeft: if a[i] <= mi; i1Left: if a[i+1] <= mi
		bool iLeft = mapLeft(i) == mapLeft(i-1) + 1; 
		bool i1Left = (mapLeft(i+1)) == (mapLeft(i) + 1);
		if (iLeft && !i1Left) mapLeft(i)--;
		else if (!iLeft && i1Left) mapLeft(i)++;
		else if (iLeft && i1Left) L->swapContiguous(mapLeft(i));
		else R->swapContiguous(mapRight(i));
	}
	// Push element k to end of array 
	void push_back(int k) {
		mp.push_back(mp.back() + (k <= mi));
		if (lo != hi) {
			if (k <= mi) L->push_back(k);
			else R->push_back(k);
		}
	}
	// Pop element k from the end of array
	void pop_back(int k) {
		mp.pop_back();
		if (lo != hi) {
			if (k <= mi) L->pop_back(k);
			else R->pop_back(k);
		}
	}
	~waveletTree() { if (L) delete L; if (R) delete R; }
};