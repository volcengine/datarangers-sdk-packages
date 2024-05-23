//
//  BDAutoTrackASA.h
//  RangersAppLog
//
//  Created by 朱元清 on 2021/6/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ASA stands for Apple Search Ads
@interface BDAutoTrackASA : NSObject

@property (nonatomic) BOOL useAdServicesAPI;

@property (nonatomic, readonly) NSString *AdServicesAttrToken;

+ (BDAutoTrackASA *)sharedInstance;

+ (void)start;

- (NSString *)iAdAttrDetails_JSON;

/// helper function 便于外界通过运行时获取上报参数
+ (NSDictionary *)ASAParams;

@end

NS_ASSUME_NONNULL_END
