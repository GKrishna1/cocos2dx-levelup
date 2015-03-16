/*
 * Copyright (C) 2012-2014 Soomla Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

package com.soomla.cocos2dx.levelup;

import com.soomla.SoomlaUtils;

public class LevelUpBridgeBinder {

    public static void bind() {
        SoomlaUtils.LogDebug(TAG, "Binding to native LevelUp bridge");

        LevelUpBridge.getInstance().init();
    }

    private static final String TAG = "SOOMLA LevelUpBridgeBinder";
}
