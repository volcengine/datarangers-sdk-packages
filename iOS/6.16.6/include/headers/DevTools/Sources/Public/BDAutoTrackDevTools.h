//
//  BDAutoTrackDevTools.h
//  RangersAppLog
//
//  Created by bytedance on 6/27/22.
//

#import <UIKit/UIKit.h>
#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackDevTools : NSObject

+ (void)setMonitorEnabled:(BOOL) monitorEnabled;

+ (void)showFloatingEntryButton;

+ (void)install:(BDAutoTrack *) tracker;

@end

NS_ASSUME_NONNULL_END
