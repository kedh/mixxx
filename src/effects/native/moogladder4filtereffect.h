#ifndef MOOGLADDER4FILTEREFFECT_H
#define MOOGLADDER4FILTEREFFECT_H

#include "effects/effect.h"
#include "effects/effectprocessor.h"
#include "engine/effects/engineeffect.h"
#include "engine/effects/engineeffectparameter.h"
#include "engine/enginefiltermoogladder4.h"
#include "sampleutil.h"
#include "util.h"
#include "util/defs.h"
#include "util/types.h"



struct MoogLadder4FilterGroupState {
    MoogLadder4FilterGroupState();
    ~MoogLadder4FilterGroupState();
    void setFilters(int sampleRate, double lowFreq, double highFreq);

    CSAMPLE* m_pBuf;
    EngineFilterMoogLadder4Low* m_pLowFilter;
    EngineFilterMoogLadder4High* m_pHighFilter;

    double m_loFreq;
    double m_resonance;
    double m_hiFreq;
    double m_samplerate;

};

class MoogLadder4FilterEffect : public GroupEffectProcessor<MoogLadder4FilterGroupState> {
  public:
    MoogLadder4FilterEffect(EngineEffect* pEffect, const EffectManifest& manifest);
    virtual ~MoogLadder4FilterEffect();

    static QString getId();
    static EffectManifest getManifest();

    // See effectprocessor.h
    void processGroup(const QString& group,
                      MoogLadder4FilterGroupState* pState,
                      const CSAMPLE* pInput, CSAMPLE *pOutput,
                      const unsigned int numSamples,
                      const unsigned int sampleRate,
                      const EffectProcessor::EnableState enableState,
                      const GroupFeatureState& groupFeatures);

  private:
    QString debugString() const {
        return getId();
    }

    EngineEffectParameter* m_pLPF;
    EngineEffectParameter* m_pResonance;
    EngineEffectParameter* m_pHPF;

    DISALLOW_COPY_AND_ASSIGN(MoogLadder4FilterEffect);
};

#endif /* MOOGLADDER4FILTEREFFECT_H */
