//
//  BDAutoTrackAlinkRouting.h
//  RangersAppLog
//
//  Created by 朱元清 on 2021/3/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
static NSErrorDomain const RALALinkErrorDomain = @"RALALinkErrorDomain";

@protocol BDAutoTrackAlinkRouting <NSObject>
@required

- (void)onAttributionData:(nullable NSDictionary *)routingInfo error:(nullable NSError *)error;

- (void)onALinkData:(nullable NSDictionary *)routingInfo error:(nullable NSError *)error;

- (bool)shouldALinkSDKAccessPasteBoard;

@end

NS_ASSUME_NONNULL_END
