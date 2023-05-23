#ifndef MY_ENUMS_H
#define MY_ENUMS_H

#include <iostream>

enum WeaponIds
{
    WEAPON_DEAGLE = 1,
    WEAPON_ELITE = 2,
    WEAPON_FIVESEVEN = 3,
    WEAPON_GLOCK = 4,
    WEAPON_AK47 = 7,
    WEAPON_AUG = 8,
    WEAPON_AWP = 9,
    WEAPON_FAMAS = 10,
    WEAPON_G3SG1 = 11,
    WEAPON_GALILAR = 13,
    WEAPON_M249 = 14,
    WEAPON_M4A1 = 16,
    WEAPON_MAC10 = 17,
    WEAPON_P90 = 19,
    WEAPON_MP5SD = 23,
    WEAPON_UMP45 = 24,
    WEAPON_XM1014 = 25,
    WEAPON_BIZON = 26,
    WEAPON_MAG7 = 27,
    WEAPON_NEGEV = 28,
    WEAPON_SAWEDOFF = 29,
    WEAPON_TEC9 = 30,
    WEAPON_TASER = 31,
    WEAPON_HKP2000 = 32,
    WEAPON_MP7 = 33,
    WEAPON_MP9 = 34,
    WEAPON_NOVA = 35,
    WEAPON_P250 = 36,
    WEAPON_SHIELD = 37,
    WEAPON_SCAR20 = 38,
    WEAPON_SG556 = 39,
    WEAPON_SSG08 = 40,
    WEAPON_KNIFEGG = 41,
    WEAPON_KNIFE = 42,
    WEAPON_FLASHBANG = 43,
    WEAPON_HEGRENADE = 44,
    WEAPON_SMOKEGRENADE = 45,
    WEAPON_MOLOTOV = 46,
    WEAPON_DECOY = 47,
    WEAPON_INCGRENADE = 48,
    WEAPON_C4 = 49,
    WEAPON_HEALTHSHOT = 57,
    WEAPON_KNIFE_T = 59,
    WEAPON_M4A1_SILENCER = 60,
    WEAPON_USP_SILENCER = 61,
    WEAPON_CZ75A = 63,
    WEAPON_REVOLVER = 64,
    WEAPON_TAGRENADE = 68,
    WEAPON_FISTS = 69,
    WEAPON_BREACHCHARGE = 70,
    WEAPON_TABLET = 72,
    WEAPON_MELEE = 74,
    WEAPON_AXE = 75,
    WEAPON_HAMMER = 76,
    WEAPON_SPANNER = 78,
    WEAPON_KNIFE_GHOST = 80,
    WEAPON_FIREBOMB = 81,
    WEAPON_DIVERSION = 82,
    WEAPON_FRAG_GRENADE = 83,
    WEAPON_SNOWBALL = 84,
    WEAPON_BUMPMINE = 85,
    WEAPON_BAYONET = 500,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT = 506,
    WEAPON_KNIFE_KARAMBIT = 507,
    WEAPON_KNIFE_M9_BAYONET = 508,
    WEAPON_KNIFE_TACTICAL = 509,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY = 515,
    WEAPON_KNIFE_PUSH = 516,
    WEAPON_KNIFE_URSUS = 519,
    WEAPON_KNIFE_GYPSY_JACKKNIFE = 520,
    WEAPON_KNIFE_STILETTO = 522,
    WEAPON_KNIFE_WIDOWMAKER = 523,
    STUDDED_BLOODHOUND_GLOVES = 5027,
    T_GLOVES = 5028,
    CT_GLOVES = 5029,
    SPORTY_GLOVES = 5030,
    SLICK_GLOVES = 5031,
    LEATHER_HANDWRAPS = 5032,
    MOTORCYCLE_GLOVES = 5033,
    SPECIALIST_GLOVES = 5034,
    STUDDED_HYDRA_GLOVES = 5035,
};

enum SkinIds{
    Dragon_Lore = 344,
    Case_Hardened = 44,
    Hellfire = 664,

};

