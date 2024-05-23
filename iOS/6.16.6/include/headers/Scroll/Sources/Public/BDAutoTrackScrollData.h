//
//  BDAutoTrackScrollData.h
//  Pods
//
//  Created by bytedance on 2023/9/15.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrackScrollConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface BDAutoTrackScrollData : NSObject

/*! @abstract 设置滑动埋点信息
 @param eventName 事件名称，如果不填会使用默认的滑动事件eventName
 @param properties 事件参数。可以为空或者nil，但是param如果非空，需要可序列化成json
 @param config 配置参数。可以配置视图级别的配置，默认为空会使用全局配置
 @discussion properties 请参考文档中的日志格式要求，或者使用 [NSJSONSerialization isValidJSONObject:] 来检查params是否可序列化
 @result 滑动埋点信息实例
 */
+ (instancetype)eventName:(nullable NSString *)eventName
               properties:(nullable NSDictionary *)properties
                   config:(nullable BDAutoTrackScrollConfig *)config;


/*!
    @abstract event 事件名称，如果不填会使用默认的滑动事件event
 */
@property (nonatomic, copy, nullable) NSString *eventName;


/*!
    @abstract properties 事件参数。可以为空或者nil，但是param如果非空，需要可序列化成json
 */
@property (nonatomic, copy, nullable) NSDictionary  *properties;


/*!
    @abstract config 配置参数。默认为空会使用全局配置
 */
@property (nonatomic, strong, nullable) BDAutoTrackScrollConfig *config;

@end

NS_ASSUME_NONNULL_END
