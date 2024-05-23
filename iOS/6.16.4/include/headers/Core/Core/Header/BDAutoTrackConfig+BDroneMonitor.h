//
//  BDAutoTrackConfig+BDroneMonitor.h
//  Pods
//
//  Created by bytedance on 2023/4/27.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackConfig (BDroneMonitor)

/*! @abstract 值 0-100
 @discussion 5 代表采样率5%，只有命中才会采集
 */
@property (nonatomic, assign) NSUInteger monitorSamplingRate;

@end

NS_ASSUME_NONNULL_END