namespace offset{
    constexpr ::std::ptrdiff_t localPlayer = 0xDE997C;
    constexpr ::std::ptrdiff_t entityList = 0x4DFEF0C;
    constexpr ::std::ptrdiff_t clientState = 0x59F19C;
    constexpr ::std::ptrdiff_t weapons = 0x2E08;

    // other
    constexpr ::std::ptrdiff_t m_flFallbackWear = 0x31E0;
    constexpr ::std::ptrdiff_t fallbackPaintKit = 0x31D8;
    constexpr ::std::ptrdiff_t m_nFallbackSeed = 0x31DC;
    constexpr ::std::ptrdiff_t m_nFallbackStatTrak = 0x31E4;


    constexpr ::std::ptrdiff_t itemDefinitionIndex = 0x2FBA;
    constexpr ::std::ptrdiff_t m_iItemIDHigh = 0x2FD0;

    constexpr ::std::ptrdiff_t cs_gamerules_data = 0x0;
    constexpr ::std::ptrdiff_t m_ArmorValue = 0x117CC;
    constexpr ::std::ptrdiff_t m_Collision = 0x320;
    constexpr ::std::ptrdiff_t m_CollisionGroup = 0x474;
    constexpr ::std::ptrdiff_t m_Local = 0x2FCC;
    constexpr ::std::ptrdiff_t m_MoveType = 0x25C;
    constexpr ::std::ptrdiff_t m_OriginalOwnerXuidHigh = 0x31D4;
    constexpr ::std::ptrdiff_t m_OriginalOwnerXuidLow = 0x31D0;
    constexpr ::std::ptrdiff_t m_SurvivalGameRuleDecisionTypes = 0x1328;
    constexpr ::std::ptrdiff_t m_SurvivalRules = 0xD00;
    constexpr ::std::ptrdiff_t m_aimPunchAngle = 0x303C;
    constexpr ::std::ptrdiff_t m_aimPunchAngleVel = 0x3048;
    constexpr ::std::ptrdiff_t m_angEyeAnglesX = 0x117D0;
    constexpr ::std::ptrdiff_t m_angEyeAnglesY = 0x117D4;
    constexpr ::std::ptrdiff_t m_bBombDefused = 0x29C0;
    constexpr ::std::ptrdiff_t m_bBombPlanted = 0x9A5;
    constexpr ::std::ptrdiff_t m_bBombTicking = 0x2990;
    constexpr ::std::ptrdiff_t m_bFreezePeriod = 0x20;
    constexpr ::std::ptrdiff_t m_bGunGameImmunity = 0x9990;
    constexpr ::std::ptrdiff_t m_bHasDefuser = 0x117DC;
    constexpr ::std::ptrdiff_t m_bHasHelmet = 0x117C0;
    constexpr ::std::ptrdiff_t m_bInReload = 0x32B5;
    constexpr ::std::ptrdiff_t m_bIsDefusing = 0x997C;
    constexpr ::std::ptrdiff_t m_bIsQueuedMatchmaking = 0x74;
    constexpr ::std::ptrdiff_t m_bIsScoped = 0x9974;
    constexpr ::std::ptrdiff_t m_bIsValveDS = 0x7C;
    constexpr ::std::ptrdiff_t m_bSpotted = 0x93D;
    constexpr ::std::ptrdiff_t m_bSpottedByMask = 0x980;
    constexpr ::std::ptrdiff_t m_bStartedArming = 0x3400;
    constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMax = 0x9D9;
    constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMin = 0x9D8;
    constexpr ::std::ptrdiff_t m_bUseCustomBloomScale = 0x9DA;
    constexpr ::std::ptrdiff_t m_clrRender = 0x70;
    constexpr ::std::ptrdiff_t m_dwBoneMatrix = 0x26A8;
    constexpr ::std::ptrdiff_t m_fAccuracyPenalty = 0x3340;
    constexpr ::std::ptrdiff_t m_fFlags = 0x104;
    constexpr ::std::ptrdiff_t m_flC4Blow = 0x29A0;
    constexpr ::std::ptrdiff_t m_flCustomAutoExposureMax = 0x9E0;
    constexpr ::std::ptrdiff_t m_flCustomAutoExposureMin = 0x9DC;
    constexpr ::std::ptrdiff_t m_flCustomBloomScale = 0x9E4;
    constexpr ::std::ptrdiff_t m_flDefuseCountDown = 0x29BC;
    constexpr ::std::ptrdiff_t m_flDefuseLength = 0x29B8;
    constexpr ::std::ptrdiff_t m_flFlashDuration = 0x10470;
    constexpr ::std::ptrdiff_t m_flFlashMaxAlpha = 0x1046C;
    constexpr ::std::ptrdiff_t m_flLastBoneSetupTime = 0x2928;
    constexpr ::std::ptrdiff_t m_flLowerBodyYawTarget = 0x9ADC;
    constexpr ::std::ptrdiff_t m_flNextAttack = 0x2D80;
    constexpr ::std::ptrdiff_t m_flNextPrimaryAttack = 0x3248;
    constexpr ::std::ptrdiff_t m_flSimulationTime = 0x268;
    constexpr ::std::ptrdiff_t m_flTimerLength = 0x29A4;
    constexpr ::std::ptrdiff_t m_hActiveWeapon = 0x2F08;
    constexpr ::std::ptrdiff_t m_hBombDefuser = 0x29C4;
    constexpr ::std::ptrdiff_t m_hMyWeapons = 0x2E08;
    constexpr ::std::ptrdiff_t m_hObserverTarget = 0x339C;
    constexpr ::std::ptrdiff_t m_hOwner = 0x29DC;
    constexpr ::std::ptrdiff_t m_hOwnerEntity = 0x14C;
    constexpr ::std::ptrdiff_t m_hViewModel = 0x3308;
    constexpr ::std::ptrdiff_t m_iAccountID = 0x2FD8;
    constexpr ::std::ptrdiff_t m_iClip1 = 0x3274;
    constexpr ::std::ptrdiff_t m_iCompetitiveRanking = 0x1A84;
    constexpr ::std::ptrdiff_t m_iCompetitiveWins = 0x1B88;
    constexpr ::std::ptrdiff_t m_iCrosshairId = 0x11838;
    constexpr ::std::ptrdiff_t m_iDefaultFOV = 0x333C;
    constexpr ::std::ptrdiff_t m_iEntityQuality = 0x2FBC;
    constexpr ::std::ptrdiff_t m_iFOV = 0x31F4;
    constexpr ::std::ptrdiff_t m_iFOVStart = 0x31F8;
    constexpr ::std::ptrdiff_t m_iGlowIndex = 0x10488;
    constexpr ::std::ptrdiff_t m_iHealth = 0x100;
    constexpr ::std::ptrdiff_t m_iMostRecentModelBoneCounter = 0x2690;
    constexpr ::std::ptrdiff_t m_iObserverMode = 0x3388;
    constexpr ::std::ptrdiff_t m_iShotsFired = 0x103E0;
    constexpr ::std::ptrdiff_t m_iState = 0x3268;
    constexpr ::std::ptrdiff_t m_iTeamNum = 0xF4;
    constexpr ::std::ptrdiff_t m_lifeState = 0x25F;
    constexpr ::std::ptrdiff_t m_nBombSite = 0x2994;
    constexpr ::std::ptrdiff_t m_nForceBone = 0x268C;
    constexpr ::std::ptrdiff_t m_nModelIndex = 0x258;
    constexpr ::std::ptrdiff_t m_nTickBase = 0x3440;
    constexpr ::std::ptrdiff_t m_nViewModelIndex = 0x29D0;
    constexpr ::std::ptrdiff_t m_rgflCoordinateFrame = 0x444;
    constexpr ::std::ptrdiff_t m_szCustomName = 0x304C;
    constexpr ::std::ptrdiff_t m_szLastPlaceName = 0x35C4;
    constexpr ::std::ptrdiff_t m_thirdPersonViewAngles = 0x31E8;
    constexpr ::std::ptrdiff_t m_vecOrigin = 0x138;
    constexpr ::std::ptrdiff_t m_vecVelocity = 0x114;
    constexpr ::std::ptrdiff_t m_vecViewOffset = 0x108;
    constexpr ::std::ptrdiff_t m_viewPunchAngle = 0x3030;
    constexpr ::std::ptrdiff_t m_zoomLevel = 0x33E0;
}

#endif