//
//  BDAutoTrack+IDFA.h
//  Pods
//
//  Created by bytedance on 2024/4/15.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (IDFA)

/*! @abstract 设置自定义的 IDFA URL 回调
 @param requestIDFAURLBlock 回调block，设置一次即可，不需要多次设置
 @discussion requestURLBlock 会覆盖之前的初始化或者上一次设置的回调，如果为nil会清空回调
 @discussion block在初始化之前 设置一次即可，每次拉取请求都会回调，请勿一直重复设置
 */
- (void)setRequestIDFAURLBlock:(nullable BDAutoTrackRequestURLBlock)requestIDFAURLBlock;

/*! @abstract 设置自定义的 IDFA URL 回调
 @param requestIDFAHostBlock 回调block，设置一次即可，不需要多次设置
 @discussion requestHostBlock 会覆盖之前的初始化或者上一次设置的回调，如果为nil会清空回调
 @discussion requestURLBlock会优先于requestHostBlock
 */
- (void)setRequestIDFAHostBlock:(nullable BDAutoTrackRequestHostBlock)requestIDFAHostBlock;

@end

NS_ASSUME_NONNULL_END
