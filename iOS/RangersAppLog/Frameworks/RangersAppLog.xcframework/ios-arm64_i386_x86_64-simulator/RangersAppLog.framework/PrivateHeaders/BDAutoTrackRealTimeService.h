//
//  BDAutoTrackRealTimeService.h
//  RangersAppLog
//
//  Created by bob on 2020/5/28.
//

#import "BDAutoTrackService.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackRealTimeService : BDAutoTrackService<BDAutoTrackLogService>

- (instancetype)initWithAppID:(NSString *)appID;

- (void)sendEvent:(NSDictionary *)event key:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
