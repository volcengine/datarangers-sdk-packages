//
//  NSDictionary+OK.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (OK)

- (id)ok_safeJsonObject;
- (nullable NSString *)ok_queryString;

- (BOOL)ok_boolValueForKey:(NSString *)key;
- (double)ok_doubleValueForKey:(NSString *)key;
- (NSInteger)ok_integerValueForKey:(NSString *)key;
- (long long)ok_longlongValueForKey:(NSString *)key;
- (nullable NSString *)ok_stringValueForKey:(NSString *)key;
- (nullable NSDictionary *)ok_dictionaryValueForKey:(NSString *)key;
- (nullable NSMutableDictionary *)ok_mutableDictionaryValueForKey:(NSString *)key;
- (nullable NSArray *)ok_arrayValueForKey:(NSString *)key;
- (nullable NSMutableArray *)ok_mutableArrayValueForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
