//
//  OKReachability.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int32_t, OKReachabilityStatus) {
    OKReachabilityStatusNotReachable    = 0,
    OKReachabilityStatusReachableViaWiFi,
    OKReachabilityStatusReachableViaWWAN
};

FOUNDATION_EXTERN NSString *OKNotificationReachabilityChanged;

@interface OKReachability : NSObject

@property (nonatomic, assign, readonly) BOOL telephoneInfoIndeterminateStatus;

+ (instancetype)sharedInstance;

- (void)startNotifier;

- (OKReachabilityStatus)currentReachabilityStatus;

@end

NS_ASSUME_NONNULL_END
