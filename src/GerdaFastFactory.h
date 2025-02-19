/* GerdaFastFactory.h
 *
 * Author: Luigi Pertoldi
 * Created: Tue 18 Jun 2019
 *
 */
#include "vector"

#include "TH1.h"
#include "TRandom3.h"

#ifndef _GERDA_FAST_FACTORY_H
#define _GERDA_FAST_FACTORY_H

class GerdaFastFactory {

    public:

    // delete dangerous constructors
    GerdaFastFactory           (GerdaFastFactory const&) = delete;
    GerdaFastFactory& operator=(GerdaFastFactory const&) = delete;

    // custom constructor
    GerdaFastFactory();
    ~GerdaFastFactory();

    void SetCountsRange(float xmin, float xmax);
    void AddComponent(const TH1* hist, const float counts);
    TH1* GetPseudoExp();

    private:

    TRandom3 _rndgen;
    TH1* _model;
    std::pair<float, float> _range;
};

#endif
