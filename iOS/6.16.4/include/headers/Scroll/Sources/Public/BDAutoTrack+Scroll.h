//
//  BDAutoTrack+Scroll.h
//  Pods
//
//  Created by bytedance on 2023/9/15.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrack.h"
#import "BDAutoTrackScrollData.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrack (Scroll)

/*!
 @abstract 设置视图开启自动滑动埋点采集
 @param scrollView  视图实例，UIScrollView 及其子类
 @param data 滑动埋点信息数据
 @discussion 支持重复设置，如果data中的event,properties 不一致，会被认为是一个新的事件
 */
- (void)observeViewScroll:(UIScrollView *)scrollView withData:(nullable BDAutoTrackScrollData *)data;

/*!
 @abstract 移除视图滑动埋点采集
 @param scrollView  视图实例， UIScrollView 及其子类
 */
- (void)disposeViewScroll:(UIScrollView *)scrollView;

@end

NS_ASSUME_NONNULL_END
