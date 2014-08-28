LOCAL_PATH := $(call my-dir)

# cocos2dx-levelup
include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dx_levelup_static
LOCAL_MODULE_FILENAME := libcocos2dxlevelup
LOCAL_SRC_FILES := ../../Soomla/CCLevel.cpp \
	../../Soomla/CCLevelUp.cpp \
	../../Soomla/CCLevelUpConsts.cpp \
	../../Soomla/CCLevelUpEventDispatcher.cpp \
	../../Soomla/CCLevelUpService.cpp \
	../../Soomla/CCSimpleLevelUpEventHandler.cpp \
	../../Soomla/CCWorld.cpp \
	../../Soomla/challenges/CCBalanceMission.cpp \
	../../Soomla/challenges/CCChallenge.cpp \
	../../Soomla/challenges/CCMission.cpp \
	../../Soomla/challenges/CCPurchasingMission.cpp \
	../../Soomla/challenges/CCRecordMission.cpp \
	../../Soomla/challenges/CCWorldCompletionMission.cpp \
	../../Soomla/data/CCGateStorage.cpp \
	../../Soomla/data/CCLevelStorage.cpp \
	../../Soomla/data/CCMissionStorage.cpp \
	../../Soomla/data/CCScoreStorage.cpp \
	../../Soomla/data/CCWorldStorage.cpp \
	../../Soomla/gates/CCBalanceGate.cpp \
	../../Soomla/gates/CCGate.cpp \
	../../Soomla/gates/CCGatesList.cpp \
	../../Soomla/gates/CCGatesListAnd.cpp \
	../../Soomla/gates/CCGatesListOr.cpp \
	../../Soomla/gates/CCPurchasableGate.cpp \
	../../Soomla/gates/CCRecordGate.cpp \
	../../Soomla/gates/CCScheduleGate.cpp \
	../../Soomla/gates/CCWorldCompletionGate.cpp \
	../../Soomla/scoring/CCScore.cpp \
	../../Soomla/scoring/CCVirtualItemScore.cpp \
	../../Soomla/scoring/CCRangeScore.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Soomla
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/challenges
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/data
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/gates
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/scoring
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../lib

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_soomla_common_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_store_static

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../..
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Soomla
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/challenges
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/data
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/gates
LOCAL_EXPORT_C_INCLUDES += $(LOCAL_PATH)/../../Soomla/scoring

include $(BUILD_STATIC_LIBRARY)

$(call import-module,extensions/soomla-cocos2dx-core/android/jni)
$(call import-module,extensions/cocos2dx-store/android/jni)
