//
//  NSObject+OK.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (OK)

- (id)ok_safeJsonObject;
- (NSString *)ok_safeJsonObjectKey;
- (nullable NSString *)ok_jsonStringEncoded;
- (nullable NSString *)ok_jsonStringEncodedForJS;
/**
 Swizzle two instance selectors.

 @param origSelector The original selector.
 @param newSelector The new selector.
 @return Return YES if selectors were swizzled successfully.
 */
+ (BOOL)ok_swizzleInstanceMethod:(nonnull SEL)origSelector with:(nonnull SEL)newSelector;

/**
 Swizzle two class selectors.

 @param origSelector The original selector.
 @param newSelector The new selector.
 @return Return YES if selectors were swizzled successfully.
 */
+ (BOOL)ok_swizzleClassMethod:(nonnull SEL)origSelector with:(nonnull SEL)newSelector;

@end

NS_ASSUME_NONNULL_END
