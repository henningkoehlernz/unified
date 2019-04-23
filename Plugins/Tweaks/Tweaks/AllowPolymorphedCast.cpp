#include "Tweaks/AllowPolymorphedCast.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* AllowPolymorphedCast::pAddCastSpellActions_hook = nullptr;

AllowPolymorphedCast::AllowPolymorphedCast(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__AddCastSpellActions>(&AddCastSpellActions_hook);
    pAddCastSpellActions_hook = hooker->FindHookByAddress(Functions::CNWSCreature__AddCastSpellActions);
}

int32_t AllowPolymorphedCast::AddCastSpellActions_hook(NWNXLib::API::CNWSCreature *pThis, uint32_t nSpellId, int32_t nMultiClass, int32_t nDomainLevel,
    int32_t nMetaType, int32_t bSpontaneousCast, Vector vTargetLocation, uint32_t oidTarget, int32_t bAreaTarget, int32_t bAddToFront,
    int32_t bFake, unsigned char nProjectilePathType, int32_t bInstant, int32_t bAllowPolymorphedCast, int32_t nFeat, unsigned char nCasterLevel)

{
    bAllowPolymorphedCast = true;
    return pAddCastSpellActions_hook->CallOriginal<int32_t>(pThis, nSpellId, nMultiClass, nDomainLevel, nMetaType, bSpontaneousCast, vTargetLocation,
        oidTarget, bAreaTarget, bAddToFront, bFake, nProjectilePathType, bInstant, bAllowPolymorphedCast, nFeat, nCasterLevel);
}

}
