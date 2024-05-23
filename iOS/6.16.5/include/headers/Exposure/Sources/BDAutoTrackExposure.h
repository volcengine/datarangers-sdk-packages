//
//  BDAutoTrackExposure.h
//  RangersAppLog
//
//  Created by SoulDiver on 2022/3/31.
//

#import <Foundation/Foundation.h>
#import "BDAutoTrack.h"
#import "BDAutoTrackConfig.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BDAutoTrackExposureTriggerType) {
    // 首次曝光
    BDAutoTrackExposureTriggerTypeExposureOnce          = 0,
    
    // 页面中多次出现（第二次曝光后）
    BDAutoTrackExposureTriggerTypeLifecycleShowNew      = 3,
    
    // 从其他页面返回
    BDAutoTrackExposureTriggerTypeResumeFromPage        = 6,
    
    // 从后台返回
    BDAutoTrackExposureTriggerTypeResumeFromBack        = 7,
};

/*! @abstract 曝光回调
    @param view  曝光的元素
    @param type 曝光类型
    @param eventName  曝光事件名
    @param properties  曝光事件属性
    @result YES: 正常曝光    NO: 过滤本次曝光事件
 */
typedef BOOL (^BDAutoTrackExposureBlock)(id view, BDAutoTrackExposureTriggerType type, NSString *eventName, NSDictionary *properties);

@interface BDViewExposureConfig : NSObject


/*!
    @abstract 创建默认初始化的配置实例
 */
+ (instancetype)defaultConfig;


/*! @abstract 提供可视化的诊断，提供功能的校验
    @param enable 开启或者关闭可视化诊断，默认为 NO
    @discussion 开启后，会调整用户追踪视图的状态，当视图被设置Observale 会添加红色边框，当被检测满足曝光条件则会覆盖红色半透明浮层。生产模式下，请勿开启。
    @result 返回当前实例
 */
- (instancetype)enableVisualDiagnosis:(BOOL)enable;


/*! @abstract 设置触发曝光的最小进入屏幕视图面积占比
    @param radio  可以设置 0 - 1 的浮点数
    @discussion
        默认为 -1 将会采用全局的配置，
        0  表示 采用 1 pixel 进入屏幕触发曝光
        1 表示 100%后才会触发曝光
 
    @result 返回当前实例
 */
- (instancetype)areaRatio:(CGFloat)radio;


/*! @abstract 设置触发曝光的最小停留时长
    @param timestamp  最小停留时长，单位毫秒
    @discussion
        默认为 -1 将会采用全局的配置，
        0  表示 立即触发曝光
    @result 返回当前实例
 */
- (instancetype)stayTriggerTime:(NSInteger)timestamp;


/*! @abstract 设置曝光回调
    @param block  曝光回调
    @result 返回当前实例
 */
- (instancetype)exposureBlock:(nullable BDAutoTrackExposureBlock)block;

@end


@interface BDAutoTrackConfig (BDTViewExposure)

/*!
    @abstract 曝光采集的功能的全局开关
 */
@property (nonatomic) BOOL exposureEnabled;

/*!
    @abstract 曝光采集的功能的全局配置
 */
@property (nonatomic) BDViewExposureConfig *exposureConfig;

@end




@interface BDViewExposureData : NSObject

/*! @abstract 设置曝光埋点信息
 @param event 事件名称，如果不填会使用默认的曝光采集事件event
 @param properties 事件参数。可以为空或者nil，但是param如果非空，需要可序列化成json
 @param config 配置参数。可以配置视图级别的配置，默认为空会使用全局配置
 @discussion properties 请参考文档中的日志格式要求，或者使用 [NSJSONSerialization isValidJSONObject:] 来检查params是否可序列化
 @result 曝光埋点信息实例
 */
+ (instancetype)event:(nullable NSString *)event
           properties:(nullable NSDictionary *)properties
               config:(nullable BDViewExposureConfig *)config;

/*!
    @abstract event 事件名称，如果不填会使用默认的曝光采集事件event
 */
@property (nonatomic, copy, nullable) NSString *eventName;

/*!
    @abstract properties 事件参数。可以为空或者nil，但是param如果非空，需要可序列化成json
 */
@property (nonatomic, copy, nullable) NSDictionary  *properties;

/*!
    @abstract config 配置参数。可以配置视图级别的配置，默认为空会使用全局配置
 */
@property (nonatomic, strong, nullable) BDViewExposureConfig *config;

@end



@interface BDAutoTrack (BDTViewExposure)

/*!
 @abstract 设置视图开启自动曝光埋点采集
 @param view  视图实例， UIView 的子类
 @param data 曝光埋点信息数据
 @discussion 支持 reuseful view 进行重复设置，如果data中的event,properties 不一致，会被认为是一个新的事件
 */

- (void)observeViewExposure:(id)view
                   withData:(nullable BDViewExposureData *)data;

/*!
 @abstract 移除视图曝光埋点采集
 @param view  视图实例， UIView 的子类
 */
- (void)disposeViewExposure:(id)view;

@end





NS_ASSUME_NONNULL_END
