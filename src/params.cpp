#include "common.hpp"

#include <param/param.hpp>

void basesp( from::paramdef::SP_EFFECT_PARAM_ST& row ) {
    row = from::param::SpEffectParam[0].first;

    row.effectEndurance =
    row.isDisableNetSync = 0;
    row.hpRecoverRate = 
    row.equipWeightChangeRate = 
    row.soulRate = 
    row.fallDamageRate = 
    row.lifeReductionRate = 
    row.effectTargetSelf = 
    row.effectTargetFriend = 
    row.effectTargetEnemy = 
    row.effectTargetPlayer = 
    row.effectTargetAI = 
    row.effectTargetLive = 
    row.effectTargetGhost = 
    row.effectTargetOpposeTarget = 
    row.effectTargetFriendlyTarget = 
    row.effectTargetSelfTarget = 
    row.isIgnoreNoDamage = 
    row.allItemWeightChangeRate = 
    row.soulStealRate = 
    row.isDisableNetSync = 
    row.vowType0 = 
    row.vowType1 = 
    row.vowType2 = 
    row.vowType3 = 
    row.vowType4 = 
    row.vowType5 = 
    row.vowType6 = 
    row.vowType7 = 
    row.vowType8 = 
    row.vowType9 = 
    row.vowType10 = 
    row.vowType11 = 
    row.vowType12 = 
    row.vowType13 = 
    row.vowType14 = 
    row.vowType15 = 1;
}

