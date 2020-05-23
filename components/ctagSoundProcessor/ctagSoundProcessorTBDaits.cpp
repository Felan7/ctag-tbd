/***************
CTAG TBD >>to be determined<< is an open source eurorack synthesizer module.

A project conceived within the Creative Technologies Arbeitsgruppe of
Kiel University of Applied Sciences: https://www.creative-technologies.de

(c) 2020 by Robert Manzke. All rights reserved.

The CTAG TBD software is licensed under the GNU General Public License
(GPL 3.0), available here: https://www.gnu.org/licenses/gpl-3.0.txt

The CTAG TBD hardware design is released under the Creative Commons
Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0).
Details here: https://creativecommons.org/licenses/by-nc-sa/4.0/

CTAG TBD is provided "as is" without any express or implied warranties.

License and copyright details for specific submodules are included in their
respective component folders / files if different from this license.
***************/

#include "ctagSoundProcessorTBDaits.hpp"
#include <iostream>
#include "esp_heap_caps.h"
#include "esp_log.h"
#include "helpers/ctagFastMath.hpp"

using namespace CTAG::SP;

ctagSoundProcessorTBDaits::ctagSoundProcessorTBDaits() {
    setIsStereo();
    model = std::make_unique<ctagSPDataModel>(id, isStereo);
    model->LoadPreset(0);

    shared_buffer = (char *) heap_caps_malloc(16384, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
    if (shared_buffer == NULL) {
        ESP_LOGE("Plaits", "Could not allocate shared buffer!");
    }
    stmlib::BufferAllocator allocator(shared_buffer, 16384);
    voice.Init(&allocator);

    patch.engine = 0;
    patch.lpg_colour = 0.5f;
    patch.decay = 0.5f;
}

void ctagSoundProcessorTBDaits::Process(const ProcessData &data) {
    patch.note = frequency / 4095.f * 96.f;

    if (cv_lpg_decay != -1) {
        patch.decay = HELPERS::fastfabs(data.cv[cv_lpg_decay]);
    } else {
        patch.decay = lpg_decay / 4095.f;
    }

    patch.harmonics = harmonics / 4095.f;

    if (cv_lpg_color != -1) {
        patch.lpg_colour = HELPERS::fastfabs(data.cv[cv_lpg_color]);
    } else {
        patch.lpg_colour = lpg_color / 4095.f;
    }

    patch.timbre = timbre / 4095.f;
    patch.morph = morph / 4095.f;
    patch.morph_modulation_amount = mod_morph / 4095.f;
    patch.frequency_modulation_amount = mod_freq / 4095.f;
    patch.timbre_modulation_amount = mod_timbre / 4095.f;
    patch.engine = smodel;

    plaits::Modulations modulations;

    if (cv_smodel != -1) {
        modulations.engine = HELPERS::fastfabs(data.cv[cv_smodel]);
    } else {
        modulations.engine = 0.f;
    }

    if (cv_frequency != -1) {
        modulations.note = data.cv[cv_frequency] * 5.f * 12.f;
    } else {
        modulations.note = 0.f;
    }

    if (cv_mod_freq != -1) {
        modulations.frequency_patched = true;
        modulations.frequency = data.cv[cv_mod_freq] * 30.f;
    } else {
        modulations.frequency_patched = false;
        modulations.frequency = 0.f;
    }

    if (cv_harmonics != -1) {
        modulations.harmonics = data.cv[cv_harmonics];
    } else {
        modulations.harmonics = 0.f;
    }

    if (cv_mod_timbre != -1) {
        modulations.timbre = data.cv[cv_mod_timbre];
        modulations.timbre_patched = true;
    } else {
        modulations.timbre = 0.f;
        modulations.timbre_patched = false;
    }

    if (cv_mod_morph != -1) {
        modulations.morph = data.cv[cv_mod_morph];
        modulations.morph_patched = true;
    } else {
        modulations.morph = 0.f;
        modulations.morph_patched = false;
    }

    if (trig_trigger != -1) {
        modulations.trigger_patched = true;
        modulations.trigger = data.trig[trig_trigger] != 1;
    } else {
        modulations.trigger_patched = false;
        modulations.trigger = false;
    }

    float fLevel = 1.f;
    if (cv_level != -1) {
        modulations.level = HELPERS::fastfabs(data.cv[cv_level]);
        modulations.level_patched = true;
    } else {
        fLevel = level / 4095.f;
        modulations.level_patched = false;
    }

    // get frame
    plaits::Voice::Frame out[bufSz];
    voice.Render(patch, modulations, out, bufSz);

    // convert
    for (int i = 0; i < bufSz; i++) {
        data.buf[i * 2] = out[i].out / 32768.f * fLevel;
        data.buf[i * 2 + 1] = out[i].aux / 32768.f * fLevel;
    }
}

ctagSoundProcessorTBDaits::~ctagSoundProcessorTBDaits() {
    heap_caps_free(shared_buffer);
}

const char *ctagSoundProcessorTBDaits::GetCStrID() const {
    return id.c_str();
}


void ctagSoundProcessorTBDaits::setParamValueInternal(const string &id, const string &key, const int val) {
// autogenerated code here
// sectionCpp0
    if (id.compare("smodel") == 0) {
        if (key.compare("current") == 0) {
            smodel = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_smodel = val;
        }
        return;
    }
    if (id.compare("trigger") == 0) {
        if (key.compare("current") == 0) {
            trigger = val;
            return;
        } else if (key.compare("trig") == 0) {
            if (val >= -1 && val <= 1)
                trig_trigger = val;
        }
        return;
    }
    if (id.compare("frequency") == 0) {
        if (key.compare("current") == 0) {
            frequency = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_frequency = val;
        }
        return;
    }
    if (id.compare("level") == 0) {
        if (key.compare("current") == 0) {
            level = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_level = val;
        }
        return;
    }
    if (id.compare("harmonics") == 0) {
        if (key.compare("current") == 0) {
            harmonics = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_harmonics = val;
        }
        return;
    }
    if (id.compare("timbre") == 0) {
        if (key.compare("current") == 0) {
            timbre = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_timbre = val;
        }
        return;
    }
    if (id.compare("morph") == 0) {
        if (key.compare("current") == 0) {
            morph = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_morph = val;
        }
        return;
    }
    if (id.compare("lpg_color") == 0) {
        if (key.compare("current") == 0) {
            lpg_color = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_lpg_color = val;
        }
        return;
    }
    if (id.compare("lpg_decay") == 0) {
        if (key.compare("current") == 0) {
            lpg_decay = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_lpg_decay = val;
        }
        return;
    }
    if (id.compare("mod_freq") == 0) {
        if (key.compare("current") == 0) {
            mod_freq = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_mod_freq = val;
        }
        return;
    }
    if (id.compare("mod_timbre") == 0) {
        if (key.compare("current") == 0) {
            mod_timbre = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_mod_timbre = val;
        }
        return;
    }
    if (id.compare("mod_morph") == 0) {
        if (key.compare("current") == 0) {
            mod_morph = val;
            return;
        } else if (key.compare("cv") == 0) {
            if (val >= -1 && val <= 3)
                cv_mod_morph = val;
        }
        return;
    }
// sectionCpp0









}

void ctagSoundProcessorTBDaits::loadPresetInternal() {
// autogenerated code here
// sectionCpp1
    smodel = model->GetParamValue("smodel", "current");
    cv_smodel = model->GetParamValue("smodel", "cv");
    trigger = model->GetParamValue("trigger", "current");
    trig_trigger = model->GetParamValue("trigger", "trig");
    frequency = model->GetParamValue("frequency", "current");
    cv_frequency = model->GetParamValue("frequency", "cv");
    level = model->GetParamValue("level", "current");
    cv_level = model->GetParamValue("level", "cv");
    harmonics = model->GetParamValue("harmonics", "current");
    cv_harmonics = model->GetParamValue("harmonics", "cv");
    timbre = model->GetParamValue("timbre", "current");
    cv_timbre = model->GetParamValue("timbre", "cv");
    morph = model->GetParamValue("morph", "current");
    cv_morph = model->GetParamValue("morph", "cv");
    lpg_color = model->GetParamValue("lpg_color", "current");
    cv_lpg_color = model->GetParamValue("lpg_color", "cv");
    lpg_decay = model->GetParamValue("lpg_decay", "current");
    cv_lpg_decay = model->GetParamValue("lpg_decay", "cv");
    mod_freq = model->GetParamValue("mod_freq", "current");
    cv_mod_freq = model->GetParamValue("mod_freq", "cv");
    mod_timbre = model->GetParamValue("mod_timbre", "current");
    cv_mod_timbre = model->GetParamValue("mod_timbre", "cv");
    mod_morph = model->GetParamValue("mod_morph", "current");
    cv_mod_morph = model->GetParamValue("mod_morph", "cv");
// sectionCpp1









}
