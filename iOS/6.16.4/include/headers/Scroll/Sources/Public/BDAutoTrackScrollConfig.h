//
//  BDAutoTrackScrollConfig.h
//  Pods
//
//  Created by bytedance on 2023/9/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*! @abstract 滑动回调
    @param view  滑动的元素
    @param eventName  滑动事件名
    @param properties  滑动事件属性
    @result YES: 正常上报    NO: 过滤本次滑动事件
 */
typedef BOOL (^BDAutoTrackScrollBlock)(UIScrollView *view, NSString *eventName, NSDictionary *properties);

@interface BDAutoTrackScrollConfig : NSObject

/*!
    @abstract 创建默认初始化的配置实例
 */
+ (instancetype)defaultConfig;

/*!
    @abstract 全局默认配置，一般用于 BDAutoTrackConfig
 */
+ (instancetype)globalDefaultConfig;


/*! @abstract 设置触发滑动事件的最小滑动距离
    @param offset  最小滑动距离
    @discussion
        默认为 -1 将会采用全局的配置
    @result 返回当前实例
 */
- (instancetype)minOffset:(CGFloat)offset;


/*! @abstract 设置滑动回调
    @param block  滑动回调
    @result 返回当前实例
 */
- (instancetype)scrollBlock:(nullable BDAutoTrackScrollBlock)block;

@end

NS_ASSUME_NONNULL_END
