/* Copyright (c) 2010 Guillaume Collet
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE. 
 */

#ifndef __TRIDENT_H__
#define __TRIDENT_H__

#include "statistic.h"

class TridStat : public Statistic {
private:
	int ncol;
	int N;
	vector<float> w;					/**< Weight of each sequence in the msa (size = nb sequences) */
	vector<float> t;					/**< t(x) = Shannon entropy score  + Weighted sequence Score */
	vector<float> r;					/**< r(x) = Stereochemical score */
	vector<float> g;					/**< g(x) = Gap Score */
	vector<float> col_cons;		/**< Conservation score = (1-t(x))^a * (1- r(x))^b * (1-g(x))^c */
	
	float calcSeqWeight(Msa & msa, int i);
	float normVect(vector<float> vect);
	
public:
	void calculateStatistic(Msa & msa);
};

#endif

