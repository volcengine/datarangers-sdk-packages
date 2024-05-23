//
//  BDAutoTrack+CAID.h
//  RangersAppLog
//
//  Created by 朱元清 on 2021/2/28.
//

#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (CAID)
/// 获取CAID
+ (NSString *)caid;

/// 获取上次的CAID
+ (NSString *)prevCaid;

/// 获取CAID
- (NSString *)caid;

/// 获取上次的CAID
- (NSString *)prevCaid;
@end

NS_ASSUME_NONNULL_END
