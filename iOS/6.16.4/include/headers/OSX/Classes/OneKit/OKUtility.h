//
//  OKUtility.h
//  OneKit
//
//  Created by bob on 2020/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OKUtility : NSObject

+ (NSTimeInterval)currentInterval; /// return [[NSDate date] timeIntervalSince1970];
+ (long long)currentIntervalMS; /// return currentInterval * 1000
+ (NSCharacterSet *)URLQueryAllowedCharacterSet;

@end

FOUNDATION_EXTERN uint64_t OK_CurrentMachTime(void);
FOUNDATION_EXTERN double OK_MachTimeToSecs(uint64_t time);
FOUNDATION_EXTERN BOOL OK_isValidDictionary(NSDictionary *value);
FOUNDATION_EXTERN BOOL OK_isValidArray(NSArray *value);
FOUNDATION_EXTERN BOOL OK_isValidString(NSString *value);

NS_ASSUME_NONNULL_END
