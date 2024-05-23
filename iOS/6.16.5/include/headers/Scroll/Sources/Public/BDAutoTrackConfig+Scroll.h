//
//  BDAutoTrackConfig+Scroll.h
//  Pods
//
//  Created by bytedance on 2023/9/15.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackConfig.h"
#import "BDAutoTrackScrollConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackConfig (Scroll)

/*!
    @abstract 滑动采集的功能的全局开关
 */
@property (nonatomic, assign) BOOL scrollObserveEnabled;

/*!
    @abstract 滑动采集的功能的全局配置
 */
@property (nonatomic) BDAutoTrackScrollConfig *scrollObserveConfig;

@end

NS_ASSUME_NONNULL_END
