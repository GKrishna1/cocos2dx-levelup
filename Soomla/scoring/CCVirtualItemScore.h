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
// Created by Shubin Fedor on 22/08/14.
// Copyright (c) 2014 SOOMLA. All rights reserved.
//


#ifndef __CCVirtualItemScore_H_
#define __CCVirtualItemScore_H_

#include "CCScore.h"

namespace soomla {

    /**
     A specific type of `Score` that has an associated virtual item.
     The score is related to the specific item ID. For example: a game 
     that has an "energy" virtual item can have energy points.
     */
    class CCVirtualItemScore: public CCScore {
        SL_SYNTHESIZE_RETAIN_WITH_DICT(cocos2d::CCString *, mAssociatedItemId, AssociatedItemId, CCLevelUpConsts::JSON_LU_ASSOCITEMID);
    public:
        CCVirtualItemScore(): CCScore(), mAssociatedItemId(NULL) {
        }
        
        /**
         Creates an instance of `CCVirtualItemScore`.
         @param id ID.
         @param associatedItemId Associated virtual item ID.
         */
        static CCVirtualItemScore *create(cocos2d::CCString *id, cocos2d::CCString *associatedItemId);
        
        /**
         Creates an instance of `CCVirtualItemScore`.
         @param id ID.
         @param name Name.
         @param higherBetter If set to `true` higher is better.
         @param associatedItemId Associated virtual item ID.
         */
        static CCVirtualItemScore *create(cocos2d::CCString *id, cocos2d::CCString *name, cocos2d::CCBool *higherBetter, cocos2d::CCString *associatedItemId);

        SL_CREATE_WITH_DICTIONARY(CCVirtualItemScore);

        virtual bool init(cocos2d::CCString *id, cocos2d::CCString *name, cocos2d::CCBool *higherBetter, cocos2d::CCString *associatedItemId);

        virtual bool initWithDictionary(cocos2d::CCDictionary* dict);
        
        /**
         Converts this `CCVirtualItemScore` to a Dictionary. 
         @return The Dictionary representation of this `CCVirtualItemScore`.
         */
        virtual cocos2d::CCDictionary *toDictionary();

        char const *getType() const;
        
    protected:
        
        /**
         Gives your user the temp-score amount of the associated item.
         */
        virtual void performSaveActions();
    };

}

#endif //__CCVirtualItemScore_H_
