//
//  NSNumber+OK.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNumber (OK)

- (id)ok_safeJsonObject;
- (NSString *)ok_safeJsonObjectKey;

@end

NS_ASSUME_NONNULL_END
