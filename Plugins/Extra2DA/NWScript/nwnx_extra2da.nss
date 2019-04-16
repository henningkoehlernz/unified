#include "nwnx"

const string NWNX_Extra2DA = "NWNX_Extra2DA";

// Get first character level where awarded ability bonuses differ from expected values.
// Returns 0 if no difference exists.
int NWNX_Extra2DA_GetDragonAbilityDivergence(object oPC);
// Delevel character as much as necessary to repair dragon ability bonuses, then restore XP.
void NWNX_Extra2DA_RelevelToFixDragonAbilities(object oPC);

// Get string encoding of adjustments made to ability scores (for persistent storage)
string NWNX_Extra2DA_GetDragonAbilityHistory(object oPC);
// Set string encoding of adjustments made to ability scores
void NWNX_Extra2DA_SetDragonAbilityHistory(object oPC, string sHistory);

//--------------------------- Implementation ----------------------------------

int NWNX_Extra2DA_GetDragonAbilityDivergence(object oPC)
{
    string sFunc = "GetDragonAbilityDivergence";

    NWNX_PushArgumentObject(NWNX_Extra2DA, sFunc, oPC);
    NWNX_CallFunction(NWNX_Extra2DA, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Extra2DA, sFunc);
}

void NWNX_Extra2DA_RelevelToFixDragonAbilities(object oPC)
{
    int nDivergence = NWNX_Extra2DA_GetDragonAbilityDivergence(oPC);
    if ( nDivergence )
    {
        int originalXP = GetXP(oPC);
        int minXP = nDivergence * (nDivergence - 1) * 500;
        SetXP(oPC, minXP - 1);
        SetXP(oPC, originalXP);
        SendMessageToPC(oPC, "Dragon abilities have changed. Please re-level your character.");
    }
}

string NWNX_Extra2DA_GetDragonAbilityHistory(object oPC)
{
    string sFunc = "GetDragonAbilityHistory";

    NWNX_PushArgumentObject(NWNX_Extra2DA, sFunc, oPC);
    NWNX_CallFunction(NWNX_Extra2DA, sFunc);
    return NWNX_GetReturnValueString(NWNX_Extra2DA, sFunc);
}

void NWNX_Extra2DA_SetDragonAbilityHistory(object oPC, string sHistory)
{
    string sFunc = "SetDragonAbilityHistory";

    NWNX_PushArgumentString(NWNX_Extra2DA, sFunc, sHistory);
    NWNX_PushArgumentObject(NWNX_Extra2DA, sFunc, oPC);
    NWNX_CallFunction(NWNX_Extra2DA, sFunc);
}
