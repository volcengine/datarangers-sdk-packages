//
//  BDAutoTrack+ET.h
//  RangersAppLog
//
//  Created by bob on 2020/6/11.
//

#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (ET)

/**
 给Lark使用，需要埋点验证的时候调用

 */
+ (void)setETEnable:(BOOL)enable withAppID:(NSString *)appID;

/// 设置ET自动上报时间间隔。
/// @param interval 时间间隔。单位:毫秒。
+ (void)setETReportInterval:(long long)interval;

@end

NS_ASSUME_NONNULL_END
