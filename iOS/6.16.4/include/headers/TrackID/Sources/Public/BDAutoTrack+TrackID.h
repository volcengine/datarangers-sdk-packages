//
//  BDAutoTrack+TrackID.h
//  Pods
//
//  Created by bytedance on 2023/10/18.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (TrackID)

/*!
 @abstract 设置资源位标识，用于判定触发的埋点是否属于资源位
 @param paramKey 设置资源位标识的 key，对应埋点中 params 的 key
 @param paramValues  设置资源位标识的 value，对应埋点中 params 的 value
 @discussion 当埋点的 params 中的 key 与标识相同，且 value 在 paramValues 中时，即判定当前埋点属于资源位
 */
- (void)configTrackIDResourceEvent:(NSString *)paramKey values:(NSSet *)paramValues;

/*!
 @abstract 设置最大追踪资源位数量
 @param count  最大追踪资源位数量，默认为 3
 */
- (void)configTrackIDResourcCount:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
