//
//  BDAutoTrackExceptionTracer.h
//  RangersAppLog
//
//  Created by bytedance on 2022/8/12.
//

#import <Foundation/Foundation.h>

@interface BDAutoTrackExceptionTracer : NSObject

@property (nonatomic, assign) BOOL hasStart;

+ (instancetype)shared;

- (void)start;

- (void)stop;

@end