uint64_t common::params::parammain() {
    common::time();

    for ( auto [id, row] : from::param::Bullet ) {
        if ( row.isAttackSFX != 1 || row.isPenetrateChr + row.isPenetrateMap + row.isPenetrateObj > 0 || row.life < 5 || row.atkAttribute != 254 || row.atkId_Bullet == -1 ) continue;

        row.life *= 25;
        row.maxVellocity *= 20;
        row.accelOutRange = 20;
        row.accelInRange = 450;

        row.damageDamp = -128;
        row.spelDamageDamp = -128;
        row.fireDamageDamp = -128;
        row.thunderDamageDamp = -128;
        row.darkDamageDamp = -128;
        row.staminaDamp = -128;
        row.knockbackDamp = -128;
    }

    for ( auto [id, row] : from::param::NpcThinkParam ) {
        row.maxBackhomeDist = 9999;
        row.backhomeDist = 9999;
        row.backhomeBattleDist = 9999;
        
        row.eye_dist *= 7;
        row.ear_dist *= 7;
    }

    for ( auto [id, row] : from::param::EquipParamWeapon ) {
        row.isEnhance = 1;
    }

    for ( auto [id, row] : from::param::EquipParamGoods ) {
        if ( row.goodsUseAnim != 16 && row.reinforceMaterialId != 1 ) continue;
        from::param::SpEffectParam[row.refId_default].first.cycleOccurrenceSpEffectId = row.refId_1;
        from::param::SpEffectParam[row.refId_1].first.effectEndurance = 0.01f;
    }

    for ( auto [id, row] : from::param::EquipParamGem ) {
        if ( row.canMountWep_Claw
            || row.canMountWep_Dagger
            || row.canMountWep_katana
            || row.canMountWep_SaberNormal
            || row.canMountWep_SwordPierce
            || row.canMountWep_ReverseHandSword
        ) {
            row.canMountWep_Claw = 1;
            row.canMountWep_Dagger = 1;
            row.canMountWep_katana = 1;
            row.canMountWep_SaberNormal = 1;
            row.canMountWep_SwordPierce = 1;
            row.canMountWep_ReverseHandSword = 1;
        }
        if ( row.canMountWep_GreatKatana
            || row.canMountWep_LightGreatsword
            || row.canMountWep_AxeLarge
            || row.canMountWep_HammerLarge
            || row.canMountWep_SwordGigantic
            || row.canMountWep_SwordLarge
            || row.canMountWep_SaberLarge
        ) {
            row.canMountWep_GreatKatana = 1;
            row.canMountWep_LightGreatsword = 1;
            row.canMountWep_AxeLarge = 1;
            row.canMountWep_HammerLarge = 1;
            row.canMountWep_SwordGigantic = 1;
            row.canMountWep_SwordLarge = 1;
            row.canMountWep_SaberLarge = 1;
        }
        
        row.configurableWepAttr00 =
        row.configurableWepAttr01 =
        row.configurableWepAttr02 =
        row.configurableWepAttr03 =
        row.configurableWepAttr04 =
        row.configurableWepAttr05 =
        row.configurableWepAttr06 =
        row.configurableWepAttr07 =
        row.configurableWepAttr08 =
        row.configurableWepAttr09 =
        row.configurableWepAttr10 =
        row.configurableWepAttr11 =
        row.configurableWepAttr12 =
        row.configurableWepAttr13 =
        row.configurableWepAttr14 =
        row.configurableWepAttr15 =
        row.configurableWepAttr16 =
        row.configurableWepAttr17 =
        row.configurableWepAttr18 =
        row.configurableWepAttr19 =
        row.configurableWepAttr20 =
        row.configurableWepAttr21 =
        row.configurableWepAttr22 =
        row.configurableWepAttr23 = 1;
    }

    {
        auto& row = from::param::SpEffectParam[100690].first;
        row.effectEndurance = 4.555f;
        row.stateInfo = 8;
        row.sightSearchEnemyRate = 0;
    }
    {
        auto& row = from::param::SpEffectParam[350401].first;
        row.changeStaminaRate = row.changeHpRate = ( row.changeMpRate = -4 ) * 2;
        row.changeStaminaPoint = row.changeHpPoint = ( row.changeMpPoint = -6 ) * 4;
    }
    {
        from::param::SpEffectParam[102000].first.vfxId = -1;
        from::param::SpEffectParam[102000].first.iconId = -1;

        auto& row = from::param::SpEffectParam[20380100].first;
        row.iconId = -1;
        row.slashDamageCutRate = 1;
        row.blowDamageCutRate = 1;
        row.thrustDamageCutRate = 1;
        row.neutralDamageCutRate = 1;
        row.magicDamageCutRate = 1;
        row.fireDamageCutRate = 1;
        row.thunderDamageCutRate = 1;
        row.darkDamageCutRate = 1;
    }
    {
        auto& right = from::param::SpEffectParam[7210].first;
        basesp( right );

        right.effectEndurance = -1;
        right.wepParamChange = 1;
        right.changeStrengthPoint = 11;
        right.changeAgilityPoint = 22;
        right.changeMagicPoint = 22;
        right.changeFaithPoint = 22;
        right.changeLuckPoint = 22;
        right.bAdjustStrengthAblity = 1;
        right.bAdjustAgilityAblity = 1;
        right.bAdjustMagicAblity = 1;
        right.bAdjustFaithAblity = 1;
        right.isUseAtkParamAtkPowerCorrect = 1;
        right.isUseStatusAilmentAtkPowerCorrect = 1;
        right.magParamChange = 1;
        right.miracleParamChange = 1;
        right.shamanParamChange = 1;
        right.throwAttackParamChange = 1;

        auto& left = from::param::SpEffectParam[7220].first;
        left = right;
        left.wepParamChange = 2;
    }


    // from::param::Bullet[10464010].first = from::param::Bullet[20007601].first;
    // auto& bu = from::param::Bullet[10464010].first;
    // bu.atkId_Bullet = 0;
    // bu.sfxId_Bullet = -1;
    // bu.sfxId_Flick = -1;
    // bu.sfxId_Hit = -1;
    // bu.hitRadius = 0.025f;
    // bu.hitRadiusMax = 0.025f;
    // bu.spEffectId0 = 6909;
    // for ( auto [id, row] : from::param::Bullet ) {
    //     if ( id == 10464010 || row.HitBulletID > 0 ) continue;
    //     row.HitBulletID = 10464010;
    // }
    
    return common::time();
}

/*
    Changing the wepmotionCategory and spAtkcategory to copy that of the right hand weapon, would create the ability for use the dual heavy attacks
    could also copy over the guardmotion thing which would change wep position
*/