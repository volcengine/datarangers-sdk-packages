//
//  UIView+AutoTrack.h
//  Applog
//
//  Created by bob on 2019/1/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (TrackInfo)

/*! @abstract 这个对应新增的 element_id 字段，bdAutoTrackViewID 对应的是 element_manual_key 字段
 @discussion 如果设置，被点击的时候会采集
 */
@property (nonatomic, copy) NSString *bdAutoTrackElementID;

/*! @abstract 手动设置的ViewID
 @discussion 如果设置，被点击的时候会采集，可以唯一标志该View
 */
@property (nonatomic, copy) NSString *bdAutoTrackViewID;

/*! @abstract 手动设置的ViewContent
 @discussion如果设置，被点击的时候会采集
 */
@property (nonatomic, copy) NSString *bdAutoTrackViewContent;

/*! @abstract 手动设置的extra信息
 @discussion 如果设置，被点击的时候会采集
 */
@property (nonatomic, copy) NSDictionary<NSString*, NSString *> *bdAutoTrackExtraInfos;

/*! @abstract 自定义采集属性，相同 key 会覆盖默认采集的 params
 @discussion 如果设置，被点击的时候会采集
 */
@property (nonatomic, copy) NSDictionary<NSString*, NSObject *> *bdAutoTrackViewProperties;

/*! @abstract 自定义采集开发
 @discussion 如果设置 YES，被点击的时候埋点会被忽略
 */
@property (nonatomic, assign) BOOL bdAutoTrackIgnoreClick;

@end

NS_ASSUME_NONNULL_END
