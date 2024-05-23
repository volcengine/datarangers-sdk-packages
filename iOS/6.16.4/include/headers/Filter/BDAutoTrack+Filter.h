//
//  BDAutoTrack+Filter.h
//  RangersAppLog
//
//  Created by bob on 2020/6/11.
//

#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (Filter)

/**
 给Lark使用, startTrack之前调用
 */
- (void)setFilterEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
