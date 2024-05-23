//
//  BDAutoTrack+UITracker.h
//  RangersAppLog
//
//  Created by bytedance on 1/27/22.
//

#import "BDAutoTrack.h"

NS_ASSUME_NONNULL_BEGIN


@interface BDAutoTrack (UITracker)

/*! @abstract 忽略UIViewController中自动采集的浏览埋点
    @discussion 忽略范围作用域为自身类，并不影响继承关系，例如 BViewController 继承于 AViewController， 如果都忽略需要传入@[[AViewController class],[BViewController class]]
    @param controllerClasses 传入需要忽略的类名 @[[TestViewController class], [UserViewController class]]
 */
- (void)ignoreAutoTrackPage:(NSArray<Class> *)controllerClasses;

/*! @abstract 忽略控件中自动采集的点击埋点
    @discussion 忽略范围作用域为自身类
    @param viewClasses 传入需要忽略的类名 @[[AButton class], [ALabel class]]
 */
- (void)ignoreAutoTrackClick:(NSArray<Class> *)viewClasses;


/*!
 *  @abstract 代码触发页面浏览埋点上报
 *  @param controller 可以传递 UIViewController 以及实现了 BDAutoTrackable协议的对象
 *  @result 是否成功
 */
- (BOOL)trackPage:(id<BDAutoTrackable>)controller;

/*!
 *  @abstract 代码触发页面浏览埋点上报
 *  @param controller 可以传递 UIViewController
 *  @param params 用户自定义参数，进行 [NSJSONSerialization isValidJSONObject:] 验证
 *  @result 是否成功
 */
- (BOOL)trackPage:(id)controller withParameters:(nullable NSDictionary<NSString *,id> *)params;

/*!
 *  @abstract 代码触发点击埋点上报
 *  @param view 可以传递 UIView 等控件对象 以及实现了 BDAutoTrackable协议的对象
 *  @result 是否成功
 */
- (BOOL)trackClick:(id<BDAutoTrackable>)view;

/*!
 *  @abstract 代码触发点击埋点上报
 *  @param view 可以传递 UIView 等控件对象 以及实现了 BDAutoTrackable协议的对象
 *  @param params 用户自定义参数，进行 [NSJSONSerialization isValidJSONObject:] 验证
 *  @result 是否成功
 */
- (BOOL)trackClick:(id<BDAutoTrackable>)view withParameters:(nullable NSDictionary<NSString *,id> *)params;

- (BOOL)isPageIgnored:(id)controller;
- (BOOL)isClickIgnored:(id)view;


@end

NS_ASSUME_NONNULL_END
