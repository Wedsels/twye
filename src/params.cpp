#include "common.hpp"

#include <param/param.hpp>

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

    auto row = from::param::SpEffectParam[100690].first;
    row.stateInfo = 8;
    row.sightSearchEnemyRate = 0;

    row = from::param::SpEffectParam[350401].first;
    row.changeHpRate = ( row.changeMpRate = -6 ) * 2;
    row.changeHpPoint = ( row.changeMpPoint = -9 ) * 4;

    row = from::param::SpEffectParam[20380100].first;
    row.slashDamageCutRate = 1;
    row.blowDamageCutRate = 1;
    row.thrustDamageCutRate = 1;
    row.neutralDamageCutRate = 1;
    row.magicDamageCutRate = 1;
    row.fireDamageCutRate = 1;
    row.thunderDamageCutRate = 1;
    row.darkDamageCutRate = 1;

    return common::time();
}