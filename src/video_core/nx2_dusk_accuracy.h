// SPDX-FileCopyrightText: Copyright 2026 Lichii Dusk Updated contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <cstdlib>

#include "common/common_types.h"
#include "common/logging.h"
#include "common/settings.h"

// A deliberately slow, title-scoped rendering diagnostic for The Duskbloods.
// It is opt-out (EDEN_NX2_DUSK_ACCURACY=0), but can never affect another title.
namespace VideoCommon::DuskAccuracy {

inline constexpr u64 DuskbloodsProgramId = 0x0400D1D02399A000ULL;
inline void ReadSwitch() {
    const char* value = std::getenv("EDEN_NX2_DUSK_ACCURACY");
    const bool requested = value == nullptr || value[0] != '0';
    const u64 program_id = Settings::GetCurrentProgramID();
    const bool enabled = requested && program_id == DuskbloodsProgramId;
    Settings::SetDuskbloodsRenderAccuracy(enabled);

    if (enabled) {
        LOG_WARNING(HW_GPU,
                    "Duskbloods render-accuracy experiment ENABLED: synchronous GPU submission, "
                    "high-accuracy memory synchronization and conservative NX2 paths; "
                    "performance will be substantially lower");
    } else if (program_id == DuskbloodsProgramId) {
        LOG_INFO(HW_GPU, "Duskbloods render-accuracy experiment disabled by EDEN_NX2_DUSK_ACCURACY=0");
    }
}

[[nodiscard]] inline bool Enabled() {
    return Settings::DuskbloodsRenderAccuracy();
}

} // namespace VideoCommon::DuskAccuracy
