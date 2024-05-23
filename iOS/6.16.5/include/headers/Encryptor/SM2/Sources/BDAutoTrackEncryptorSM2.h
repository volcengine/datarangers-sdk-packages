//
//  BDAutoTrackEncryptorSM2.h
//  Pods
//
//  Created by bytedance on 2023/3/2.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackEncryptionDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackEncryptorSM2 : NSObject<BDAutoTrackEncryptionDelegate>

+ (void)setPublickKey:(NSString *)publicKey;

+ (NSString *)publicKey;

@end

NS_ASSUME_NONNULL_END
