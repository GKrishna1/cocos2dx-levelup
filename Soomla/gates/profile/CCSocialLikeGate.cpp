/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

//
// Created by Shubin Fedor on 21/08/14.
// Copyright (c) 2014 SOOMLA. All rights reserved.
//

#include "CCSocialLikeGate.h"
#include "CCGateStorage.h"
#include "CCSoomlaProfile.h"

namespace soomla {

#define TAG "SOOMLA SocialLikeGate"

    CCSocialLikeGate *CCSocialLikeGate::create(cocos2d::CCString *id, CCProvider provider, cocos2d::CCString *pageName) {
        CCSocialLikeGate *ret = new CCSocialLikeGate();
        if (ret->init(id, provider, pageName)) {
            ret->autorelease();
        }
        else {
            CC_SAFE_DELETE(ret);
        }

        return ret;
    }

    bool CCSocialLikeGate::init(cocos2d::CCString *id, CCProvider provider, cocos2d::CCString *pageName) {
        bool result = CCSocialActionGate::init(id, provider);
        if (result) {

            setPageName(pageName);

            return true;
        }
        return result;
    }

    bool CCSocialLikeGate::initWithDictionary(cocos2d::CCDictionary *dict) {
        bool result = CCGate::initWithDictionary(dict);
        if (result) {

            fillPageNameFromDict(dict);

            return true;
        }
        return result;
    }

    cocos2d::CCDictionary *CCSocialLikeGate::toDictionary() {
        cocos2d::CCDictionary *dict = CCSoomlaEntity::toDictionary();

        putPageNameToDict(dict);

        return dict;
    }

    const char *CCSocialLikeGate::getType() const {
        return CCLevelUpConsts::JSON_JSON_TYPE_SOCIAL_LIKE_GATE;
    }

    CCSocialLikeGate::~CCSocialLikeGate() {
        CC_SAFE_RELEASE(mPageName);
    }

    bool CCSocialLikeGate::openInner() {
        if (canOpen()) {

            CCSoomlaProfile::getInstance()->like(getProvider(), getPageName()->getCString(), NULL, NULL);

            return true;
        }

        return false;
    }

}